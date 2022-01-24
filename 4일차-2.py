# 기수 정렬 = radixSort
# 진법 수에 맞는 큐가 필요하다.
#--> 큐 이용 --> FIFO --> 십진수 큐 --> 일의 자리 맞춰서 큐 10개 에 사용(0~9)
# --> 그 다음 데이터를 다 꺼낸다 --> 그다음 또 다시 같은 작업 시작 이번에는 십의 자리로 집어 넣음
# --> 그 다음 백의 자리.. 이런식으로 쭉 하면 정렬
data=[19, 2, 31, 45, 30, 11, 121, 27]
isSort= False # 정렬이 완료 되었나 기억하는 변수
radix = 1 # 큐에 넣어줄 자리수의 위치를 기억하는 변수  1의 자리 10의 자리 100의 자리 이런거

# 정렬이 완료 될 때 까지 반복한다
# isSort에 False가 들어 있으면 아직 정렬이 완료되지 않은 상태를 의미하고 True 이면 정렬 완료
while not isSort:  # not 이니까 지금 True 인데 True가 되면 False 가 되서 종료
    isSort=True
    # 정렬할 숫자의 기수(진법)의 크기만큼 큐로 사용할 리스트를 만든다.
    queueList=[[] for i in range(10)]# 2차원 배열
    print('radix : {}'.format(radix))
    # 정렬할 데이터의 개수만큼 반복하며 큐에 넣어준다.
    for n in data:
        print('n : {}'.format(n),end=" => ")
        # 큐에 넣어줄 자리수(radix)에 해당되는 숫자만 뽑아낸다
        digit=n//radix%10 #--> 이거 일의 자리 십의자리 백의자리 뽑아내는 식 알지? n//radix 한값의 일의 자리만 쭉 나온다,
        print(digit)
        # 큐에 숫자 넣어준다
        queueList[digit].append(n)
        #정렬이 완료 되었나 검사한다.
        if isSort and digit>0: # digit이 하나라도 0보다 크면 정렬이 안된거다.
            isSort=False
    # 큐에 저장된 데이터를 0번 큐부터 차례대로 꺼네서 data를 수정한다.
    index=0
   # queueList에 저장된 0번 큐를 numbers 리스트에 저장한 다음 반복을 시작해서 9번 큐를 numbers 리스트에 저장한 후
   # 반복한 다음 종료한다.
    for numbers in queueList: # 2차원 중에서 1차원씩 받고
       # 각각의 기수에 해당되는 리스트에 저장된 데이터 개수만큼 반복하며 data를 수정한다.
        for number in numbers: # 1차원에 들어있는거 하나씩 뽑아낸다.
            data[index]=number
            index+=1
    print(data)
    print('='*30)
    radix*=10 # 이거 1의 자리가 10의 자리 되고 100의 자리 되고 하게 하는거 알지?
print(data)

    
    

