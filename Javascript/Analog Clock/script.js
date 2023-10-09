setInterval(() => {
    date = new Date();
    thrs = date.getHours();
    tmin = date.getMinutes();
    tsec = date.getSeconds();
    document.getElementById("hours").style.transform = `rotate(${30 * thrs + tmin / 2 + tsec / 120}deg)`;
    document.getElementById("minutes").style.transform = `rotate(${6 * tmin + tsec / 10}deg)`;
    document.getElementById("seconds").style.transform = `rotate(${6 * tsec}deg)`;
}, 1000);


/*
12 hrs = 360 deg
1 hrs = 360/12 = 30deg
1hrs = 60min = 30 deg ; So, 1min = 30/60 = 1/2;
60min = 360 deg; 1min = 6deg; 1min = 60sec = 6deg; 1sec = 6/60  = 1/10deg;
60sec = 360 deg; 1sec = 6deg;

hrs = 6*hrs+1/2*min;
min = 6*min + 1/10*sec;
sec = 6*sec;


*/