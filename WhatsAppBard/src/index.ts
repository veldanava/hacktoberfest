import { Client } from "whatsapp-web.js";
import { default as qrcode } from "qrcode-terminal";
import { Bard } from "googlebard";
import { config } from "dotenv";
import { handleMessage } from "./BardAI.js";

config();

if(!process.env.COOKIES){
  console.log('Cookie not loaded')
  new Error('Bard cookie not defined in environment')
  process.exit(1)
}

export const api = new Bard(
  `__Secure-1PSID=${process.env.COOKIES}`,
  {
    //inMemory: false, // optional: if true, it will not save conversations to disk
    //savePath: "./conversations.json", // optional: path to save conversations
  }  
);


const client = new Client({})

client.on("qr", (qr) => {
  // Generate and scan this code with your phone
  qrcode.generate(qr, { small: true });
});

client.on("ready", () => {
  console.log("Bot is ready to use.!");
});

client.on("message_create", async (msg) => {
  try {
    await handleMessage(msg);
  } catch (e: any) {
    msg.reply(e.message);
  }

});

client.initialize();
