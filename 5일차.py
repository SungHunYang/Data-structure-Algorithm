#Binary Search(이진검색)(제어검색) 제어 검색은 검색할 데이터가 정렬이 되어 있어야 한다.
#이진 검색 제어 검색의 한 종류(이진 검색, 피보나치 검색, 보간 검색)로 검색하려는 데이터를 파일의 중간 위치의 데이터와
#비교 하면서 검색을 수행한다.
data=[2,11,19,28,30,31,45,121]
LH=0
RH=len(data)-1 # 마지막 데이터를 기억하는 변수 
mid=(LH+RH)//2
count =0 # 몇번 돌았는지 보기 위해
isFlag = False # 데이터 검색에 성공했나(true) 실패했다(False)를 기억하는 변수
s=int(input("찾을 값을 넣으세요 : "))
while True:
    if s==data[mid]:
        print("찾았습니다. {} 번".format(count))
        break
    elif s>data[mid]:
        LH=mid+1
        print(data[mid])
    elif s<data[mid]:
        RH=mid-1
        print(data[mid])
    mid=(LH+RH)//2
    count+=1
    if LH>RH:
        print("못 찾았습니다.")
        break 
