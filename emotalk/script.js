const text = document.querySelector("#textmsg")
const password = document.querySelector('#password')
const result = document.querySelector("#result")
var clutter = "";
var parinam = "";

function encryption() {

    document.querySelector("#encrypt-btn").addEventListener("click", function () {


        // getting the password

        var pass = document.getElementById("password").value;
        console.log(pass)


        // getting the input

        var input = document.getElementById("textmsg").value;
        console.log(input)

        //converting it into a set of emojis
        // to split the word in input in an individual letter array

//https://www.alt-codes.net/smiley_alt_codes.php   (used for the ascii values)     
        var str = input.split("")
        str.forEach(element => {
            clutter += `&#128${(element.charCodeAt())} `
            // console.log((element.charCodeAt()) * Math.floor(Math.random() * 10))
        });
        //saving emojis in localstorage

        // localStorage.setItem("emojis", clutter)

// Set the inner HTML of an element with the ID "result" to the value of "clutter"
        document.querySelector("#result").innerHTML = clutter

        var dataarr = [];
        if(JSON.parse(localStorage.getItem('data1'))){
        // If data exists, parse and assign it to the "dataarr" array   
            dataarr = JSON.parse(localStorage.getItem('data1'));
            console.log(dataarr)
             // Push a new object containing "pass," "input," and "clutter" into the array
            dataarr.push({"pass":pass, "input":input, "clutter":clutter})
        }else{
        // If no data exists, create an array containing a new object
            dataarr = [{"pass":pass,"input":input,"clutter":clutter}]
        }
        // Store the updated array in local storage
        localStorage.setItem(`data1`, JSON.stringify(dataarr))
    })

}

function decryption() {
    document.querySelector("#decrypt-btn").addEventListener("click", function () {
        var clutter2 = '';

    //getting an given emoji message
        var input2 = document.querySelector("#emojimsg").value
    //getting an given final password
        var finalPass = document.querySelector("#finalpassword").value


        var user = JSON.parse(localStorage.getItem('data1'))
        console.log(user)
        var str2 = input2.split(" ")
        str2.forEach(element => {

//https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/codePointAt
                clutter2 += `&#${(element.codePointAt(0))} `
                // console.log((element.charCodeAt()) * Math.floor(Math.random() * 10))
        });

//loop to check whether the input emojis for the decryption is same as we are getting in the encryption        
        console.log(clutter2)
        var found;
        for(let i of user){
            if(i.clutter == clutter2){
                found = i;
                console.log(i)
            }
        }
        if (found.clutter === clutter2) {
            console.log("Nikla Jaa Yaha se")
            document.querySelector("#result").style.display = `block`
            document.querySelector("#result").style.color = `#eee`

            document.querySelector("#result").innerHTML = found.input
        } else {
            document.querySelector("#result").style.display = `block`
            document.querySelector("#result").style.color = `red`
            document.querySelector("#result").innerHTML = "Wrong password!"
        }
    })

}


function btnClicking() {

    document.querySelector("button").addEventListener("click", function () {
        document.querySelector("#result").style.display = "block"
        // console.log(localStorage.getItem("password"))
        // console.log(localStorage.getItem("emojis"))
    })
    document.querySelector("#dec-btn").addEventListener("click", function () {
        document.querySelector("#result").style.display = "none"
        document.querySelector("#decryption").style.display = "block"
        document.querySelector("#encryption").style.display = "none"
        document.querySelector("#dec-btn").style.backgroundColor = "#333"
        document.querySelector("#enc-btn").style.backgroundColor = "#222"
        document.querySelector("#main>h1 span img").style.rotate = '270deg'
    })
    document.querySelector("#enc-btn").addEventListener("click", function () {
        document.querySelector("#decryption").style.display = "none"
        document.querySelector("#result").style.display = "none"
        document.querySelector("#encryption").style.display = "block"
        document.querySelector("#dec-btn").style.backgroundColor = "#222"
        document.querySelector("#enc-btn").style.backgroundColor = "#333"
        document.querySelector("#main>h1 span img").style.rotate = '90deg'

    })
}

encryption();

decryption()

btnClicking();



// I am competitive and I feel bad when we lose. You can see it in me when we've lost. I'm in a bad way. I don't like to talk to anyone.