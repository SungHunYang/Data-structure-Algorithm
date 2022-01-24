'''
#selenium 이용하는 건데 이건 설치가 필요함 --> 영상 꼭 다시 참고하셈.
#selenium을 사용하기 위해 selenium 을 설치하고 improt 한다.
# !pip install selenium --> 이게 설치 방법인데 암튼... 영상 꼭 봐야 겠다 이건... 2021 07 06 10일차 영상
import warnings
warnings.filterwarnings(action='ignore')
from selenium import webdriver
from bs4 import BeautifulSoup
from datatime import datatime as dt
'''
#===========================================================

# image 크롤링 하기
import warnings
warnings.filterwarnings(action='ignore')
import requests
url = 'https://search.pstatic ' # -> 여기 이미지 링크 복사로 넣으면 되는데 너무 길어서 일단 은 내가 잘랐다
# 나중에 혼자 해볼때 꼭 해보기 
request = requests.get(url)
file = open('junim.png','wb') # w 로 하면 text로 인식 -> wb 이진 바이너리 파일 사진 가능
# write binary = wb
file.write(request.content) # --> 글씨만 꺼낼 때는 request.text 였지만 이미지는 request.content 로 한다.
file.close()
#--> 이렇게 하면 이미지 링크 복사한거 사진으로 저장되어 있다.
