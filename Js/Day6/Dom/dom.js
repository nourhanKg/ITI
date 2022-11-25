let divHeader = document.documentElement.lastChild.firstElementChild.firstElementChild;

setTimeout(
    changeDom, 2000
);

function changeDom() {
    divHeader.setAttribute("style","text-align:right;");
    let divFooter = divHeader.cloneNode(true);
    divFooter.setAttribute("style","text-align:left;");
    divFooter.setAttribute("id", "footer");
    divHeader.parentNode.appendChild(divFooter);
}


