#include <pgmspace.h>
char style_css[] PROGMEM = R"=====(
    :root{
    --color: #1149e4;
    --first-color: #0c0c0e;

    --header-height: 3rem;
    --nav-width:100px;
    --normal-font-size: 1rem;
    --z-fixed: 100;
}

* {
    box-sizing: border-box;
    -moz-box-sizing: border-box;
}
body
{
    justify-content: center;
    align-items: center;
    margin: 0;
    padding: 0;
    display: flex;
    min-height: 100vh;
    background: #060607
}

.color_picker{
    position: relative;
    height: 20em;
    display: flex;
    flex-direction: column;
    justify-content:space-between;
    overflow: hidden;
    align-items: center;
    justify-items: center;
}

/* Img */
.image{
    z-index: -1;
    opacity: 0;
}
.image.show{
    opacity: 1;
    transition: 0.5s;
    animation: fail 2s linear;
}
@keyframes fail{
    0%{
        opacity: 0;
    }
    50%{
        opacity: 0;
    }
    60%{
        opacity: 0.6;
    }
    75%{
        opacity: 0.1;
    }
    90%{
        opacity: 1;
    }
    100%{
        opacity: 1;
    }
}
@keyframes fail2{
    0%{
        opacity: 0;
    }
    10%{
        opacity: 0;
    }
    12%{
        opacity: 0.6;
    }
    15%{
        opacity: 0.1;
    }
    18%{
        opacity: 1;
    }
    70%{
        opacity: 1;
    }
    72%{
        opacity: 0.6;
    }
    75%{
        opacity: 1;
    }
    78%{
        opacity: 0.2;
    }
    81%{
        opacity: 1;
    }
    95%{
        opacity: 1;
    }
    97%{
        opacity: 0;
    }
    99%{
        opacity: 0.8;
    }
    100%{
        opacity: 0;
    }
}
#lamp2{
    overflow: visible;
    filter: drop-shadow(0px 0px 10px var(--color)) ;
    animation: fail2 10s linear infinite;
}
svg{
    position: absolute;
    top: 25%;
    left: calc(12vw + (100vw - 300px) * 0.28);;
    height: 60%;
    z-index: -1;
    fill: var(--color);
    transition: 0.5s;
}


/* Slider */
.slider {
    position:relative;
    top: 1em;
    left:48%;
    transform:translate(-50%,-50%);
    width:13em;
    height:1em;
    padding:25px;
    padding-left: 40px;
    background:rgb(19, 20, 20);
    border-radius:10px;
    display:flex;
    align-items:center;
    box-shadow:0px 0px 45px -20px var(--color);
    transition: 0.5s;
}
.slider p {
    font-size:1.2em;
    text-transform: uppercase;    
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    letter-spacing: 0.2px;
    padding-left:10px;
    color:rgba(255,255,255,.7);
    z-index: 101;
}
.slider input[type='range'] {
    -webkit-appearance:none !important;
    margin-left: -20px;
    width: 10em;
    height:5px;
    background:var(--color);
    box-shadow: 0px 0px 10px var(--color);
    border-radius:10px;
    border:none;
    outline:none;
    transition:0.5s;
    z-index: 101;
}
.slider input[type='range']::-webkit-slider-thumb {
    -webkit-appearance:none !important;
    width:20px;
    height:20px;
    background:#fcfcfc;
    border:2px solid rgb(44, 46, 46);
    border-radius:50%;
    cursor:pointer;
}


/* scrollbar */
::-webkit-scrollbar{
    width: 0;
}
#progressbar::before{
    content: "";
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: linear-gradient(to top,#008aff,#00ffe7);
    z-index: 9999;
    filter:blur(10px);

}
#progressbar::after{
    content: "";
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 0%;
    background: linear-gradient(to top,#008aff,#00ffe7);
    z-index: 9999;
    filter:blur(20px);

}
#progressbar{
    position: fixed;
    top: 0;
    right: 0;
    width: 8px;
    height: 0%;
    border-radius:10px;
    background: linear-gradient(to top,#008aff,#00ffe7);
    z-index: 9999;
    animation: scroller 10s linear infinite;
}
@keyframes scroller{
    0%,100%{
        filter: hue-rotate(0deg);
    }
    50%{
        filter: hue-rotate(360deg)
    }
}

