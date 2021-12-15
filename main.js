button = document.getElementById("on/off");
button.onclick = function() {on_off()};

bodyStyles = document.body.style;
bodyStyles.setProperty('--color','#2196f3')

function on_off(){
    var element = document.getElementById("button")
    switch(element.innerHTML){
        case "off":
            element.innerHTML = "on";
            button.classList.add('on');
            button.classList.remove('off');
            setTimeout(function() {
                button.classList.add("on_finish");
                button.classList.remove('on');
                document.getElementById("nav-bar").classList.add("on_finish");
            }, 1200);
            break;
        case "on":
            element.innerHTML = "off";
            console.log(button.id);
            button.classList.add('off');
            button.classList.remove('on_finish');
            document.getElementById("nav-bar").classList.remove('on_finish');
            break;
        default:
            console.log("sexo");
    }
}
