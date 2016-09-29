window.alert("My name is George. Welcome!")


var answer = document.getElementById ("button");
var answerr = document.getElementById("button1");
var frame = document.body;
var song = document.getElementById("stressed");


answer.onclick = function() {
frame.classList.toggle("pic");

return false;

}



answerr.onclick = function() {
frame.classList.toggle("pic");

song.play("stressed");

}

