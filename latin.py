import sys
import urllib3
from bs4 import BeautifulSoup

def get_html(word):
    http = urllib3.PoolManager()
    html = http.request('GET', "https://en.wiktionary.org/wiki/" + word)
    soup = BeautifulSoup(html.data, 'html.parser')
    return soup

def get_definition(soup):
    start = soup.find(id="Latin").parent.findNext("ol")
    lst = start.find_all('li', recursive=False)
    for element in lst:
        print(element.get_text().split('\n')[0])

soup = get_html("terreo")
get_definition(soup)
