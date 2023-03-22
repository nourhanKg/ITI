let imgNum = document.images.length;
let cur;
let prev;
let clicks = 0;

function setAll() {
    for(i=0; i<imgNum; i++) {
        document.images[i].src = "./img/Moon.gif";
    }
} 
setAll();


function reveal(img) {
    clicks++;
    // console.log(clicks);
    if(clicks <= 2) {

        img.src = "./img/" + img.alt + ".gif";
    } 
    if(clicks == 1) {
        prev = img;
        console.log(prev);
    }
    if(clicks == 2) {
        cur = img;
        console.log(cur);
        evaluation(prev, cur);
    }
}

function evaluation(first, sec) {
    if(first.alt === sec.alt) {
        clicks = 0;
    }
    else {
        setTimeout(
            function() {
                first.src = "./img/Moon.gif";
                sec.src = "./img/Moon.gif";
            }, 500
        );
        clicks = 0;
    }
}