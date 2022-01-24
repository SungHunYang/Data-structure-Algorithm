import random # 난수 생성 randrange()
import time   # 시간 주는 함수 sleep()

#로또 추첨기 역할을 할 리스트를 만들고(튜플을 수정이 안돼서 리스트로 만듬) 1~45로 초기화
'''
lotto=[]
for i in range(1,46): --> 45까지 그냥 숫자 넣는법
    lotto.append(i)
print(lotto)
'''
lotto=[i for i in range(1,46)] #--> 이렇게도 가능
#섞기 전 상태 출력 --> 1줄에 10개씩 --> 이런것도 알고리즘이다.
for a in range(len(lotto)):
    if (a+1)%10==0:
        print()
    #print(lotto[a],end=" ") 이렇게도 되고
    print("{0:2d}".format(lotto[a]),end=" ")
print("\n =========== 섞기 전")

#lotto[0]와(고정) lotto[1]~ lotto[44] 중에서 랜덤한 위치의 값을 선택해서 두 기억 장소의 데이터를 교환 한다.--> 알고리즘
# randrange(a,b) --> a부터 b-1사이에서 랜덤한 숫자
for i in range(1,20):
    r=random.randrange(1,45) ## 랜덤 함수 쓰는법 까먹지 말
    lotto[0], lotto[r]=lotto[r], lotto[0]
    
for t in range(len(lotto)):
    if (t+1)%10==0:
        print()
    print("{0:2d}".format(lotto[t]),end=" ")
print("\n =========== 섞은 후")

# 1등 번호와 보너스 번호를 출력한다.
#앞에 6개가 1등번호 그 뒤에 1개가 보너스 번호
print("1등 번호 : ",end=' ')
for i in range(6):
    print('{0:2d}'.format(lotto[i]),end=" ")
    # time 모듈의 sleep() 메소드는 인수로 지정된 시간만큼 프로그램을 일시적으로 멈춘다.
    # sleep() 메소드에 프로그램을 멈추는 시간은 '초' 단위로 지정한다.
    # 자바 c언어 같은 경우에는 () 안에가 1000분에 1 초인데 파이선은 그냥 적인 대로 초이다. 즉 (1)하면 1초라는 거다.
    time.sleep(0.5) # 0.5초
print(" 보너스 번호 : ",lotto[6])

# 미국 로또 => powerball, 1~69 사이에서 5개 1~26사이 1개 고르기
print(" =========== 미국 로또")
alotto=[]
for i in range(5):
    t=random.randrange(1,70)
    alotto.append(t)
g=random.randrange(1,26)
alotto.append(g)

print('red ball :',end=" ")
for i in range(5):
    print('{0:2d}'.format(alotto[i]),end=" ")
    time.sleep(0.5)
print(" white : ",alotto[5])

#로또 번호를 기억할 빈 set을 선언한다.
slotto=set()  # set은 중복되는 숫자는 안들어간다.!!!!!

# 1등 번호
# 무한루프를 돌려주는 이유는 랜덤으로 발생시킨 숫자가 몇 번 중복될 지 모르기 떄문이다.
while True:
    number=random.randrange(1,46)
    slotto.add(number)
    print('{0:2d} {1}'.format(number,slotto))
    # set에 중복되지 않는 숫자가 6개 저장 되면 무한 루프 탈출
    if len(slotto)==6:
        break
print('1등 번호 : {}'.format(slotto),end=" ")
#보너스 번호가 로또 번호에 없을 경우 무한 루프 탈출
while True:
    r=random.randrange(1,46)
    print(r)
    if r not in slotto:
        break
print('보너스 번호 : {}'.format(r))




















