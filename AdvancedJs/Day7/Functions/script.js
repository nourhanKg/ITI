function revA() {
    let myArr = Array.from(arguments);
    console.log(myArr.reverse());
}

function revB() {
    let myArr = Array.prototype.slice.call(arguments);
    console.log(myArr.reverse);
}

revA(1, 7, 3);
revB(1, 7, 3);