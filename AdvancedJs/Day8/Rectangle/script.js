var Rectangle = function(width, height) {
    this.width = width || 0;
    this.height = height || 0;
    this.calcArea = function() {
        return width * height;
    }
    this.calcPerimeter = function() {
        return (width + height) * 2;
    }
    this.displayInfo = function() {
        console.log("Rectangle info is, width: " + this.width + ", height: " + this.height + ", area: ", this.calcArea() + ", perimeter: " + this.calcPerimeter() + ".");
    }
}




var rec1 = new Rectangle();
var rec2 = new Rectangle(30, 40);

console.log(rec1.width);
console.log(rec2.width);

rec2.displayInfo();