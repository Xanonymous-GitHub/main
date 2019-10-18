import bs4
import requests
from selenium import webdriver
head={'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64)\AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101\Safari/537.36'}
url='https://forum.gamer.com.tw/B.php?bsn=60076'
fn='result.html'
try:
    data=requests.get(url,head)
    data.raise_for_status()
    main_obj=bs4.BeautifulSoup(data.text,'html.parser')
    content=main_obj.find_all('td')
    for x in range(len(content)):
        print(content[x].getText())
except Exception as e:print('Error! {}'.format(e))
