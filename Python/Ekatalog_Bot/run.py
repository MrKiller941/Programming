from aiogram import types, executor, Dispatcher, Bot
from aiohttp.client import request
from bs4 import BeautifulSoup
import requests
from config import TOKEN
 
 
bot = Bot(TOKEN)
dp = Dispatcher(bot)
 
#команда /start запускает нашего бота
@dp.message_handler(commands=['start'])
async def start(message: types.message):
    await bot.send_message(message.chat.id, """
Привет \U0001F642 Я бот, который поможет тебе быстро находить нужные товары в <b><a href="https://kz.e-katalog.com/">E Каталоге</a></b>
 
Для того, чтобы я отправил тебе интересующий товар, введи в поле его название.""",
parse_mode="html", disable_web_page_preview=0)
 
#парсинг
@dp.message_handler(content_types=['text'])
async def parser(message: types.message):
    url = "https://kz.e-katalog.com/ek-list.php?search_=" + message.text
    print(url, {'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X x.y; rv:42.0) Gecko/20100101 Firefox/42.0'},
            {'user-agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0'},
            {'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:91.0) Gecko/20100101 Firefox/91.0 Waterfox/91.10.0'},
            {'user-agent': 'Defined'})
    request = requests.get(url)
    soup = BeautifulSoup(request.text, "html.parser") # то, что мы будем парсить
 
    all_links = soup.find_all("a", class_="model-short-title") # парсим модель товара
    print(len(all_links)) 
    for link in all_links:
        url = "https://kz.e-katalog.com/" + link["href"] #вывод ссылки на нужный нам товар
        request = requests.get(url)
        soup = BeautifulSoup(request.text, "html.parser") 
 
        name = soup.find("div", class_="fix-menu-name") # парсинг название товара
        price = name.find("a").text # стоимость товара
        name.find("a").extract()
        name = name.text
 
        img = soup.find("div", class_="img200") # парсим картинку товара
        img = img.findChildren("img")[0] # дочерний элемент картинки товара
        img = "https://kz.e-katalog.com/" + img["src"] # вытаскиваем ссылку на товар + картинку его
 
        await bot.send_photo(message.chat.id, img,
        caption="<b>" + name + "</b>\n<i>" + price + f"</i>\n<a href='{url}'>Ссылка на сайт</a>",
        parse_mode="html")
 
        if all_links.index(link) == 9:
            break
 
    if len(all_links) == 0:
        await bot.send_message(message.chat.id, "Ничего не удалось мне найти \U0001F612")
 
executor.start_polling(dp)