/* Navbar */
a{
    text-decoration: none;
}
#nav-bar.show{
    right: 0.1rem;
}
.r-navbar{
    position: fixed;
    top: 0;
    right: -256px;
    border-radius: 0.5rem;
    width: calc(var(--nav-width) + 156px);
    height: 100vh;
    background-color: var(--first-color);
    padding: .5rem 1rem 0 0;
    transition: 0.8s;
    z-index: var(--z-fixed);
}
.nav{
    height: 100%;
    width: 114%;
    display: flex;
    flex-direction: column;
    justify-content:space-between;
    overflow: auto;
    align-items: center;
    justify-items: center;
}
a.nav__button{
    position: relative;
    text-align: center;
    left: .5em;
    column-gap: 3rem;
    margin: 1rem;
    display: grid;
    width: 160px;
    height: 50px;
    line-height: 50px;
    text-transform: uppercase;    
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    letter-spacing: 3px;
}
a span.nav__name{
    position:absolute;
    display: block;
    top: 1px;
    left: 1px;
    right: 1px;
    bottom: 1px;
    text-align: center;
    background: #0c0c0c;
    color: rgba(255,255,255,.4);
    transition: 0.5s;
    z-index: 1;
}
a:hover span.nav__name, a.selected span.nav__name{
    color: rgba(255,255,255,1)
}
a span.nav__name::before{
    content: "";
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 50%;
    background: rgba(255,255,255,.1);
}
a.nav__button#color::after{
    content: "";
    position: absolute;
    top: 0;
    left: 0;
    width:100%;
    height: 100%;
    background: var(--color);
    background-size: 400%;
    opacity: 0;
    filter:blur(20px);
    transition: .5s;
    animation: animate 20s linear infinite;
}
a.nav__button#color::before{
    content: "";
    position: absolute;
    top: 0;
    left: 0;
    width:100%;
    height: 100%;
    background: var(--color);
    background-size: 400%;
    opacity: 0;
    transition: .5s;
    animation: animate 20s linear infinite;
}
a.nav__button#color:hover::before,a.nav__button#color:hover::after,a.selected#color::before,a.selected#color::after{
    opacity: 1;
}
a.nav__button#rainbow::after{
    content: "";
    position: absolute;
    top: 0;
    left: 0;
    width:100%;
    height: 100%;
    background: linear-gradient(45deg,#fb0094,#00f,#0f0,#ff0,#f00,#fb0094,#00f,#0f0,#ff0,#f00);
    background-size: 400%;
    opacity: 0;
    filter:blur(20px);
    transition: .5s;
    animation: animate 20s linear infinite;
}
a.nav__button#rainbow::before{
    content: "";
    position: absolute;
    top: 0;
    left: 0;
    width:100%;
    height: 100%;
    background: linear-gradient(45deg,#fb0094,#00f,#0f0,#ff0,#f00,#fb0094,#00f,#0f0,#ff0,#f00);
    background-size: 400%;
    opacity: 0;
    transition: .5s;
    animation: animate 20s linear infinite;
}
a.nav__button#rainbow:hover::before,a.nav__button#rainbow:hover::after,a.selected#rainbow::before,a.selected#rainbow::after{
    opacity: 1;
}
@keyframes animate
{
    0%
    {
        background-position: 0 0;
    }

    100%{
        background-position: 450% 0;
    }
}


