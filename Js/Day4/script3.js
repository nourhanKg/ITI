let numI = document.images.length;
let curImg = 0;

let animationTimer = setInterval;
startAnimation();

function animation() {
    for(i = 0; i < numI; i++) {
        if(i === curImg) {
            document.images[i].src = "./img/marble2.jpg";
        }
        else {
            document.images[i].src = "./img/marble1.jpg";
        }
    }
    curImg++;
    if (curImg === numI) {
        curImg = 0;
    }
}

function startAnimation() {
    animationTimer = setInterval(
        animation, 1000
    );
}

function stopAnimation() {
    console.log("stop");
    clearInterval(animationTimer);
}