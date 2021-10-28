import requests
import json

url = "http://api.weatherbit.io/v2.0/current"

querystring = {"city":"guwahati", "country": "India", "key": "ca8bbc0aa955422ba8a9f3fe3c82956a"}


response = requests.request("GET", url, params=querystring)


line = json.loads(response.text)
#print(line)
data = str(line['data'][0]['weather']['description'])
print(data) 


