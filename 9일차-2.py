#음원사이트 melon 털어본다.
#melon TOP 100
import warnings
warnings.filterwarnings(action='ignore')
import requests
from bs4 import BeautifulSoup
from datatime import datatime as dt

#print(dt.now()) #현재 시간 보여주기
'''
targetSite = 'https://www.melon.com/chart/index.htm'
request = requests.get(targetSite)
print(request) #<Response [406]> => 헤더 문제로 사이트의 요청한 정보를 얻어 올 수 없다.
멜론은 bug랑 똑같이 하면 response [406] 에러가 뜬다. [200] 이 떠야 성공 한거다.
크롤링시 406 에러가 발생될 경우
헤더 정보 사이트 => https://developers.whatismybrowser.com/useragents/explore/layout_engine_name/trident/
header = {"User-agent": "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko"}
사이트 에서 Mozilla/5.0 NT 6.1 버전으로 복사 하면 할 수 있다. 위에 적혀 있는거
'''
targetSite = 'https://www.melon.com/chart/index.htm'
header = {"User-agent": "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko"}
request = requests.get(targetSite,headers=header)
print(request)
html = request.text
soup = BeautifulSoup(html,'html.parser')

# 노래 제목 크롤링
# 노래 제목은 'class' 속성이 'ellipsis rank01' 인 <div> 태그 내부에 있다.
titles = soup.findAll('div',{'class' : 'ellipsis rank01'})
for title in titles:
    print(title.text.strip().split('\n')[0])
# 가수 이름 크롤링
# 가수 이름은 'class' 속성이 'checkEllipsis' 인 <span> 태그 내부에 있다.
artist = soup.findAll('span',{'class' : 'checkEllipsis'})
for artist in artists:
    print(artist.text.strip().split('\n')[0])

for i in range(100):
    title = titles[i].text.strip().split('\n')[0]
    artist = artists[i].text.strip().split('\n')[0]
    print('{0:3d}위 {1} - {2}'.format(i+1,artist,title))

# 파일 텍스트에 넣는거 벅스와 동일








