console.log(msg, chosenPic);
let newWinBody = document.documentElement.lastChild;
console.log(newWinBody);
let newDiv = document.createElement("div");
newDiv.setAttribute("style", "text-align: center;");
newDiv.innerHTML = "Hello";
let img = document.createElement("img");
img.setAttribute("style","width: 300px;")
img.setAttribute("src", "./" + chosenPic + ".jpg");
let message = document.createElement("h2");
message.innerHTML = msg;
img.setAttribute("style","color: #C2E7EF;")
newWinBody.appendChild(newDiv);
newDiv.appendChild(img);
newDiv.appendChild(message);