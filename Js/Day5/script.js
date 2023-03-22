// import * as cookiesFn from "./cookieLibrary.js";
document.getElementById("btn").onclick = saveData;
let userName, age, genderF, genderM, color ,chosenG;

function saveData() {
    userName = document.getElementById("username").value;
    age = document.getElementById("age").value;
    genderF = document.getElementById("female").checked;
    genderM = document.getElementById("male").checked;
    if(genderF) {
        chosenG = "female";
    }
    else {
        chosenG = "male";
    }
    color = document.getElementById("color").value;
    // console.log(genderF | genderM);
    storeData();
}

function storeData() {
    let date = new Date();
    // console.log(date);
    date.setMonth(date.getMonth() + 1);
    setCookie("username", userName, date);
    setCookie("age", age, date);
    setCookie("gender", chosenG, date);
    setCookie("color", color, date);
    setCookie("visits", 0, date);
}
console.log(allCookieList());

console.log(hasCookie("age"));
console.log(hasCookie("size"));