function twoP() {
    try {
        if(arguments.length !==2) {
            throw new Error("Enter two parameters");
        }
    }
    catch(err) {
        console.log(err.message);
    }
}

twoP(3, 1);