let btn = document.getElementById("btn");
let chosenPic, msg;
btn.addEventListener("click", openPreview); 

function openPreview(event) {
    event.preventDefault();
    msg = document.getElementById("message").value;
    let pics = document.forms[0].elements.card;
    chosenPic;
    for(i = 0; i < pics.length; i++) {
        if(pics[i].checked)
            chosenPic = pics[i].value;
    }
    console.log(msg, chosenPic);

    let newWin = open("","","width=500,height=400");
    newWin.focus();
    let newWinBody = newWin.document.documentElement.lastChild;
    newWin.console.log(newWinBody);
    let newDiv = newWin.document.createElement("div");
    newDiv.setAttribute("style", "text-align: center;");
    newWinBody.appendChild(newDiv);
    // newDiv.innerHTML = "Hello";
    let img = newWin.document.createElement("img");
    newDiv.appendChild(img);
    img.setAttribute("style","width: 300px;");
    img.setAttribute("src", "http://127.0.0.1:5500/Card%20Maker/"+chosenPic+".jpg");
    newWin.console.log(img);
    let message = document.createElement("h2");
    message.innerHTML = msg;
    message.setAttribute("style","color: #C2E7EF;")
    newDiv.appendChild(message);

    let closeBtn = newWin.document.createElement("button");
    closeBtn.innerHTML = "Close Preview";
    closeBtn.setAttribute("style", "display: block;background-color:  #C2E7EF;color: white;padding: 5px 10px;border: none;margin-left: auto;margin-right: auto;");
    newDiv.appendChild(closeBtn);

    closeBtn.addEventListener("click", function() {
        newWin.close();
    })
}

function createPreview(newWin) {
    // let newWinBody = newWin.document.documentElement.lastChild;
    // console.log(newWinBody);
    // let newDiv = newWin.document.createElement("div");
    // newWinBody.appendChild(newDiv);
    // newDiv.setAttribute("style", "text-align: center;");
    // newDiv.innerHTML = "Hello";
    // let img = document.createElement("img");
    // img.setAttribute("style","width: 300px; height: 100px;")
    // img.setAttribute("src", "./" + chosenPic + ".jpg");
    // let message = document.createElement("h2");
    // message.innerHTML = msg;
    // img.setAttribute("style","color: #C2E7EF;")
    
    // newDiv.appendChild(img);
    // newDiv.appendChild(message);
}
