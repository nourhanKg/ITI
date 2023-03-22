let myInterval = setInterval;
function openNewWin() {
    console.log("Hello");
    let newWin = open("", "", "top=0,left=0,width=400,height=200");
    newWin.focus();
    myInterval = setInterval(
        function() {
            let screenHeight = window.screen.height;
            let screenWidth = window.screen.width;
            // console.log(screenHeight, screenWidth);
            // console.log(newWin.screenY + 200, newWin.screenX + 400);

            
            if(screenHeight - newWin.screenY - 200 < 150 || screenWidth - newWin - 400 < 150) {
                console.log("hitwall");
                newWin.moveBy(-150, -150);
            }
            // if( newWin.screenY == 0 || newWin.screenX == 0)
            // {
            // newWin.moveBy(150, 150);
            // }
            else {
            newWin.moveBy(150, 150);
            }
        }
        ,1000
    )
}

function stopNewWin() {
    clearInterval(myInterval);
    console.log("Stopped");
}