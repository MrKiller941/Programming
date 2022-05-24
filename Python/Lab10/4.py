import requests



response = requests.get(f"http://geocode-maps.yandex.ru/1.x/?apikey=&geocode=Барнаул&format=json")
json_response = response.json()
city = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
city_region = city["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
print("Барнаул: " + city_region)

response = requests.get(f"http://geocode-maps.yandex.ru/1.x/?apikey=&geocode=Мелеуз&format=json")
json_response = response.json()
city = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
city_region = city["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
print("Мелеуз: " + city_region)

response = requests.get(f"http://geocode-maps.yandex.ru/1.x/?apikey=&geocode=Йошкар-Ола&format=json")
json_response = response.json()
city = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
city_region = city["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
print("Йошкар-Ола: " + city_region)