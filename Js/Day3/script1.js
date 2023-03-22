let myArr = [];


for(i = 0; i < 5; i++) {
    myArr[i] = parseInt(prompt("Enter number " + (i + 1)));
}

console.log(myArr);
console.log("Sorting Descending");
myArr.sort((a, b) => {
    if(a > b) {
        return -1;
    }
    if(a < b) {
        return 1;
    }
    return 0;
});
console.log(myArr);
console.log("Sorting Ascending");
myArr.sort((a, b) => {
    if(a > b) {
        return 1;
    }
    if(a < b) {
        return -1;
    }
    return 0;
});
console.log(myArr);