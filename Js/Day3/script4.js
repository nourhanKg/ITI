let message = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

let i = 0;

function openNewWin() {
    let newWin = open("", "", "width=400,height=200");
    newWin.focus();

    setTimeout(
        function() {
            newWin.close();
        },4000
    );

    startTyping(newWin);
}
function startTyping(newWin) {
    setInterval(
        function() {
            newWin.document.write(message[i]);
            i++;
        },300
    )
}