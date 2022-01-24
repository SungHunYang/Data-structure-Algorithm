#큐 FIFO 입력은 뒤(rear), 출력은 앞(front) FIFO(먼저 들어온게 먼저 나감)
# rear front는 처음 데이터 0위치에 있음
# 입력할 때는 rear가 증가 출력하면 front가 증가

class Queue:
    def __init__(self,size=5):
        self.queue=[] #큐 => 빈리스트로 만듬
        self.size=size # 큐의 크기
        self.rear = 0 # 큐의 뒤쪽 포인터 => 큐에 데이터가 입력될 때 마다 1씩 증가한다.
        self.front = 0 # 큐의 앞쪽 포인터 => 큐에서 데이터가 제거될 때 마다 1씩 증가한다.

    #add=> 입력
    def add(self, data):
        if data not in self.queue : # not in 은 self.queue에 없다는 뜻
            # 큐에 추가하려는 데이터가 큐에 존재하지 않는가?
            # overflow 검사
            if self.size > self.rear :
                # 오버플로우가 아닐때
                self.queue.append(data)
                self.rear+=1
            else :
                # 오버 플로우
                print('큐이 가득 찼습니다 overflow -> {} 넣을 수 없습니다.'.format(data))
        else : # 중복된 값
            print('{} : 중복된 값 입니다.'.format(data))
        #underflow 인가 검사한다.
        if self.rear <=0 or self.rear == self.front :
            # 큐에 저장된 데이터가 없으므로 없다고 출력한다.
            print('저장된 데이터 없음')
        else :
            # 큐에 저장된 데이터의 개수만큼 반복하며 큐에 저장된 데이터를 출력한다.
            print('add :: queue = [ ',end=' ')
            for i in range(self.front,self.rear):
                print(self.queue[i], end=' ')
            print(' ]')
    #remove => 출력

    # view => 보기
    def view(self):
        #underflow 인가 검사한다.
        # 1. 큐에 데이터가 아예 입력되지 않았을 경우 rear가 0 이므로 underflow가 발생된다.
        # 2. 큐에 데이터가 입력된 후 입력된 데이터가 모두 제거 되면 rear == front 가 되면서 underflow가 발생된다
        if self.rear <=0 or self.rear == self.front :
            # 큐에 저장된 데이터가 없으므로 없다고 출력한다.
            print('저장된 데이터 없음')
        else:
            # 큐에 저장된 데이터의 개수만큼 반복하며 큐에 저장된 데이터를 출력한다.
            print('view :: queue = [ ',end=' ')
            for i in range(self.front,self.rear):
                print(self.queue[i], end=' ')
            print(' ]')
        
que=Queue()
que.add(100)
que.add(100)
que.add(200)
que.add(300)
que.view()









    
        
        