/* Button */
a.button
{
    font-family: fantasy;
    font-weight: bold;
    position: relative;
    display: inline-block;
    padding: 0em 2em;
    color: var(--color);
    border-radius: 0.2em;
    text-transform: uppercase;
    letter-spacing: 0.1em;
    font-size: 40px;
    overflow: hidden;
    transition: 0.2;
}
.button-container{
    position: absolute;
    top: 43%;
    left: calc(20vw + (100vw - 300px) * 0.28);
    transition: 0.5s;
}
.button-container.on_finish {
    position: absolute;
    top: 1%;
    left: 1%;
    transition: 0.5s;
}
a.button.on_finish
{
    color: rgba(0, 0, 0, 0.507);
    background: var(--color);
    box-shadow: 0 0 5px var(--color),0 0 25px var(--color),0 0 50px var(--color),0 0 200px var(--color);
    font-size: 20px;
    transition-duration: 0.5s,0.5s,0.5s,0.1s,0.1s,0.1s;
    transition-delay: 0,0,0,0,0,0;
}
a.button.on
{
    transition-property: top,left,font-size,background-color,box-shadow,color;
    color: rgba(0, 0, 0, 0.507);
    background: var(--color);
    box-shadow: 0 0 5px var(--color),0 0 25px var(--color),0 0 50px var(--color),0 0 200px var(--color);
    transition-duration: 0.5s,0.5s,0.5s,0.1s,0.1s,0.1s;
    transition-delay: 0.6s,0.6s,0.6s,0.6s,0.6s,0.6s;

}
a.button span
{
    position: absolute;
    display: block;

}
a.button span:nth-child(1)
{
    top: 0;
    left: -100%;
    width: 100%;
    height: 3px;
    border-radius: 2px;
    background: linear-gradient(90deg,transparent,var(--color));
}
a.button.on span:nth-child(1)
{
    left: 100%;
    transition: 0.5s;
}
a span:nth-child(3)
{
    bottom: 0;
    right: -100%;
    width: 100%;
    height: 3px;
    border-radius: 2px;
    background: linear-gradient(270deg,transparent,var(--color));
}
a.button.on span:nth-child(3)
{
    right: 100%;
    transition: 0.5s;
    transition-delay: 0.25s;
}
a.button span:nth-child(2)
{
    top: -100%;
    right: 0;
    width: 3px;
    border-radius: 2px;
    height: 100%;
    background: linear-gradient(180deg,transparent,var(--color));
}
a.button.on span:nth-child(2)
{
    top: 100%;
    transition: 0.5s;
    transition-delay: 0.15s;
}
a span:nth-child(4)
{
    bottom: -100%;
    left: 0;
    width: 3px;
    border-radius: 2px;
    height: 100%;
    background: linear-gradient(360deg,transparent,var(--color));
}
a.button.on span:nth-child(4)
{
    bottom: 100%;
    transition: 0.5s;
    transition-delay: 0.35s;
}
a.button.off
{
    transition: 0.5s;
}

/* Color picker */

:root, [data-theme="default"]{
    --base-background-color: rgb(19, 20, 20);
    --thumb-border-color: rgba(255, 255, 255, 0.7);
    --color-wheel-control-box-shadow: 0px 0px 5px 0px rgba(0, 0, 0, 0.85) inset;
    --brightness-control-box-shadow: 0px 0px 5px 0px rgba(0, 0, 0, 0.5) inset;
    --input-controls-tab-header-background-color: rgba(41, 45, 53, 1.0);
    --input-controls-tab-header-font-color: rgba(255, 255, 255, 1.0);
    --input-controls-tab-background-color: rgba(0, 0, 0, 0.1);
    --range-input-control-background-color: rgba(35, 38, 43, 0.6);
    --range-input-control-background-color--focused: rgba(47, 51, 58, 0.6);
    --range-input-control-font-color: rgba(255, 255, 255, 1.0);
    --range-input-control-selection-color:rgba(0, 0, 0, 0.5);
    --range-input-control-progress-color:rgba(35, 38, 43, 0.6);
    --text-input-control-background-color: rgba(35, 38, 43, 0.6);
    --text-input-control-background-color--focused: rgba(55, 61, 71, 0.5);
    --text-input-control-font-color: rgba(255, 255, 255, 1.0);
    --text-input-control-selection-color:rgba(0, 0, 0, 0.5);
}

[data-theme="light"]{
    --base-background-color: rgba(217, 214, 205, 1.0);
    --thumb-border-color: rgba(255, 255, 255, 0.7);
    --color-wheel-control-box-shadow: 0px 0px 5px 0px rgba(0, 0, 0, 0.45) inset;
    --brightness-control-box-shadow: 0px 0px 5px 0px rgba(0, 0, 0, 0.25) inset;
    --input-controls-tab-header-background-color: rgba(221, 218, 210, 1.0);
    --input-controls-tab-header-font-color: rgba(35, 35, 35, 1.0);
    --input-controls-tab-background-color: rgba(122, 122, 122, 0.1);
    --range-input-control-background-color: rgba(221, 218, 210, 0.6);
    --range-input-control-background-color--focused: rgba(222, 220, 220, 0.5);
    --range-input-control-font-color: rgba(35, 35, 35, 1.0);
    --range-input-control-selection-color:rgba(255, 255, 255, 0.5);
    --range-input-control-progress-color:rgba(228, 228, 228, 1.0);
    --text-input-control-background-color: rgba(221, 218, 210, 0.6);
    --text-input-control-background-color--focused: rgba(222, 220, 220, 0.5);
    --text-input-control-font-color: rgb(17, 17, 17);
    --text-input-control-selection-color:rgba(255, 255, 255, 0.5);
}

