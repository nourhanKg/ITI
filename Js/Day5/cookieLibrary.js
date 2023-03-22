function setCookie(cookieName, cookieValue, expDate) {
    document.cookie = cookieName + "=" + cookieValue + "; expires=" + expDate;
}

function getCookie(cookieName) {
    let cookies = document.cookie.split(";");
    let cookiesValues =[];

    for(let i=0; i<cookies.length; i++) {
        cookies[i] = cookies[i].split("=");
        cookiesValues[cookies[i][0].trim()] = cookies[i][1];
    }
    return cookiesValues[cookieName];
}

function deleteCookie(cookieName) {
    document.cookie = cookieName + "=; expires=" + new Date();
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