import requests


response = requests.get(f"http://geocode-maps.yandex.ru/1.x/?apikey=&geocode=Москва,+Петровка,+38&format=json")
json_response = response.json()
mura = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
mura_address = mura["metaDataProperty"]["GeocoderMetaData"]["text"]
mura_postal_code = mura["metaDataProperty"]["GeocoderMetaData"]["Address"]["postal_code"]
print(mura_address + " Почтовый индекс " + mura_postal_code)