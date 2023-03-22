let flag = false;
let x ="75012242";
let y ="0115656"
let z ="0105656"
let mobExp = /^011|^012|^010/;
let emailExp = /^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$/;
// console.log(mobExp.test(x));
// console.log(mobExp.test(y));
// console.log(mobExp.test(z));

do {
    var userName = prompt("Please enter your name:");
    var phone = prompt("Please enter your phone 8 digits:");
    var mobile = prompt("Please enter your mobile:");
    var email = prompt("Please enter your email:");
    var myColor = prompt("Choose Color (red, blue, green)");
    console.log(!isNaN(userName));
    console.log(isNaN(phone));
    console.log(phone.length);
    if(!isNaN(userName)) {
        alert("Not valid name");
        flag = true;
    }
    if(isNaN(phone) || phone.length !== 8) {
        alert("Not valid phone");
        flag = true;
    }
    if(!mobExp.test(mobile) || mobile.length !== 11) {
        alert("Not valid mobile");
        flag = true;
    }
    if(!emailExp.test(email)) {
        alert("Not valid Email");
        flag = true;
    }
}
while(flag);

console.log("%c Welcome " + userName, `color: ${myColor}`);
console.log("%c Telephone is " + phone, `color: ${myColor}`);
console.log("%c Mobile is " + mobile, `color: ${myColor}`);
console.log("%c Email is " + email, `color: ${myColor}`);