// JS Date and Time

function mydate(){
    var date = new Date();
    document.getElementById("date").innerHTML = date.toDateString();
}

function mytime(){
    var time = new Date();
    document.getElementById("time").innerHTML = time.toLocaleTimeString('en-GB',{ hour12: false });
}

// Digital Clock
function interval(){
    var d = new Date();
    document.getElementById("hh").value = d.getHours();
    document.getElementById("mm").value = d.getMinutes();
    document.getElementById("ss").value  = d.getSeconds();
    document.getElementById("ms").value = d.getMilliseconds();
}

setInterval("interval()", 1);


//Countdown
var count = 10;

function countdown(){
    document.getElementById("count").innerHTML = count;
    count--;
    if(count < 0){
        clearInterval(intervalId);
        alert("Time's Up!");
    }
}

var intervalId = setInterval(countdown, 1000);
