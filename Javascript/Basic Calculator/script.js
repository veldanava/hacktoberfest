let btns = document.querySelectorAll(".btn");
let input = document.getElementById("input");
let string='';
for(let x of btns){
    x.addEventListener('click',function(){
        if(x.innerHTML =='='){
            string = eval(string);
            input.value = string;
            prev = "0";
        }else if(x.innerHTML == 'AC'){
            string ='';
            input.value = '0';
        }else{
            string = string + x.innerHTML;
            input.value = string;
        }
        console.log(string.search("."));
        
})
}