function getSuggestions(str) {
    if (str.length == 0) {
        document.getElementById("suggestions").innerHTML = "Suggestions: no suggestion";
        return;
    }

    let xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            showSuggestions(this);
        }
    };
    xmlhttp.open("GET", "get_suggestions.php?q=" + str, true);
    xmlhttp.send();
}

function showSuggestions(xml) {
    let suggestions = xml.responseXML.getElementsByTagName("name");
    let input = document.getElementById("nameInput").value.toLowerCase();
    let html = "Suggestions: ";

    for (let i = 0; i < suggestions.length; i++) {
        let name = suggestions[i].childNodes[0].nodeValue;
        if (name.toLowerCase().startsWith(input)) {
            html += name + ", ";
        }
    }

    if (html === "Suggestions: ") {
        html += "no suggestion";
    } else {
        html = html.slice(0, -2); // Remove the trailing comma and space
    }

    document.getElementById("suggestions").innerHTML = html;
}
