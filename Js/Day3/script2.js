let rad = parseFloat(prompt("What's the circle radius?"));

console.log(rad);

let cArea = Math.PI * Math.pow(rad, 2);

alert("Circle area is " + cArea);

let num = parseFloat(prompt("What's the number?"));

console.log(num);

let sqr = Math.sqrt(num);

alert("Square root is " + sqr);

let angD = parseFloat(prompt("What's the angle in degree?"));

console.log(angD);

let angR = (angD * Math.PI) / 180;

console.log(angR);

let cosV = Math.cos(angR);

alert("Cos " + angD + "° is " + cosV.toFixed(4));