const LnkdLst = {
    data: [{val:1}, {val:2},{val:4}],
    getAll: function() {
        return Object.values(this.data);
    },
    checkExist: function(value) {
        let exist = false;
        try {
            let dataValues = this.getAll();
            let i = 0;
            while(i < dataValues.length) {
                if(dataValues[i].val !== value) {
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
            console.log(err.message);
        }
        finally {
            return exist;
        }
    },
    pushVal: function(value) {
        let dataValues = this.getAll();
        if(!this.checkExist(value)) {
            try {
                if(dataValues[dataValues.length - 1].val > value) {
                    let err = new Error("Can't insert here");
                    throw err;
                }
                else {
                    let newVal = {val: value,};
                    this.data.push(newVal);
                }
            }
            catch(err) {
                console.log(err.message);
            }
        }
    },
    enqueue: function(value) {
        if(!this.checkExist(value)) {
            try {
                if(this.data[0].val < value) {
                    let err = new Error("Can't insert here");
                    throw err;
                }
                else {
                    let newVal = {val: value,};
                    this.data.unshift(newVal);
                }
            }
            catch(err) {
                console.log(err.message);
            }
        }
    },
    insert: function(index, value) {
        if(!this.checkExist(value)) {
            try{
                if(this.data[index - 1.].val < value < this.data[index].val) {
                    let newVal = {val: value,};
                    this.data.splice(index, 0, newVal);
                }
                else {
                    let err = new Error("Can't insert here");
                    throw err;
                }
            }
            catch(err) {
                console.log(err);
            }
        }
    },
    popVal: function() {
        this.data.pop();
    },
    dequeue: function() {
        this.data.shift();
    },
    removeVal(value) {
        try{
            if(arguments.length !== 1) {
                let err = new Error("Data not found");
                throw err;
            }
            let i = 0;
            while(this.data[i].val !== value) {
                i++;
            }
            this.data.splice(i);
        }
        catch(err) {
            console.log(err.message);
        }
    },
    display: function() {
        let dataValues = this.getAll();
        for(i = 0; i < dataValues.length; i++) {
            console.log(dataValues[i].val);
        }
    }
}
// LnkdLst.display();
// LnkdLst.pushVal(3);
// LnkdLst.pushVal(5);
// LnkdLst.display();
// LnkdLst.enqueue(7);
// LnkdLst.enqueue(0);
// LnkdLst.display();


// LnkdLst.display();
// LnkdLst.insert(1, 3);
// LnkdLst.display();
// LnkdLst.removeVal(4);
// LnkdLst.display();

// LnkdLst.checkExist(4);
// LnkdLst.checkExist(6);
// console.log(LnkdLst.checkExist(4));
// console.log(LnkdLst.checkExist(6));