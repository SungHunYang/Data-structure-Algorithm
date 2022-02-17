#nate 실시간 검색어 보기
import warnings
warnings.filterwarnings(action='ignore')
import requests
from bs4 import BeautifulSoup
from datatime import datatime as dt

targetSite = 'https://www.nate.com/'
header = {"User-agent": "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko"}
request = requests.get(targetSite,headers=header)
soup = BeautifulSoup(html,'html.parser')

#실시간 이슈 키워드만 크롤링하려면
#'class' 속성이 'txt_rank' 인 <span>태그 내부에 있다.
#issues = soup.findAll('span',{'class' : 'txt_rank'}) -> 실시간 이슈 키워드만 가지고 오려면
#for issue in issues :
    #print(issue.text)

#### 그냥 긁어 올 때

# 실시간 이슈 키워드와 상승, 하락 까지 크롤링 하려면 'class' 속성이 'ik'인 <a>태그 내부
issues = soup.findAll('a',{'class' : 'ik'})
for issue in issues :
    print(issue.text.split('\n')[1], issue.text.split('\n')[2])
print('='*20)
for issue in issues :
    print(issue.text.split('\n')[1], end=', ')
    upDown = issue.text.split('\n')[2]
    if upDown[:2] == '상승':  # 여긴 그냥 상승하락 멋있게 보여주려고 하는거 알지?
        print('↑'+ upDown[2:])
    elif upDown[:2] == '하락':
        print('↓'+ upDown[2:])
    elif upDown[:2] == '동일':
        print('-')
    else:
        print(upDown)












