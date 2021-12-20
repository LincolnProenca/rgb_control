/* Button and navbar*/
button = document.getElementById("on/off");
button.onclick = function() {on_off()};
function on_off(){
    var element = document.getElementById("button")
    switch(element.innerHTML){
        case "off":
            element.innerHTML = "on";
            button.classList.add('on');
            button.classList.remove('off');
            button.classList.add('turning');
            setTimeout(function() {
                document.getElementById("button-container").classList.add("on_finish")
                button.classList.add("on_finish");
                button.classList.remove('on');
                button.classList.remove('turning');
                document.getElementById("nav-bar").classList.add("show");
                document.getElementById("image").classList.add("show");
            }, 1200);
            break;
        case "on":
            if(button.classList.contains("turning")){
                break;
            }else{
                element.innerHTML = "off";
                console.log(button.id);
                button.classList.add('off');
                button.classList.remove('on_finish');
                document.getElementById("button-container").classList.remove('on_finish');
                document.getElementById("nav-bar").classList.remove('show');
                document.getElementById("image").classList.remove("show");
                
                break;
            }
        default:
            console.log("sexo");
    }
}

list = document.getElementsByClassName('nav__button');
document.getElementById('nav__list').onclick = function(e) {select(e)}
function select(e){
    if (e.path[1].classList.contains('nav__button')) {
        for (var i = 0; i <list.length; i++) {
            list[i].classList.remove('selected');
        }
        e.path[1].classList.add('selected');
    }
}

/* Progress bar */
let progress = document.getElementById("progressbar");
let nav = document.getElementById('nav');
let totalHeight = nav.scrollHeight - window.innerHeight;
nav.onscroll = function() {
    let progressHeight = (nav.scrollTop/totalHeight)*100;
    progress.style.height=progressHeight+'%';
}