.color-picker{
    position: absolute;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
    width: 180px;
    height: auto;
    min-height: 226px;
    background: var(--base-background-color);
    border-radius: 5px;
    -webkit-box-shadow: 0px 3px 1px -2px rgba(0, 0, 0, 0.2), 
                            0px 2px 2px 0px rgba(0, 0, 0, 0.14), 
                                0px 1px 5px 0px rgba(0,0,0,.12);
    -moz-box-shadow: 0px 3px 1px -2px rgba(0, 0, 0, 0.2), 
                        0px 2px 2px 0px rgba(0, 0, 0, 0.14), 
                            0px 1px 5px 0px rgba(0,0,0,.12);
    box-shadow: 0px 3px 1px -2px rgba(0, 0, 0, 0.2), 
                    0px 2px 2px 0px rgba(0, 0, 0, 0.14), 
                        0px 1px 5px 0px rgba(0,0,0,.12);
    z-index: 1000;
}
.color-picker-controls{
    position: relative;
    width: 100%;
    height: auto;
    display: flex;
    flex-direction: column;
}
.color-picker-controls-group{
    position: relative;
    display: block;
    width: 100%;
    padding: 10px;
}

.color-picker-wheel-control {
    position: relative;
    display: flex;
    flex-direction: row;
    height: 100%;
    width: 140px;
    border: none;
}
.color-picker-wheel-control::after {
    content: '';
    position: absolute;
    display: block;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    border: 1px solid var(--base-background-color);
    border-radius: 50%;
    -webkit-box-shadow: var(--color-wheel-control-box-shadow);
    -moz-box-shadow: var(--color-wheel-control-box-shadow);
    box-shadow: var(--color-wheel-control-box-shadow);
    margin: -1px;
    pointer-events: none;
}
.color-picker-brightness-control {
    position: relative;
    display: flex;
    flex-direction: row;
    height: 100%;
    width: 8px;
    border: 1px solid transparent;
    border-radius: 3px;
    margin-left: 10px;
}
.color-picker-brightness-control::after {
    content: '';
    position: absolute;
    display: block;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    border-radius: 3px;
    -webkit-box-shadow: var(--brightness-control-box-shadow);
    -moz-box-shadow: var(--brightness-control-box-shadow);
    box-shadow: var(--brightness-control-box-shadow);
    pointer-events: none;
}
.color-picker-wheel-control-thumb,
.color-picker-brightness-control-thumb {
    position: absolute;
    display: block;
    width: 10px;
    height: 10px;
    border: 1px solid var(--thumb-border-color);
    border-radius: 50%;
    -webkit-box-shadow: 0px 3px 1px -2px rgba(0, 0, 0, 0.2), 
                            0px 2px 2px 0px rgba(0, 0, 0, 0.14), 
                                0px 1px 5px 0px rgba(0, 0, 0, .12);
    -moz-box-shadow: 0px 3px 1px -2px rgba(0, 0, 0, 0.2), 
                        0px 2px 2px 0px rgba(0, 0, 0, 0.14), 
                            0px 1px 5px 0px rgba(0, 0, 0, .12);
    box-shadow: 0px 3px 1px -2px rgba(0, 0, 0, 0.2), 
                    0px 2px 2px 0px rgba(0, 0, 0, 0.14), 
                        0px 1px 5px 0px rgba(0, 0, 0, .12);
    cursor: pointer;
    z-index: 1000;
}
.wheel-canvas,
.brightness-canvas {
    width: 100%;
    height: 100%;
    border-radius: 3px;
}

.color-picker-input-controls{
    position: relative;
    width: 100%;
    height: 100%;
    display: flex;
    flex-direction: column;
    background: var(--input-controls-tab-background-color);
    border-radius: 3px;
    overflow: hidden;
}
.color-picker-input-controls-tab-headers{
    position: relative;
    display: flex;
    flex-direction: row;
    width: 100%;
    height: 25px;
    overflow: hidden;
}
.color-picker-input-controls-tab-headers button{
    position: relative;
    display: block;
    width: 33.33%;
    height: 100%;
    background: var(--input-controls-tab-header-background-color);
    font-size: 9px;
    color: var(--input-controls-tab-header-font-color);
    border: none;
    outline: none;
}
.color-picker-input-controls-tab-headers button.selected{
    background: none;
}
.color-picker-input-controls-tabs{
    position: relative;
    display: block;
    width: 100%;
    height: auto;
    padding: 4px;
}
.color-picker-input-controls-tab{
    position: relative;
    display: flex;
    flex-direction: column;
}
.color-picker-input-controls-tab:not(.selected){
    display: none;
}


