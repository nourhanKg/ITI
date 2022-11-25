let subBtn = document.getElementById("submit");


subBtn.addEventListener("click", 
function(e) {
    // e.preventDefault();
    let conf = confirm("Are you sure you want to submit?");
    if(!conf) {
        e.preventDefault();
    }
});

let timeout = new Event("timeout");

document.addEventListener("timeout",
function() {
    alert("Please Enter Data");
});


setInterval(function() {
    let pass = document.getElementById("password").value;
    let user = document.getElementById("username").value;
    if(!user && !pass) {
        document.dispatchEvent(timeout);
    }
}, 10000);