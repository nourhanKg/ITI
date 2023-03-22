var custObj = {
    id: "SD-123",
    location: "ITI-Smart",
    address: "123 st.",
    getSetGen: function() {
        var props = Object.entries(this);
        for(i = 0; i < props.length; i++) {
            if(!(typeof props[i][1] === "function")) {
                this["get" + props[i][0].charAt(0).toUpperCase() + props[i][0].slice(1)] = (function(props, i) {
                    return function() {
                        return this[props[i][0]];
                    }
                })(props, i);
                this["set" + props[i][0].charAt(0).toUpperCase() + props[i][0].slice(1)] = (function(props, i) {
                    return function(val) {
                        this[props[i][0]] = val;
                    }
                })(props, i);
            }
        }
    }
}
var user = {name: "Nour", age: 25}
custObj.getSetGen();
custObj.getSetGen.call(user);
console.log(user);
console.log(user.getName());
console.log(user.getAge());
user.setAge(11);
console.log(user.age);
