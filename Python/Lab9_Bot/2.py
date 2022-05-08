from email.utils import localtime
from aiogram import Bot, types
from aiogram.dispatcher import Dispatcher
from aiogram.utils import executor
import time
from datetime import date


bot = Bot("5177958791:AAExrbojHx1T_mLzDDsb7AmbSTs0S5aNOXE")
dp = Dispatcher(bot)
t = time.localtime()


@dp.message_handler(commands=['time'])
async def process_time_command(message: types.Message):
    await message.reply(time.strftime("%H:%M:%S", t))


@dp.message_handler(commands=['date'])
async def process_time_command(message: types.Message):
    await message.reply(date.today())


@dp.message_handler(commands=['help'])
async def process_help_command(message: types.Message):
    await message.reply("Введите команду /time, чтобы получить текущее время или /date, чтобы получить текущую дату")


if __name__ == '__main__':
    executor.start_polling(dp)
