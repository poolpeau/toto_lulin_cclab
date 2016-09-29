
var greetings = "ALONE TOGETHER- BAMBOUNOU/ ISABELLA/ TNKWAI/WALL PEELER";

alert(greetings);

var answer = document.getElementById ("button");
var answerr = document.getElementById("button1");
var frame = document.body;
var song = document.getElementById("water");


answer.onclick = function() {
frame.classList.toggle("pic");
song.play("water");

}

answerr.onclick = function() {
frame.classList.toggle("pic");

song.play("stressed");

}
