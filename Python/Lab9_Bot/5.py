import discord
from config import token

class Bot(discord.Client):
    
    async def on_ready(self):
        print("Я подключился и готов показывать котят и песиков)")

    async def on_message(self, message):
        if message.author == self.user:
            return
        if "кот" in message.content.lower():
            with open('images/cat.png', 'rb') as file:
                picture = discord.File(file)
                await message.channel.send(file=picture)
        elif "собака" in message.content.lower():
            with open('images/dog1.png', 'rb') as file:
                picture = discord.File(file)
                await message.channel.send(file=picture)

client = Bot()
client.run(token)