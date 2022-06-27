#include <Arduino.h>

#ifdef ARDUINO_ARCH_ESP32
  #include <WiFi.h>
  #include <WebServer.h>
  #define WEB_SERVER WebServer
  #define ESP_RESET ESP.restart()
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>
  #define WEB_SERVER ESP8266WebServer
  #define ESP_RESET ESP.reset()
#endif

#include <WS2812FX.h>

extern char index_html[];
extern const char main_js[];
extern const char style_css[];

#define WIFI_SSID "This is not a virus 2.4GHz"
#define WIFI_PASSWORD "13092002l"

//#define STATIC_IP                       // uncomment for static IP, set IP below
#ifdef STATIC_IP
  IPAddress ip(192,168,0,123);
  IPAddress gateway(192,168,0,1);
  IPAddress subnet(255,255,255,0);
#endif

// QUICKFIX...See https://github.com/esp8266/Arduino/issues/263
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#define LED_PIN 2                       // 0 = GPIO0, 2=GPIO2
#define LED_COUNT 120

#define WIFI_TIMEOUT 30000              // checks WiFi every ...ms. Reset after this time, if WiFi cannot reconnect.
#define HTTP_PORT 80

unsigned long auto_last_change = 0;
unsigned long last_wifi_check_time = 0;
String of = "off";
String speed = "100";
String color = "#1149e4";
String modes = "";
String id = "";
uint8_t myModes[] = {}; // *** optionally create a custom list of effect/mode numbers

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
WEB_SERVER server(HTTP_PORT);

//Declaring functions
void modes_setup();
void wifi_setup();
void srv_handle_index_html();
void srv_handle_icon();
void srv_handle_not_found();
void srv_handle_main_js();
void srv_handle_style_css();
void srv_handle_modes();
void srv_handle_stats();
void srv_handle_set();
void srv_handle_hset();

void setup(){
  Serial.begin(115200);
  delay(500);
  Serial.println("\n\nStarting...");

  modes.reserve(5000);
  modes_setup();

  Serial.println("WS2812FX setup");
  ws2812fx.init();
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(0x1149e4);
  ws2812fx.setSpeed(100);
  ws2812fx.setBrightness(0);
  ws2812fx.start();

  Serial.println("Wifi setup");
  wifi_setup();
 
  Serial.println("HTTP server setup");
  server.on("/", srv_handle_index_html);
  server.on("/main.js", srv_handle_main_js);
  server.on("/style.css", srv_handle_style_css);
  server.on("/stats", srv_handle_stats);
  server.on("/modes", srv_handle_modes);
  server.on("/set", srv_handle_set);
  server.on("/hset", srv_handle_hset);
  server.onNotFound(srv_handle_not_found);
  server.begin();
  Serial.println("HTTP server started.");

  Serial.println("ready!");
}


void loop() {
  unsigned long now = millis();

  server.handleClient();
  ws2812fx.service();

  if(now - last_wifi_check_time > WIFI_TIMEOUT) {
    Serial.print("Checking WiFi... ");
    if(WiFi.status() != WL_CONNECTED) {
      Serial.println("WiFi connection lost. Reconnecting...");
      wifi_setup();
    } else {
      Serial.println("OK");
    }
    last_wifi_check_time = now;
  }
}



/*
 * Connect to WiFi. If no connection is made within WIFI_TIMEOUT, ESP gets resettet.
 */
void wifi_setup() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  WiFi.mode(WIFI_STA);
  #ifdef STATIC_IP  
    WiFi.config(ip, gateway, subnet);
  #endif

  unsigned long connect_start = millis();
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    if(millis() - connect_start > WIFI_TIMEOUT) {
      Serial.println();
      Serial.print("Tried ");
      Serial.print(WIFI_TIMEOUT);
      Serial.print("ms. Resetting ESP now.");
      ESP_RESET;
    }
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}


/*
 * Build <li> string for all modes.
 */
void modes_setup() {
  modes = "";
  id = "color";
  uint8_t num_modes = sizeof(myModes) > 0 ? sizeof(myModes) : ws2812fx.getModeCount();
  for(uint8_t i=0; i < num_modes; i++) {
    uint8_t m = sizeof(myModes) > 0 ? myModes[i] : i;
    String nome = ws2812fx.getModeName(m);
    Serial.println(nome);
    if (nome.indexOf("Rainbow") != -1){
      id = "rainbow";
    }
    else{
      id = "color";
    }
    modes += "<a title='" + nome + "' href='javascript:;' class='nav__button "+nome+"'";
    modes +=  "id='" + id + "'><span class='nav__name'>";
    modes += nome;
    modes += "</span></a>";
  }
}

/* #####################################################
#  Webserver Functions
##################################################### */

void srv_handle_not_found() {
  server.send(404, "text/plain", "File Not Found");
}

void srv_handle_index_html() {
  server.send_P(200,"text/html", index_html);
}

void srv_handle_style_css() {
  server.send_P(200,"text/css", style_css);
}

void srv_handle_main_js() {
  server.send_P(200,"application/javascript", main_js);
}

void srv_handle_modes() {
  server.send(200,"text/plain", modes);
}

void srv_handle_stats(){
  String stats = of + " | " + speed + " | " + ws2812fx.getModeName(ws2812fx.getMode()) + " | " + color;
  server.send(200,"text/plain", stats);
}

void srv_handle_set() {
  for (uint8_t i=0; i < server.args(); i++){
    if(server.argName(i) == "c") {
      uint32_t tmp = (uint32_t) strtol(server.arg(i).c_str(), NULL, 16);
      if(tmp <= 0xFFFFFF) {
        ws2812fx.setColor(tmp);
        Serial.println(server.arg(i));
        Serial.println(tmp);
      }
      color = "#" + server.arg(i).substring(2);
      Serial.println(color);
    }

    if(server.argName(i) == "m") {
      uint8_t tmp = (uint8_t) strtol(server.arg(i).c_str(), NULL, 10);
      uint8_t new_mode = sizeof(myModes) > 0 ? myModes[tmp % sizeof(myModes)] : tmp % ws2812fx.getModeCount();
      ws2812fx.setMode(new_mode);
      Serial.print("mode is "); Serial.println(ws2812fx.getModeName(ws2812fx.getMode()));
    }

    if(server.argName(i) == "s") {
      if(server.arg(i)[0] == '-') {
        ws2812fx.setSpeed(max(ws2812fx.getSpeed(), 5) * 1.2);
      } else if(server.arg(i)[0] == ' ') {
        ws2812fx.setSpeed(ws2812fx.getSpeed() * 0.8);
      } else {
        uint16_t tmp = (uint16_t) strtol(server.arg(i).c_str(), NULL, 10)*10;
        ws2812fx.setSpeed(tmp);
        speed = server.arg(i);
        Serial.println(speed);
      }
      Serial.print("speed is "); Serial.println(ws2812fx.getSpeed());
    }

    if(server.argName(i) == "of") {
      of = server.arg(i);
      Serial.println(of);
      if (of == "on")
      {
        ws2812fx.setBrightness(128);
      }else{
        ws2812fx.setBrightness(0);
      }
    }
  }
  server.send(200, "text/plain", "OK");
}

void srv_handle_hset(){
  Serial.print(server.args());
}