var monthList=[
    "January",
    "febuary",
    "march",
    "april",
    "may",
    "june",
    "july",
    "August",
    "september",
    "October",
    "November",
    "December"
]
let date = new Date();
document.getElementById("month").innerHTML = monthList[date.getMonth()];
document.getElementById("date").innerHTML = date.toDateString();
let lastDate = new Date(date.getFullYear(),date.getMonth()+1,0).getDate();
let firstDay = new Date(date.getFullYear(),date.getMonth(),1).getDay();
let daysData="";
for(let i=1;i<=firstDay;i++)
    daysData = daysData+'<p class="empty"></p>';
for(let i=1;i<=lastDate;i++){
    if(i===date.getDate()){
        daysData = daysData+"<p class = 'active'>"+i+"</p>";
    }else{
        daysData = daysData+"<p>"+i+"</p>";
    }
}
document.querySelector(".days").innerHTML=daysData;

