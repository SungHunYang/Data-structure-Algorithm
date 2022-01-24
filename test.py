def shell(data): # n로그n
    print('Before [',end=' ')
    for i in data:
        print(i,end=' ')
    print(']')
    mid=len(data)//2
    while mid > 0 :
        for i in range(mid,len(data)):
            index=i
            while index>=mid and data[index-mid]>data[index]:
                data[index-mid],data[index]=data[index],data[index-mid]
                index-=mid
            #print(data)
        mid//=2
    print('After [',end=' ')
    for i in data:
        print(i,end=' ')
    print(']')
    
#############################################
def insertSort(data):
    print('Before [',end=' ')
    for i in data:
        print(i,end=' ')
    print(']')
    for i in range(1,len(data)):
        temp=data[i]
        index=i # 이걸 왜 쓰나 했는데
        # elif문에서 data[j+1]=temp 이렇게만 넣어버리면
        # 제일 작은 값이 맨 앞으로 오지를 못한다.
        # 그니까 비교하는 대상이 더 큰값이여서 뒤로 전부 다 밀고
        # 맨 앞으로 불러오지를 못한상태인거다.
        for j in range(i-1,-1,-1):
            if data[j] > temp:
                data[j+1] = data[j]
                index-=1
            elif data[j] <= temp :
                break
        data[index] = temp
    print('After [',end=' ')
    for i in data:
        print(i,end=' ')
    print(']')
    
######################################################
def bubbleSort(data):
    print('Before [',end=' ')
    for i in data:
        print(i,end=' ')
    print(']')
    for i in range(len(data)-1):
        chk=True
        for j in range(len(data)-1):
            if data[j] > data[j+1] :
                data[j],data[j+1]=data[j+1],data[j]
                chk=False
        if chk:
            print('조기 종료!')
    print('After [',end=' ')
    for i in data:
        print(i,end=' ')
    print(']')

#####################################################
def selectionSort(data):
    print('Before [',end=' ')
    for i in data:
        print(i,end=' ')
    print(']')
    for i in range(len(data)-1):
        for j in range(i+1,len(data)):
            if data[i] > data[j] :
                data[j],data[i]=data[i],data[j]
    print('After [',end=' ')
    for i in data:
        print(i,end=' ')
    print(']')

######################################################
def magicsquare(size):
    if size%2 ==0:
        print('마방진 불능')
        return 0
    print('처음 마방진')
    b=[[0]*size for a in range(size)]
    for k in range(len(b)):
        for u in range(len(b)):
            print(b[k][u],end='  ')
        print()
    i=0 # 행
    j=size//2 #열
    for y in range(1,size**2+1):
        b[i][j]=y
        if y%size == 0:
            i+=1
        else :
            i-=1
            j+=1
            if i<0:
                i= size-1
            if j == size :
                j=0
    print('결과 마방진')
    for k in range(size):
        for u in range(size):
            print('{0:2d}'.format(b[k][u]),end='  ')
        print()      

##################################################################
class Stack:
    def __init__(self,size=5):
        self.stack=[]
        self.size=size
        self.top=0

    def push(self,data,num=0):
        if data not in self.stack :
            if self.size <= self.top :
                print('overflow shit!')
                return 0
            elif num == 0:
                self.stack.append(data)
                self.top+=1
                print('push Success!')
            else:
                self.stack.insert(num-1,data) # insert 인식해라
                self.top+=1
                print('push Success!')
        else:
            print('already in..')
            
    def pop(self):
        if self.top < 0 :
            print('underflow shit')
            return 0

        data=self.stack.pop()
        print('delete {}'.format(data))
        self.top -=1
        print('Leave : ')
        for i in range(self.top):
            print(self.stack[i],end=' ')
        print()
        
    def view(self):
        print('STACK = [ ',end='')
        for i in range(self.top):
            print(self.stack[i],end=' ')
        
        print(']')
