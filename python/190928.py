import webbrowser as web
import requests as rq
url='https://github.com'
html=rq.get(url)
print(type(url))
