let ic1 = document.getElementById("ic1");
let ic2 = document.getElementById("ic2");
let ic3 = document.getElementById("ic3");

let ic1D = "right";
let ic2D = "left";
let ic3D = "top";

let startBtn = document.getElementById("start");
let resetBtn = document.getElementById("reset");


startBtn.addEventListener("click", moveHandler);
resetBtn.addEventListener("click", resetHandler);

let movingInterval;

function moveHandler(e) {
    if(e.target.innerText === "Start") {
        startMoving();
        e.target.innerText = "Stop";
    }
    else{
        stopMoving();
        e.target.innerText = "Start";
    }
}


function startMoving() {
    movingInterval = setInterval(
        function() {
            moveIcons();
        },30
    )
}

function stopMoving() {
    clearInterval(movingInterval);
}


function moveIcons() {
    moveIcon1();
    moveIcon2();
    moveIcon3();
}

function moveIcon1() {
    let leftP = parseInt(getComputedStyle(ic1).left);
    if(leftP === 350) {
        ic1D = "left"
    }
    if(leftP === 0) {
        ic1D = "right";
    }
    if(ic1D === "right") {
        ic1.style.left = (leftP + 5) + "px";
    }
    else {
        ic1.style.left = (leftP - 5) + "px";
    }
}

function moveIcon2() {
    let leftP = parseInt(getComputedStyle(ic2).left);
    if(leftP === 350) {
        ic2D = "left"
    }
    if(leftP === 0) {
        ic2D = "right";
    }
    if(ic2D === "right") {
        ic2.style.left = (leftP + 5) + "px";
    }
    else {
        ic2.style.left = (leftP - 5) + "px";
    }
}

function moveIcon3() {
    let topP = parseInt(getComputedStyle(ic3).top);
    if(topP === 350) {
        ic3D = "top"
    }
    if(topP === 0) {
        ic3D = "bottom";
    }
    if(ic3D === "bottom") {
        ic3.style.top = (topP + 5) + "px";
    }
    else {
        ic3.style.top = (topP - 5) + "px";
    }
}

function resetHandler() {
    ic1.style.left = "0";
    ic2.style.left = "350px";
    ic3.style.top = "350px";

    ic1D = "left";
    ic2D = "right";
    ic3D = "top";
    clearInterval(movingInterval)
}