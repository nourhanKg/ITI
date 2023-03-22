function ListObj(start, end, step) {
    var list = [];
    var fillList = function() {
        var cur = start
        while(cur <= end) {
            list.push(cur);
            cur += step;
        }
    }
    var checkExist = function(value) {
        let exist = false;
        try {
            let i = 0;
            while(i < list.length) {
                if(list[i] !== value) {
                    exist = false;
                    i++;
                }
                else {
                    exist = true;
                    let err = new Error("Data already exists");
                    throw err;
                }
            }
        }
        catch(err) {
            console.error(err.message);
        }
        finally {
            return exist;
        }
    }
    this.start = start;
    this.end = end;
    this.step = step;
    this.Prepend = function(value) {
        if(!checkExist(value)) {
            try {
                if(list[0] < value || value + step !== list[0]) {
                    let err = new Error("Can't insert here");
                    throw err;
                }
                else {
                    list.unshift(value);
                }
            }
            catch(err) {
                console.error(err.message);
            }
        }
    }
    this.Append = function(value) {
        if(!checkExist(value)) {
            try {
                if(list[list.length - 1] > value || value - list[list.length - 1] !== step) {
                    let err = new Error("Can't insert here");
                    throw err;
                }
                else {
                    list.push(value);
                }
            }
            catch(err) {
                console.error(err.message);
            }
        }
    }
    this.Dequeue = function() {
        list.shift();
    }
    this.Pop = function() {
        list.pop();
    }
    this.display = function() {
        console.log(list);
    }
    ;(function(){
        fillList();
    }.bind(this))();

    Object.defineProperties(this, {
        start: {
            value: start,
            writable: false,
            configurable: false,
            enumerable: false
        },
        end: {
            value: end,
            writable: false,
            configurable: false,
            enumerable: false
        },
        step: {
            value: step,
            writable: false,
            configurable: false,
            enumerable: false
        }
    })
}
ListObj.prototype.toString = function() {
    this.display();
}
var myList = new ListObj(1, 9, 3);

myList.display();
myList.Prepend(4);
myList.Prepend(0);
myList.Prepend(-2);
myList.display();

myList.Append(11);
myList.Append(10);
myList.display();

// myList.Prepend(4);
// myList.Prepend(0);
// myList.display();

myList.toString();
