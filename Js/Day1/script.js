var userText = prompt("Enter your text");

for(var i = 1; i <= 6; i++) {
    //document.write(`<h${i}>${userText}</h${i}>`);
    document.write("<h" +  i + ">" + userText + "</h" + i + ">");
}

/*var num;
var flag = true;
var sum = 0;
do {
    num = prompt("Please enter a number");
    while(isNaN(num)) {
        num = prompt("Please enter a valid number");
    }
    if(parseInt(num) == 0) {
        flag = false;
    }
    else {
        sum += parseInt(num);
        console.log(sum);
        if(sum >= 100) {
        flag = false;
        }
    }
    console.log(flag);
}while(flag);

document.write("Your sum is " + sum);*/