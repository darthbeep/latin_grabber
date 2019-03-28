import sys
import urllib3
import re
from bs4 import BeautifulSoup

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

def get_html(word):
    http = urllib3.PoolManager()
    html = http.request('GET', "https://en.wiktionary.org/wiki/" + word)
    soup = BeautifulSoup(html.data, 'html.parser')
    return soup

def get_definition(soup):
    start = soup.find(id="Latin").parent.findNext("ol")
    lst = start.find_all('li', recursive=False)
    ret = []
    found = []
    for element in lst:
        elstr = "\t"+element.get_text().split('\n')[0]
        if "#Latin" in str(element):
            bonus = element.find_all(href=re.compile("#Latin"))[0]["title"]
            if bonus not in found:
                found.append(bonus)
                toadd = get_definition(get_html(bonus))
                for b in toadd:
                    elstr+="\n\t\t\t"+b

        ret.append(elstr)
    return ret

def sort_word(word):
    soup = get_html(word)
    print("\t"+word + ":")
    for word in get_definition(soup):
        print("\t" + word)

sort_word("amare")
