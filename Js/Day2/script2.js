let str = prompt("Please enter a string:");
const sensitivity = confirm("Do you want to consider case sensivitiy?");
let revStr = "";

if(!sensitivity) {
    str = str.toLowerCase();
}
for(i = str.length - 1; i >= 0; i--) {
    revStr += str[i];
}

str === revStr ? console.log("String is palindrome") : console.log("String isn't palindrome");