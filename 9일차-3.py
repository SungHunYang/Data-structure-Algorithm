# 지니 차트는 조금 난이도 있음
# 200개 인데 다른건 한페이지에 100개 인데 지니는 한 페이지에 50곡 씩이라서
# 페이지 4 개를 연결 시켜 줘야한다.
import warnings
warnings.filterwarnings(action='ignore')
import requests
from bs4 import BeautifulSoup
from datatime import datatime as dt
import time

# 타겟 사이트 주소 만들기.
#https://www.genie.co.kr/chart/top200?ditc=D&ymd=20210702&hh=20&rtm=Y&pg=1 -> 1~50
#https://www.genie.co.kr/chart/top200?ditc=D&ymd=20210702&hh=20&rtm=Y&pg=2 -> 51~100
#https://www.genie.co.kr/chart/top200?ditc=D&ymd=20210702&hh=20&rtm=Y&pg=3 -> 101~150
#https://www.genie.co.kr/chart/top200?ditc=D&ymd=20210702&hh=20&rtm=Y&pg=4 -> 151~200
url = 'https://www.genie.co.kr/chart/top200?ditc=D&ymd=20210702&hh=20&rtm=Y&pg='
# 바뀌지 않는 부분을 따로 저장한다.
for i in range(1,5):
    targetSite = '{}{}'.format(url,i)
    print(targetSite)
# for 문으로 바뀌는 숫자 4개 넣어준다.

# 노래 제목 크롤링
url = 'https://www.genie.co.kr/chart/top200?ditc=D&ymd=20210702&hh=20&rtm=Y&pg='
header = {"User-agent": "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko"}
for i in range(1,5):
    targetSite = '{}{}'.format(url,i)
    request = requests.get(targetSite,headers=header)
    html = request.text
    soup = BeautifulSoup(html,'html.parser')

    # 노래 제목은 'class' 속성이 'title ellipsis'인 <a>태그 내부에 있다.
    titles = soup.findAll('a',{'class' : 'title ellipsis'})
    for title in titles :
        print(title.text.strip())

# 아티스트 크롤링
url = 'https://www.genie.co.kr/chart/top200?ditc=D&ymd=20210702&hh=20&rtm=Y&pg='
header = {"User-agent": "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko"}
for i in range(1,5):
    targetSite = '{}{}'.format(url,i)
    request = requests.get(targetSite,headers=header)
    html = request.text
    soup = BeautifulSoup(html,'html.parser')

    # 아티스트는 'class' 속성이 'artist ellipsis'인 <a>태그 내부에 있다.
    artists = soup.findAll('a',{'class' : 'artist ellipsis'})
    for artist in artists[5:] : # 지니는 순위 차트에 5위까지는 매번 나와서 5번 부터 본다.
        print(artist.text.strip())

# 크롤링한 데이터를 리스트에 저장한다. 그동안 했던 크롤링 종합하기
genie = []
url = 'https://www.genie.co.kr/chart/top200?ditc=D&ymd=20210702&hh=20&rtm=Y&pg='
header = {"User-agent": "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko"}
for i in range(1,5):
    targetSite = '{}{}'.format(url,i)
    request = requests.get(targetSite,headers=header)
    time.sleep(1)
    html = request.text
    soup = BeautifulSoup(html,'html.parser')

    titles = soup.findAll('a',{'class' : 'title ellipsis'})
    artists = soup.findAll('a',{'class' : 'artist ellipsis'}) # 얘는 5번 부터 뽑아야 된다. 5위까지 계속 나오니까

    # genie 리스트에 노래 제목과 가수이름을 튜플로 만들어 저장한다.
    for j in range(50): # 한 페이지당 50개
        genie.append(
            (titles[j].text.strip().split('\n')[0], artists[j+5].text.strip().split('\n')[0])
            )
#print(genie)

print(dt.now())
for i in range(200):
    print('{0:3d}위 {1} - {2}'.format(i+1,genie[i][1],genie[i][0])) # genie 리스트 안에 튜플로 가수와 제목을 넣었으므로 이차원리스트가 된다.

# 크롤링 한 결과를 텍스트 파일로 저장한다.
file = open('genieTOP200.txt','w')
file.write('{} 현재 Genie 뮤직 실시간 TOP 200\n'.format(dt.now())
for i in range(200):
    data = '{0:3d}위 {1} - {2}'.format(i+1,genie[i][1],genie[i][0])
    file.write(data+'\n')
file.close()
print('Genie 쓰기 완료')

# 파일 읽어서 출력
try :
    file =open('genieTOP200.txt','r')
    lines = file.readlines()
    for line in lines:
        print(line.strip())
except:
    print('genieTOP200.txt 파일이 없습니다.')
        














    
        
