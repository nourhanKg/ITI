let imgNum = 4;
let cur = 1;
let img = document.getElementById("myImg");
let slideTime = setInterval;

function slideShow() {
    slideTime = setInterval(
        function() {
            img.src = "./img/group" +cur+ ".jpg";
            cur++;
            if(cur > imgNum) {
                cur = 1;
            }
        },2000
    );
}

function stopSlide() {
    clearInterval(slideTime);
}

function nextSelect() {
    console.log("3");
    if(cur != imgNum) {
        cur++;
        img.src = "./img/group" +cur+ ".jpg";
    }
}

function prevSelect() {
    console.log("4");
    if(cur != 1) {
        cur--;
        img.src = "./img/group" +cur+ ".jpg";
    }
}