import { default as WAWebJS } from "whatsapp-web.js";
import { api } from "./index.js";
import fs from "fs";

// initialisasi room
type Room = {
  parentMessageId: string;
};

let myParentMessageId: string | undefined = undefined;

// rooms
const rooms: Map<string, Room> = new Map();
var conversationId = "";

export async function handleMessage(message: WAWebJS.Message) {
  const { command, args } = getCommand(message.body);

  switch (command) {
    case "/bot":
      await commandBARD(message, args);
      return;

    case "/help":
      setTimeout(() => {
        message.reply(
          "Hello, I am a bot integrated with BARD Google,\n\nType */bot on* to activate the bot,\nType */bot off* to deactivate the bot.\nType */bot clear* to clear the conversation.\nType */bot refresh* to refresh the bot.\n\nIf the bot is active then you can communicate with the bot, for example n\n*1+1?*"
        );
      }, 2000);
      return;
  }
  if (message.fromMe) return;

  // get last message
  const chat = await message.getChat();
  const room = rooms.get(chat.id.user);

  if (room) {
    conversationId = room.parentMessageId;
  } else {
    conversationId = chat.id.user;
  }
  // typing indicator
  chat.sendStateTyping();

  // creating conversation
  const reply = await api.ask(message.body, conversationId);
  // reply last message
  message.reply(reply);
}

async function commandBARD(message: WAWebJS.Message, args: string[]) {
  const chat = await message.getChat();

  // conversation id // optional: to make it remember the conversation

  if (message.fromMe) {
    chat.sendStateTyping();
    const reply = await api.ask(args.join(" "), conversationId);
    message.reply(reply.text);
    return;
  }

  if (args[0] === "on") {
    conversationId = chat.id.user;

    chat.sendStateTyping();
    const reply = await api.ask(
      `*Hello, my name is ${(await chat.getContact()).pushname},`,
      conversationId
    );


    rooms.set(chat.id.user, {
      parentMessageId: conversationId,
    });

    message.reply("develop by @evnx32\nhttps://github.com/evnx32\n\n" + reply);
  } else if (args[0] === "off") {
    chat.sendStateTyping();
    message.reply("Turn off the bot..");
    api.resetConversation(conversationId);
    rooms.delete(chat.id.user);

  } else if (args[0] === "clear") {
    chat.sendStateTyping();
    message.reply("clearing all conversation..");
    api.resetConversation(conversationId);
    rooms.delete(chat.id.user);

  } 
}

function getCommand(message: string) {
  const splt = message.split(" ");
  return { command: splt[0], args: splt.slice(1) };
}
