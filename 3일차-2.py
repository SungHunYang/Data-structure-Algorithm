#선택정렬
xlist=[9,5,7,2,8,6,3]
for i in range(len(xlist)-1):
    for j in range(i+1,len(xlist)):
        if xlist[i]>xlist[j]:
            xlist[i],xlist[j]=xlist[j],xlist[i]

print(xlist)

#선택정렬을 이용한 석차 계산
score=[70,100,80,100,90]
rank=[1 for i in range(len(score))] #--> 여기에 석차를 넣을 거기 때문에 1로 초기화 시켜 줘야함

for i in range(len(score)-1):
    for j in range(i,len(score)):
        if score[i]<score[j]: # 선택된 값이 다른 값보다 값이 작으면 선택된 값이 +1
            rank[i]+=1
        elif score[i]>score[j]:  # 그런데 선택된 값이 다른 값보다 크면 ''비교대상인 다른값'' 의 석차 +1
            rank[j]+=1
# 이 뜻이 선택 정렬이라 이전 값이랑은 비교 하지 않기 때문에 미리미리 비교 할 때마다 석차를 올려준다.    
print(score)
print(rank)
for i in range(len(rank)):
    print('★' * rank[i])
# 버블 정렬 --> 이거 할 줄 알지?
# 버블 정렬은 데이터가 어느정도 정렬이 되어있는 상태라면 회전수를 다 채우지 않더라도 정렬이
# 완료되었나 판다해서 조기에 종료 가능 => early stop 기능
# boolean 함수 사용

data=[9,1,3,4,8]
for i in range(len(data)-1):

    #회전(정렬) 작업이 시작되기 전에 변수를 선언하고 True로 초기화 시킨다.
    flag = True

for j in range(len(data)-1-i):
     if data[j] > data[j+1]:
        data[j],data[j+1]=data[j+1],data[j]
        #값교환 작업이 실행되면 변수를 False로 수정한다.
        flag=False
        # if문을 거쳐야만 flag 값이 False가 되는데 만일 정렬이 끝났으면
        # if문을 거치지 않기 때문에 flag 값이 그대로 True로 온다 바로 종료 가능
    if flag:
        print('원래는 {} 회전을 해야하지만 {} 회전 후 중간 종료됨'.format(len(data)-1,i+1))
        break
    
            