input{
    font-size: 100%;
}
input::-webkit-outer-spin-button,
input::-webkit-inner-spin-button {
    -webkit-appearance: none;
    margin: 0;
}
input[type=number] {
    -moz-appearance: textfield;
}

.range-input-control{
    position: relative;
    display: block;
    width: 100%;
    height: auto;
    min-height: 20px;
    margin: 1px 0 0 0;
    background: var(--range-input-control-background-color);
    font-size: 10px;
    cursor: ew-resize;
    overflow: hidden;
}
.range-input-control:hover,
.range-input-control.range-input-control--focused{
    background: var(--range-input-control-background-color--focused);
}
.range-input-control:first-child{
    border-top-left-radius: 3px;
    border-top-right-radius: 3px;
}
.range-input-control:last-child{
    border-bottom-left-radius: 3px;
    border-bottom-right-radius: 3px;
}
.range-input-control .range-input-enter-block,
.range-input-control .range-input-details-block{
    position: absolute;
    display: block;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
}
.range-input-control:not(.range-input-control--key-input-mode) .range-input-enter-block{
    display: none;
}
.range-input-control.range-input-control--key-input-mode .range-input-enter-block{
    display: block;
}
.range-input-control:not(.range-input-control--key-input-mode) .range-input-details-block{
    display: block;
}
.range-input-control.range-input-control--key-input-mode .range-input-details-block{
    display: none;
}
.range-input-control input{
    position: absolute;
    display: block;
    top: 50%;
    transform: translate(0, -50%);
    width: 100%;
    height: auto;
    background: none;
    border: none;
    color: var(--range-input-control-font-color);
    text-align: center;
    outline: none;
}

.range-input-control input::-moz-selection { background: var(--range-input-control-selection-color); }
.range-input-control input::selection { background: var(--range-input-control-selection-color); }
.range-input-control .range-input-progress{
    position: absolute;
    display: block;
    top: 0;
    left: 0;
    height: 100%;
    background: var(--range-input-control-progress-color);
}
.range-input-control .range-input-label,
.range-input-control .range-input-value{
    position: absolute;
    display: block;
    top: 50%;
    width: auto;
    height: auto;
    transform: translate(0, -50%);
    color: var(--range-input-control-font-color);
    pointer-events: none;
}
.range-input-control .range-input-label{
    left: 5px;
}
.range-input-control .range-input-value{
    right: 5px;
}


.text-input-control{
    position: relative;
    display: block;
    width: 100%;
    height: auto;
    min-height: 20px;
    background: var(--text-input-control-background-color);
    font-size: 10px;
    margin: 1px 0 0 0;
    cursor: text;
    overflow: hidden;
}
.text-input-control:hover,
.text-input-control.text-input-control--focused{
    background: var(--text-input-control-background-color--focused);
}
.text-input-control:first-child{
    border-top-left-radius: 3px;
    border-top-right-radius: 3px;
}
.text-input-control:last-child{
    border-bottom-left-radius: 3px;
    border-bottom-right-radius: 3px;
}
.text-input-control .text-input-enter-block,
.text-input-control .text-input-details-block{
    position: absolute;
    display: block;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
}
.text-input-control:not(.text-input-control--focused) .text-input-enter-block{
    display: none;
}
.text-input-control.text-input-control--focused .text-input-enter-block{
    display: block;
}
.text-input-control:not(.text-input-control--focused) .text-input-details-block{
    display: block;
}
.text-input-control.text-input-control--focused .text-input-details-block{
    display: none;
}
.text-input-control input{
    position: absolute;
    display: block;
    top: 50%;
    transform: translate(0, -50%);
    width: 100%;
    height: auto;
    background: none;
    color: var(--text-input-control-font-color);
    text-align: center;
    border: none;
    outline: none;  
}
.text-input-control input::-moz-selection { background:var(--text-input-control-selection-color); }
.text-input-control input::selection { background:var(--text-input-control-selection-color); }
.text-input-control .text-input-label,
.text-input-control .text-input-value{
    position: absolute;
    display: block;
    top: 50%;
    width: auto;
    height: auto;
    transform: translate(0, -50%);
    color: var(--text-input-control-font-color);
    pointer-events: none;
}
.text-input-control .text-input-label{
    left: 5px;
}
.text-input-control .text-input-value{
    right: 5px;
}
)=====";