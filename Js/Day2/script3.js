let str = prompt("Please enter a string:");


function getMax(str) {
    let words = str.split(" ");
    let max = "";

    for(i = 0; i < words.length; i++) {
        if(words[i].length > max.length) {
            max = words[i];
        }
    }
    return max;
}

console.log(getMax(str));