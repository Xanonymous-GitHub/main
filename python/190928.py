import webbrowser as web
import requests as rq
import bs4
url='https://github.com'
html=rq.get(url)
soup = bs4.BeautifulSoup(html.text)
print(soup.prettify())
# print(type(url))