#########################################################
class Queue:
    def __init__(self,size=5):
        self.queue=[]*size
        self.size=size
        self.front=0
        self.rear=0
        
    def add(self,data):
        if data not in self.queue:
            if self.size <= self.rear:
                print('overflow!')
                return 0
            if self.front > self.rear:
                print('underflow!')
                return 0
            self.queue.append(data)
            self.rear+=1
            print('add {}'.format(data))
            print('Add Success')
            print('rear = {} front ={}'.format(self.rear,self.front))

    def remove(self):
        if self.rear <=0 or self.front == self.rear :
            print('empty')
            return 0
        print('remove {}'.format(self.queue[self.front]))
        ##self.queue.remove(self.queue[self.front])
        ##--> 이렇게 제거 하면 삭제된 값 뒤로 앞으로 다 땡겨져서 front 사용 어려움
        self.queue[self.front]='' ## 그래서 이렇게 안보이게 한다.
        self.front+=1
        print('Remove Success')
        print('rear = {} front ={}'.format(self.rear,self.front))
        if self.rear == self.size and self.front == self.size  :
            self.rear = 0
            self.front = 0
            for i in range(self.size):
                self.queue.pop()
            
    def veiw(self):
        if self.rear <=0 or self.rear == self.front :
            print('empty -> underflow')
            return 0
        print('QUEUE = [ ',end='')
        for i in range(self.front,self.rear):
            print(self.queue[i],end=' ')
        print(']')
#########################################################
class CircleQueue:
    def __init__(self,size=5):
        self.cQueue=[None]*size # 이거 self.cQueue[self.rear]=data 쓸때는 교체이니까 None을 안적어주면
        # 아무것도 없어서 교체가 안돼므로 꼭 None이라도 써줘야 함!
        self.size=size
        self.front=0
        self.rear=0
    def is_empty(self):
        if self.rear==self.front:
            return 1
        return 0
    def is_full(self):
        if ((self.rear+1)%self.size) == self.front:
            return 1
        return 0
    def add(self,data) : # 중복 허용
        if self.is_full():
            print('overflow!')
            return 0
        self.rear=(self.rear+1)%self.size
        self.cQueue[self.rear]=data
        print('add success {}'.format(data))
        print('rear = {} front ={}'.format(self.rear,self.front))

    def remove(self):
        if self.is_empty():
            print('underflow!')
            return 0
        print('remove success {}'.format(self.cQueue[(self.front+1)%self.size]))
        self.front=(self.front+1)%self.size
        '''
            굳이 삭제 하지 않는 이유는
            1. 큐의 사이즈는 정해져 있기 때문에 데이터의 낭비는 생기지 않음
            2. 큐를 볼때는 front 부터 rear까지만 보기 때문에 front만 땡겨도 없어진 거처럼 보인다.
            3. 그 다음 넣을 때 그 위치에 덮어 씌우면 된다.
          '''
        print('rear = {} front ={}'.format(self.rear,self.front))
        
    def veiw(self):
        if self.front > self.rear :
            print('CircleQUEUE = [ ',end='')
            for i in range(0,self.rear+1):
                print(self.cQueue[i],end=' ')
            print(']')
        else:
            print('CircleQUEUE = [ ',end='')
            for i in range(self.front+1,self.rear+1):
                print(self.cQueue[i],end=' ')
            print(']')
            
#########################################################
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head=None
        self.top= 0

    def insert(self,data):#마지막에 넣을 때
        newNode=Node(data)
        if self.head is None:
            self.head = newNode
            self.top+=1
            print('Head에 [ {} ] 삽입'.format(data))
            print('데이터 --> ( {} )개'.format(self.top))
            return
        start = self.head
        while start.next :
            start = start.next
        start.next=newNode
        self.top+=1
        print('List에 [ {} ] 삽입'.format(data))
        print('데이터 --> ( {} )개'.format(self.top))
            
    def indexInsert(self,data,num=0):
        if num > self.top:
            print('index error')
        elif num == 0:
            newNode=Node(data)
            newNode.next=self.head
            self.head = newNode
            self.top+=1
            print('[ {} ] 번 Index [ {} ]삽입'.format(num,data))
            print('데이터 --> ( {} )개'.format(self.top))
        else :
            newNode=Node(data)
            before = self.head
            for i in range(num-1): # before 찾아야해서 num-1이다
                before = before.next
            newNode.next = before.next
            before.next = newNode
            self.top+=1
            print('[ {} ] 번 Index [ {} ]삽입'.format(num,data))
            print('데이터 --> ( {} )개'.format(self.top))
            
    def delete(self,data):
        start = self.head
        if start is None:
            print('List is empty than dose not delete')
        else:
            if start.data == data:
                self.head = start.next
                self.top-=1
                print('ListHead [ {} ] 삭제'.format(data))
                print('데이터 --> ( {} )개'.format(self.top))
            else :
                while start is not None:
                    # start.next로 하면 한칸 앞까지만 나와
                    # 그런데 이렇게 하면 완전 끝까지 나오니까 start is None이 가능
                    if start.data == data:
                        break
                    before = start
                    start = start.next
                    
                if start is None:
                    print("Can't find data {}".format(data))
                else :
                    before.next = start.next
                    self.top-=1
                    print('List [ {} ] 삭제'.format(data))
                    print('데이터 --> ( {} )개'.format(self.top))
                    
    def view(self):
        start = self.head
        print('LinkedList [ ',end=' ')
        for i in range(1,self.top+1):
            print('( ',start.data,' )',end='-->')
            start=start.next
        print(' ]')
