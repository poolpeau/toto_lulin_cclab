var answer = document.getElementById ("button");
var answer2 = document.getElementById("button1");
var frame = document.body;
var song = document.getElementById("water");


answer.onclick = function() {
frame.classList.toggle("pic");
song.play("water");

}