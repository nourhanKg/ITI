function Box(width, height, length, material) {
    this.content = [];
    this.width = width;
    this.height = height;
    this.length = length;
    this.material = material;
    Object.defineProperties(this, {
        width: {
            value: width,
            writable: false,
            configurable: false,
            enumerable: false
        },
        height: {
            value: height,
            writable: false,
            configurable: false,
            enumerable: false
        },
        length: {
            value: length,
            writable: false,
            configurable: false,
            enumerable: false
        },
        material: {
            value: material,
            writable: false,
            configurable: false,
            enumerable: false
        }
    });
}

function Book(title, author, publisher, numCopies, numChapters, numPages) {
    Book.booksCount++;
    this.title = title;
    this.author = author,
    this.publisher = publisher,
    this.numCopies = numCopies,
    this.numChapters = numChapters,
    this.numPages = numPages

    Object.defineProperties(this, {
        title: {
            value: title,
            writable: false,
            configurable: false,
            enumerable: false
        },
        author: {
            value: author,
            writable: false,
            configurable: false,
            enumerable: false
        },
        publisher: {
            value: publisher,
            writable: false,
            configurable: false,
            enumerable: false
        },
        numChapters: {
            value: numChapters,
            writable: false,
            configurable: false,
            enumerable: false
        },
        numCopies: {
            value: numCopies,
            writable: true,
            configurable: true,
            enumerable: false
        },
        numPages: {
            value: numPages,
            writable: false,
            configurable: false,
            enumerable: false
        },
    })
}
Box.prototype.addBook = function(book) {
    this.content.push(book);
} 
Box.prototype.countBooks = function() {
    var list = this.content;
    var count = 0;
    for(i = 0; i < list.length; i++) {
        count += list[i].numCopies;
    }
    return count;
}

Box.prototype.deleteBook = function(title) {
    try {
        var list = this.content;
        var found = false;
        var i = 0;
        while(!found && i < list.length) {
            if(list[i].title === title) {
                found = true;
                if(list[i].numCopies === 1) {
                    list.splice(i, 1);
                }
                else {
                    console.log(list[i].numCopies);
                    list[i].numCopies = list[i].numCopies - 1;
                    console.log(list[i].numCopies);
                }
            }
            else {
                i++;
            }
        }
        if(!found) 
            throw Error("There is no book with this title");
    }
    catch(err) {
        console.error(err.message)
    }
}
Box.prototype.toString = function() {
    return "Dimensions are, width: " + this.width + ", height: " + this.height + ", length: " + this.length + ". And num of books is " + this.countBooks();
}
Box.prototype.valueOf = function() {
    return this.content.length;
}

//BooK Method
Object.defineProperty(Book, "booksCount",
    {   value: 0,
        configurable: false,
        writable: true,
        enumerable: false
    }
)
Object.defineProperty(Book, "getCount",
    {   value: function() {
            return Book.booksCount;
    },
        configurable: false,
        writable: true,
        enumerable: false
    }
)


var box1 = new Box(10, 20, 30, "Cardboard");
var box2 = new Box(20, 40, 60, "Wood");

var book1 = new Book("LOTR", "Tolkein", "UK-Publish", 100, 30, 1000);
var book2 = new Book("Harry Potter", "J.K.Rowling", "UK-Publish", 10, 20, 700);
var book3 = new Book("ASOIAF", "George Martin", "US-Publish", 50, 20, 2000);
var book4 = new Book("Supernatural", "Ahmed Khalid Tawfiq", "EG-Publish", 5, 7, 200);
var book5 = new Book("Inferno", "Dan Brown", "US-Publish", 1, 12, 450);
box1.addBook(book1);
box1.addBook(book2);
box2.addBook(book4);
box2.addBook(book5);
console.log(box1, box2);
console.log(box1.countBooks(), box2.countBooks());

box2.deleteBook("Inferno");
box2.deleteBook("Supernatural");
box1.deleteBook("Angels & Demons");
console.log(box1, box2);

// console.log(box1.toString());
// console.log(box2.toString());

console.log(Book.getCount());

// console.log(box1.valueOf() + box2.valueOf());