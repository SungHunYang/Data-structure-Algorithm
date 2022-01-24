#magicsquare (마방진)
#가로 세로 대각선 방향의 모든 숫자 합계가 모두 같은 배열
'''
1.최초의 '1'이 채워지는 자리는 첫 줄 정 가운데 열이다 -> 홀수차 정방행렬(행과 열의 개수가 같은 행렬)만 가능
2. 직전에 채워진 숫자 값에 따라 다음에 채워질 숫자의 위치가 결정된다.
-> 직전에 채워진 숫자가 행렬의 차수(n)의 배수면 다음 숫자는 아랫줄에 채운다. => 행+1
-> 직전에 채워진 숫자가 행렬의 차수(n)의 배수가 아니면 숫자는 오른쪽 위 방향으로 채운다.=>행-1 열 +1
-> 행이 0보다 작아지면 행의 위치를 마지막 위치로 변경한 후 채우고 열이 행렬의 차수와 같이지면 열의 위치를 0으로 변경한다.
'''
'''
from IPython.display import Image --> 사진 꺼내는
Image(' 주소,width='800' <-넓이)
'''
#1차원 리스트 만들기 a= [0 for i in range(5)] 0을 5번 반복 이런식 알지?
# 2차원 리스트 만들기 => 리스트이름 = [[0] * 열의 개수 for 변수 in range(행의 개수)] 요렇게
# 아니면 이건 내 방법 리스트 이름 = [[0 for i in range(5)] for j in range(5)] 이건 내 생각
b=[[0]*5 for i in range(5)]
for i in range (5):
    for j in range(5):
        print('{0:2d} '.format(b[i][j]),end='  ') # 2차원 배열 출력
    print()

# 마방진 만들기

xlist=[[0]*5 for i in range(5)]
# 5행 5열일 경우 최초로 1 이 들어갈 위치 정함
i=0 # 행
j=2 # 열

for k in range(1, 26):  #25 까지 간다
    xlist[i][j]=k # k 가 처음 1 이니까  1을 넣는다

    if k%5 == 0 :
        i+=1
    else:
        i-=1
        #행이 감소 하다 0보다 작아지면 마지막 행의 위치를 조정
        if i<0:
            i=4
        j+=1
        # 열이 증가하다 5가 되면 첫 번째 열로 열의 위치를 조정한다.
        if j>=5:
            j=0

for i in range (5):
    for j in range(5):
        print('{0:2d} '.format(xlist[i][j]),end=' ') # 2차원 배열 출력
    print()

# 입력 받아서 마방진 만들기

while True: # 입력받는 값 체크
    n=int(input('3이상인 홀수를 입력하세요:  '))
    if n>=3 and n%2==1:
        break
    print('3이상인 홀수를 입력해야 합니다.')
# n행 n열인 2차원 리스트를 만든다.
a=[[0] * n for i in range(n)]
i=0 #행 -> 처음 1이 들어가는 행 이다.
j= n//2 #열 -> 처음 1이 들어가는 열 이다.
for k in range(1, n**2+1):  #n행 n열이니까 n**2 +1 까지 간다
    a[i][j]=k # k 가 처음 1 이니까  1을 넣는다

    if k%n == 0 :
        i+=1
    else:
        i-=1
        #행이 감소 하다 0보다 작아지면 마지막 행의 위치를 조정
        if i<0:
            i= n-1
        j+=1
        # 열이 증가하다 n이 되면 첫 번째 열로 열의 위치를 조정한다.
        if j>= n:
            j=0
for i in range (n):
    for j in range(n):
        print('{0:3d} '.format(a[i][j]),end=' ') # 2차원 배열 출력
    print()





