##########################################################
        
class Tree:
    def __init__(self,data= None):
        self.data = data
        self.left=None
        self.right=None

    def insert(self,data):
        if data>self.data:
            if self.right is None:
                self.right = Tree(data)
            else :
                self.right.insert(data)

        elif data < self.data:
            if self.left is None:
                self.left = Tree(data)
            else :
                self.right.insert(data)
                
    def preorder(self):
        # 함수를 불렀을때 아직 아무 값도 받지 않아서
        # 계속 함수를 부르는데 그 마지막에 함수가 값을 받으면
        # 이 전에 불렀던 함수로 돌아간다는걸 기억해야
        # self.data가 계속 나오는걸 알 수 있다.
        print(self.data,end=' ')
        if self.left : 
            self.left.preorder()
        if self.right:
            self.right.preorder()

#########################################################


          
'''
b=[19,2,31,45,30,11,121,27]
shell(b)
'''           
'''
b=[56,91,9,7,2,13,8,19,73]
insertSort(b)
'''          
'''
b=[7,55,9,31,75,2,79,3,0,4]
bubbleSort(b)
'''
'''
b=[10,5,88,91,2,44,7]
selectionSort(b)
'''
'''
magicsquare(5)
'''
'''            
root = BinaryTree(12)
root.insert(12)
print()
root.insert(6)
print()
root.insert(20)
print()
root.insert(3)
print()
root.insert(25)
print()
root.insert(10)
print()
root.insert(15)
print()

root.preorder()
print()
'''
'''
link = LinkedList()
link.delete(1)
link.insert(11)
link.insert(22)
link.insert(33)
link.view()
link.insert(44)
link.insert(55)
link.view()
link.indexInsert(0)
link.view()
link.indexInsert(7,2)
link.indexInsert(9,4)
link.view()
link.delete(88)
link.delete(0)
link.view()
link.delete(11)
link.view()
link.delete(9)
link.delete(44)
link.view()
'''
'''
cqueue=CircleQueue()
cqueue.__init__()
cqueue.add(5)
cqueue.add(10)
cqueue.add(15)
cqueue.veiw()
cqueue.add(50)
cqueue.add(70)
cqueue.veiw()
cqueue.remove()
cqueue.remove()
cqueue.veiw()
cqueue.remove()
cqueue.veiw()
cqueue.remove()
cqueue.veiw()
cqueue.add(9)
cqueue.add(18)
cqueue.veiw()
cqueue.remove()
cqueue.veiw()
cqueue.remove()
cqueue.veiw()
cqueue.add(99)
cqueue.veiw()
'''
'''      
queue=Queue()
queue.__init__()
queue.add(5)
queue.add(10)
queue.add(15)
queue.add(50)
queue.remove()
queue.add(55)
queue.veiw()
queue.remove()
queue.remove()
queue.veiw()
queue.remove()
queue.remove()
queue.add(10)
queue.veiw()
'''
'''
stack=Stack()
stack.__init__(10)
stack.push(5)
stack.push(10)
stack.push(20)
stack.push(30,2)
stack.push(50,1)
stack.push(8,1)
stack.view()
stack.pop()
stack.pop()
stack.pop()
stack.view()
stack.stack
'''


        
















            
            
                
