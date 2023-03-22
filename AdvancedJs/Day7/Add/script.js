function add() {
    try {
        if(arguments.length === 0) {
            throw new Error("Enter a number");
        }
        for(i = 0; i < arguments.length; i++) {
            if(typeof arguments[i] !== "number") {
                throw new Error("Enter a number");
            }
        }
        let sum = 0;
        for(i = 0; i < arguments.length; i++) {
            sum += arguments[i];
        }
        return sum;
    }
    catch(err) {
        console.log(err.message);
    }
}

console.log(add(1,3));