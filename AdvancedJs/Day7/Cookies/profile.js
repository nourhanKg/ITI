// import * as cookiesFn from "./cookieLibrary.js";

let userName, age, gender, color;

let welcomeMsg = document.getElementById("message");
let profilePic = document.getElementById("profile-pic");
let visits = parseInt(getCookie("visits"));

increaseVisits();
getData();


function displayWelcome() {
    console.log("Hi");
    console.log(welcomeMsg);
    welcomeMsg.innerHTML = "Welcome " + "<span style ='color:" + color +";'>"  + userName + "</span> you visited <span style='color:" + color +";'>"  + visits + "</span>";
}

function displayPP() {
    let ppSrc = gender == "female"? "./img/female.jpg": "./img/male.jpg";
    profilePic.src = ppSrc;
}
function increaseVisits() {
    let date = new Date();
    date.setMonth(date.getMonth() + 1);
    visits++;
    setCookie("visits", visits, date)
}

function getData() {
    console.log("Hello");
    userName = getCookie("username");
    age = getCookie("age");
    color = getCookie("color");
    gender = getCookie("gender");
    displayPP();
    displayWelcome();
    // console.log(userName, age, gender, color);
}
