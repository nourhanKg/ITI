let str = prompt("Please enter a string:");
let ch = prompt("please enter character");
const sensitivity = confirm("Do you want to consider case sensivitiy?");

let occ = 0;

if(sensitivity) {
    for(i = 0; i < str.length; i++) {
        if(str.charAt(i) === ch) {
            occ++;
        }
    }
}
else {
    for(i = 0; i < str.length; i++) {
        if(
            str.charAt(i) === ch.toUpperCase() || 
            str.charAt(i) === ch.toLowerCase()
            ) 
        {
            occ++;
        }
    }
}
console.log("Ocuurance of " + ch + " is " + occ);