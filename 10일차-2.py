#nate 실시간 검색어 보기 Ajax 이용 할때
import warnings
warnings.filterwarnings(action='ignore')
import requests
# from bs4 import BeautifulSoup --> Ajax로 할 때는 이게 필요 없다.
from datatime import datatime as dt

#XHR 는 실시간 검색어가 웹 페이지에 전부 혹인 일부가 포함되어있지 않고 ajax 를 이용해 받아오는 방식
# Request Method가 GET 이므로  requests 모듈의 get() 메소드를 사용해서 실시간 검색어를 가져온다.
targetSite = 'https://www.nate.com/js/data/jsonLiveKeywordDataV1.js?v=202107062000'
request = requests.get(targetSite)
issues = request.text
print(type(issues))# --> 근데 이거 타입이 문자열이다. list 처럼 생겼는데 문자열임
# ajax로 처리 되는 데이터는 무조건 문자열 형태로 얻어온다.
# request 모듈의 jaon() 메소드로 서버에 요청해서 전달받은 데이터를 파이썬에서 처리할 수 있는 리스트나
# 딕셔너리 타입으로 변환 한다. => 데이터가 []로 묶여있으면 list {}로 묶여있으면 딕셔너리로 자동 변환한다.
ranks = request.json()
print(type(ranks))

import json # json 문자열 형태로 얻어온 데이터를 json 모듈의 loads() 메소드를 사용해서 파이썬에서 처리할 수
# 있는 리스트나 딕셔너리 타입으로 변환한다.=> 데이터가 []로 묶여있으면 list {}로 묶여있으면 딕셔너리로 자동 변환한다.

ranks = json.loads(issues)
print(type(ranks))

for rank in ranks :
    print(rank[0], rank[1], end='  ') # --> 순위 꺼내 옴
    if rank[2] == '+':
        print('↑'+ rank[3])
    elif rank[2] == '-':
        print('↓'+ rank[3])
    elif rank[2] == 's':
        print('-')
    else:
        print('new')
