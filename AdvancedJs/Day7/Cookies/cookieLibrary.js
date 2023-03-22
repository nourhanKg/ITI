function setCookie(cookieName, cookieValue, expDate) {
    try {
        if(arguments.length < 2 || arguments.length > 3) {
            throw new Error("Please enter correct cookies");
        }
        if(arguments[2]) {
            if(isNaN(Date.parse(expDate))) {
                throw new Error("Enter valid date");
            }
            document.cookie = cookieName + "=" + cookieValue + "; expires=" + expDate;
        }
    }
    catch(err) {
        console.log(err.message);
    }
}

function getCookie(cookieName) {
    try {
        if(arguments.length !== 1) {
            throw new Error("Enter valid cookie name");
        }
        let cookies = document.cookie.split(";");
        let cookiesValues =[];

        for(let i=0; i<cookies.length; i++) {
            cookies[i] = cookies[i].split("=");
            cookiesValues[cookies[i][0].trim()] = cookies[i][1];
        }
        if(!cookiesValues[cookieName]) {
            throw new Error("Enter valid cookie name");
        }
        return cookiesValues[cookieName];
    }
    catch(err) {
        console.log(err.message);
    }
}

function deleteCookie(cookieName) {
    try{
        if(arguments.length !== 1 || !hasCookie(cookieName)) {
            throw new Error("Enter valid cookie name");
        }
        document.cookie = cookieName + "=; expires=" + new Date();
    }
    catch(err) {
        console.log(err.message);
    }
}

function allCookieList() {
    let cookies = document.cookie.split(";");
    let cookiesValues =[];

    for(let i=0; i<cookies.length; i++) {
        cookies[i] = cookies[i].split("=");
        cookiesValues[cookies[i][0].trim()] = cookies[i][1];
    }
    return cookiesValues;
}

function hasCookie(cookieName) {
    return getCookie(cookieName)? true : false;
}