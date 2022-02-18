#음원사이트 Bugs 털어본다.
#Bugs TOP 100
import warnings
warnings.filterwarnings(action='ignore')
import requests
from bs4 import BeautifulSoup
from datatime import datatime as dt

#print(dt.now()) #현재 시간 보여주기

targetSite = 'https://music.bugs.co.kr/chart'
request = requests.get(targetSite)
html = request.text
#print(html)
soup = BeautifulSoup(html,'html.parser')
#print(soup)

# 노래 제목 크롤링
# 노래 제목은 'class' 속성이 'title'인 <p> 태그 내부에 있다.
titles = soup.findAll('p',{'class':'title'})
#print(titles)
#print(len(titles))
for title in titles:
    #print(title.text.strip()) # 안에서 노래 제목 즉 글씨만 가져오기
       # strip 불필요한 공백 지우기
    #print(title.text.split('\n')[1]) # 인덱스 사용은 원하는 데이터만 가져오기 위해
    # 둘을 합치면
    print(title.text.strip().split('\n')[0])


# 아티스트 크롤링
# 가수 이름은 'class' 속성이 'artist'인 <p> 태그 내부에 있다.
# 이거 사이트 에서 F12누르고 확인 가능

artists = soup.findAll('p',{'class':'artist'})
for artist in artists:
    print(artist.text.strip().split('\n')[0])


print(dt.now())
for i in range(100): # 100곡 이여서 100번 돌린다.
    title = titles[i].text.strip().split('\n')[0]
    artist = artists[i].text.strip().split('\n')[0]
    print('{0:3d}위 {1} - {2}'.format(i+1,artist,title))

# 크롤링 결과를 텍스트 파일에 저장하기
file = open('bugsTOP100.txt','w') # read write 알지?
# cp949 이런 에러가 나면 한글 인코딩 문제로 unicodeEncodeError 이다.
# 이럴 때는 file = open('bugsTOP100.txt','w',-1,'UTF-8') 이렇게

file.write('{} 현재 Bugs 뮤직 실시간 TOP 100\n'.format(dt.now()))
for i in range(100): # 100곡 이여서 100번 돌린다.
    title = titles[i].text.strip().split('\n')[0]
    artist = artists[i].text.strip().split('\n')[0]
    data = '{0:3d}위 {1} - {2}'.format(i+1,artist,title)
    file.write(data + '\n') # data 값 텍스트에 넣어 주기
file.close()
print('bugsTOP100.txt 파일에 쓰기 완료')

# 텍스트 파일에 저장된 데이터를 읽어서 출력하기
try:
    file = open('bugsTOP100.txt','r') # r은 close를 안해도 되지만 w 모드는 close 안하면
    # txt가 계속 열려있어서 삭제가 되지 않는다. 반드시 w모드는 close 해야 한다.

    # readLine 한번에 한줄씩 readLines() 한꺼번에 텍스트 파일의 내용 전체를 한번에 쭉 읽어서 list 형식으로 리턴 한다.
    lines = file.readlines()
    for line in lines:
        print(line,end='') # end 안하면 원래 띄어졌던거에 한칸 더 띄어쓰니까 두줄 띄어짐
         # 아니면 strip 써도 괜찮
         
except : # try에서 실행 되지 않으면 여기로 온다.
    # except는 정확히 하면 except FileNotFoundError : 이게 정확한 거긴 함 오류 이름까지 적혀서
    print('bugsTOP100.txt 파일이 디스크에 없습니다.')





