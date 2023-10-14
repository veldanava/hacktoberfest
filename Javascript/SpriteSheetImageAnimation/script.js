"use strict";

const playerImageFly = new Image();
playerImageFly.src = "./assets/PlayerSpritesheets/Fat_bird_fly_spritesheet.png";

const playerImageSize = 32;
const imageFlyWidth = 160;


let frameFlyX = 0;
let frameFlyY = 0;
let frameSpeed = 0;


const Game = () =>
{
  const canvas = document.querySelector("canvas");
  const ctx = canvas.getContext("2d");
  canvas.height = innerHeight;
  canvas.width = innerWidth;
  const screenHeight = canvas.height;
  const screenWidth = canvas.width;

  class Player
  {

    constructor()
    {
      this.x=25;this.y=235;this.w=40;this.h=40;
    }
    
    draw ()
    {
      ctx.drawImage(playerImageFly,frameFlyX*playerImageSize,frameFlyY*playerImageSize,playerImageSize,playerImageSize,(screenWidth/2)-150,(screenHeight/2)-150,this.w,this.h);
      ctx.strokeStyle = "#16FF00";
      ctx.strokeRect((screenWidth/2)-150,(screenHeight/2)-150,this.w,this.h);
    }

    update ()
    {
      if(frameSpeed>=3){
        frameFlyX = (frameFlyX + 1) % ( imageFlyWidth  / playerImageSize);
        frameSpeed = 0;
      }
    
      frameSpeed++;
    }

  }


  const player = new Player;


  ctx.clearRect(0,0,screenWidth,screenHeight);
  player.draw();
  player.update();
  
  requestAnimationFrame(Game);

}

window.addEventListener("load", function (){
  Game();
});
