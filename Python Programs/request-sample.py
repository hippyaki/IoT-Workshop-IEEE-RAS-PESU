import requests
import json

url = "https://esp32-server-324409-default-rtdb.firebaseio.com/Device 4.json"

querystring = {"auth":"4gmoOLRzpGxxxxxxxxxxxx8Ugz0aABOT6pf"}

response = requests.request("GET", url, params=querystring)


line = json.loads(response.text)
#data = str(line['data'])
print(line)
