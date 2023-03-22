console.log("start");
let strQ = location.search.substring(1);
console.log(strQ);

let info = strQ.split("&");
let values=[];
for(i=0; i<info.length; i++) {
    info[i] = info[i].split("=");
    values[info[i][0]] = info[i][1];
}
console.log(info);
console.log(values);


document.getElementById("welcome").innerHTML = "Welcome " + values["title"] + " " + values["username"] +" !";

document.getElementById("info").innerHTML = "Address is:  " + values["address"].split("+").join(" ") + ", Gender is: " + values["gender"] + ", Telephone is: " + values["telephone"];