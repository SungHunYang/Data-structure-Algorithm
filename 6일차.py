#linkedList에 저장될 데이터를 기억하는 클래스 => 노드
class Node:
    def __init__(self, data=None):
        self.data = data # 실제 데이터
        self.next = None # 다음 데이터의 위치(주소)

# linkedList 자체를 의미하는 클래
class LinkedList:
    def __init__ (self):
        self.head = None #linkedList의 시작 위치
        self.count = 0 # linkedList의 저장된 데이터의 개수

    # linkedList에 데이터를 입력하는 경우의 수는 모두 3가지가 있다.
    # 1. linkedList의 맨 뒤에 데이터를 추가하는 경우
    # 2. linkedList의 맨 앞(head 다음)에 데이터를 추가하는 경우
    # 3. linkedList의 맨 앞과 맨 뒤를 제외한 특정 위치에 데이터를 삽입하는 경우

     # 1. linkedList의 맨 뒤에 데이터를 추가하는 메서드
    def appendLast(self, data):
         #linkedList의 맨 뒤에 추가할 데이터를 넘겨 받아 Node(linkedList에 저장할 데이터) 클래스 객체를 만든다.
        newNode = Node(data)
        #linkedList에 저장된 데이터의 개수를 증가시킨다.
        self.count += 1
        print(newNode)
        #linkedList가 비어있을 경우와 비어있지 않을 경우에 따라서 linkedList에 데이터를 추가하는 방법이 다르다.

        #linkedList가 비어있나 물어봐서 비어있으면 head 바로 다음에 추가한다.
        if self.head is None:
            # linkedList가 비어있으므로 head 다음에 데이터를 넣어준다. =>head에 newNode가 메모리에 생선된 주소를 넣는다.
            self.head = newNode
            # 데이터를 head 다음 위치에 추가했으므로 메소드를 return 시켜서 종료한다.
            return

        #linkedList가 비어있지 않다면 linkedList에 저장된 데이터가 있다는 것 이므로 LinkedList의 마지막으로 이동
        #한 후에 데이터를 추가한다.
        #linkedList의 시작 위치를 정한다.
        start = self.head
        # head부터 시작 해서 linkedList의 마지막 데이터로 이동한다. =>마지막 데이터는 next에 None이 저장되어있다.
        # start.data는 현재 데이터를 의미하고 start.next는 다음 데이터가 저장된 주소를 의미한다.
        # start.next에 저장된 값이 None이 아니면 True, None이면 False가 된다.
        while start.next: # linkedList에 저장된 다음 데이터가 있는가?
            start = start.next
        # 더 이상 다음 데이터가 없으면 현재 데이터가 마지막 데이터 이므로 현재 데이터 다음에 새 데이터를 추가한다.
        start.next = newNode
            
    # 2. linkedList의 맨 앞(head 다음)에 데이터를 추가하는 경우
    def insertFirst(self,data):
        newNode = Node(data)
        self.count += 1
        print(newNode)
        #linkedList의 맨 뒤에 데이터를 추가하는 경우를 제외한 나머지 경우는 데이터를 추가 할 때 순서를 반드시
        #지켜야 함
        #추가할 데이터(newNode)의 다음 데이터를 기억하는 next에 이전 데이터의 next에 저장된 값(다음 데이터의 주소)dmf
        #넣어준다.
        #맨 앞에 추가할 때는 다음 데이터를 기억하는 next에 head에 저장된 값을 넣어준다.
        newNode.next = self.head
        #head에는 새로 삽입되는 데이터 추가
        self.head = newNode
        
    # 3. linkedList의 맨 앞과 맨 뒤를 제외한 특정 위치에 데이터를 삽입하는 경우
    def insertPosition(self, position, data):
        # 데이터가 삽입될 위치가 올바른가 검사한다. => 올바른 위치가 아니면 메시지를 표시하고 메소드를 종료
        if position <1 or position > self.count - 1:
            print('{}번째 위치는 {} 데이터가 삽입될 위치로 올바르지 않습니다.'.format(position, data))
            return

        #데이터가 삽입될 위치가 올바르므로 position위치에 데이터를 삽입
        newNode = Node(data)
        self.count += 1
        print(newNode)

        #바로 전 위치를 찾는다. => 반복은 postion -1만큼 시킨다.
        start = self.head
        for i in range(position - 1):
            start = start.next
        #데이터가 삽입될 위치를 찾았으므로 넣는다.
        newNode.next = start.next
        start.next = newNode

    # linkedList에 저장된 모든 데이터를 출력하는 메소드
    def listPrint(self):
        #linkedList의 시작 위치를 저장한다.
        start = self.head
        #linkedList가 비어있나 확인
        if start is None:
            print('출력-[ List가 비어있음 ]')
            return
        else:
            print('LinkedList에 저장된 데이터가[',self.count,'] 개있습니다')
            print('[ ',end='')
            for i in range(self.count):
                print(start.data, end=' ')
                # 다음에 출력할 데이터로 접근한다.
                start = start.next
            print(']')

    # linkedList에 저장된 데디터를 찾아서 제거하는 메소드
    def remove(self,data):
        #linkedList의 시작 위치를 지정한다.
        start = self.head
        #linkedList가 비어있나 확인
        if start is None:
            print('삭제-[ List가 비어있음 ]')
        else:
            # 데이터를 찾아서 제거한다.
            # 제거할 데이터가 0번째 index의 데이터일 경우
            if start.data == data:
                # 1번째 index의 데이터 위치를 head에 넣어준다.
                self.head = start.next
                self.count -=1
                # 이거 왜 필요한가 싶었는데 1번째는 prev가 head가 되버리기 때문에 이거 한거다.
                return
        #제거할 데이터가 1번째 index이후 일 경우 데이터를 제거
            while start is not None:
                if start.data == data : #제거할 데이터를 찾았는가?
                    break                   # 제거할 데이터를 찾았으므로 루프를 탈출한다,
                prev = start                #삭제할 데이터의 전 데이터를 기억한다.
                start = start.next
                
            # 여기 까지 왔다는건 데이터를 찾아서 break로 왔거나(prev.next로) //못찾아서 while문을 끝내고 바로 넘어온 경우다.(if start == None)
            
            if start == None: # 삭제할 데이터를 찾지 못함
                print('{}는 리스트에 존재하지 않는 데이터'.format(data))
                return

            #데이터를 찾았으므로 데이터를 삭제한다.
            prev.next = start.next
            self.count -= 1


print('linkedList를 만든다')
linkedList = LinkedList() #linkedList를 막 만들었으므로 비어있는 linkedList 이다.
linkedList.listPrint()
linkedList.remove('홍길동')
print('linkedList의 head 다음에 데이터를 추가 한다.')
linkedList.appendLast('홍길동')
print('='*20)
print('linkedList의 맨 뒤에 추가 한다.')
linkedList.appendLast('임꺽정')
linkedList.appendLast('장길산')
linkedList.listPrint()
print()
print('='*20)
print('linkedList의 맨 앞에 데이터를 삽입한다.')
linkedList.insertFirst('일지매')
linkedList.listPrint()
print()
print('='*20)
print('linkedList의 맨 앞과 맨 뒤를 제외한 위치에 데이터를 삽입한다.')
linkedList.insertPosition(0, '손오공')
linkedList.insertPosition(4, '저팔계')
linkedList.listPrint()
linkedList.insertPosition(2, '진모리')
linkedList.listPrint()
print('='*20)
print('linkedList의 index가 0인 데이터를 제거')
linkedList.remove('일지매')
linkedList.listPrint()
print('='*20)
print('linkedList의 index가 1이후인 데이터의 index를  제거')
linkedList.remove('임꺽정')
linkedList.listPrint()
