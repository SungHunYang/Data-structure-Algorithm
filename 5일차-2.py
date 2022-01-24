#스택 LIFO (나중에 들어온게 LI , 먼저나감 FO)
class Stack:
    # stack 클래스가 생성될 때 생성자 __init__로 스택의 크기가 전달 되면 전달된 크기 만큼의 기억공간을
    # 가지는 스택을 생성하고, 크기를 전달 받지 못하면 기본값(디폴트값) 으로 5개의 데이터를 저장
    # 할 수있는 스택을 만든다 => 디폴트 인수를 사용한다.
    def __init__(self, size = 5): # 클래스에서 함수를 만들 때 self는 반드시 적어야 한다. 근데 이게 사실
                                        # 자기 자신을 받는 변수가 필요한 거라 무조건 self일 필요 없다. 
        print('Stack 클래스의 생성자가 자동으로 실행됩니다.')  # a=Stack() 객체 선언 방법
        print('Stack 클래스 객체가 생성된 주소 : {}'.format(self))
        # 객체를 만들면 self는 객체의 주소를 받는다.
        print('스택의 크기 : {}'.format(size))
        # 생성자 함수 에서 스택을 만든다.
        # 변수 이름 앞에 'self'가 붙은 변수를 멤버 변수라 부르며 클래스 내부의 모든 메소드에서
        # 사용 할 수있고, 'self'가 붙지 않은 변수를 지역 변수라 부르며 변수가 선언된 함수 내부에서만 사용 가능
        self.stack=[] # stack => 빈 리스트 => 빈 리스트에 데이터는 append() 메소드로 추가한다.
        self.size = size # 스택의 크기
        self.top = 0 # 이게 스택 위치를 나타내는 거 top, sp(stack pointer) 라고 불린다.
        # 스택에 몇개의 데이터가 저장되어있나 기억한다. 데이터 입력 +1 출력 -1

    # push => 데이터 입력 함수
    def push(self,data):
        if data not in self.stack : # not in 은 self.stack에 없다는 뜻
            # 스택에 추가하려는 데이터가 스택에 존재하지 않는가?
            # overflow 검사
            # 스택의 크기(self.size)가 5일 때 스택으로 사용할 리스트의 인덱스(top)는 0~4만 사용할 수 있다.
            if self.size > self.top :
                # 오버플로우가 아닐때
                self.stack.append(data)
                self.top+=1
            else :
                # 오버 플로우
                print('스택이 가득 찼습니다 overflow -> {} 넣을 수 없습니다.'.format(data))
        else : # 중복된 값
            print('{} : 중복된 값 입니다.'.format(data))
        #underflow 인가 검사한다.
        if self.top <=0:
            # 스택에 저장된 데이터가 없으므로 없다고 출력한다.
            print('저장된 데이터 없음')
        else :
            # 스택에 저장된 데이터의 개수만큼 반복하며 스택에 저장된 데이터를 출력한다.
            print('push :: stack = [ ',end=' ')
            for i in range(self.top):
                print(self.stack[i], end=' ')
            print(' ]')
        # 아니면 볼 때 self.view()를 넣어도 된다.
        # 현재 클래스의 다른 함수를 실행 할 때는 반드시 앞에 self를 붙여서 실행한다.
    # pop => 데이터 출력 함수
    def pop(self):
        #underflow 검사
        if self.top<=0:
            print('스택에 저장된 데이터가 없습니다.')
        else:
            # pop 메소드를 사용해서 리스트 제거한다.
            # 스택으로 사용하는 리스트의 마지막 인덱스 위치의 데이터를 얻어와서 data 변수에
            # 저장한 후 제거한다.
            data=self.stack.pop() # 가장 끝에 있는 값이 빠져나가면서 삭제
            # 스택에 저장된 데이터가 출력 되었으므로 top 감소
            self.top-=1
            print('pop :: stack = [ ',end=' ')
            for i in range(self.top):
                print(self.stack[i], end=' ')
            print(' ]')    
    # view => 데이터 보는 함수
    def view(self):
        if self.top <=0:
            # 스택에 저장된 데이터가 없으므로 없다고 출력한다.
            print('저장된 데이터 없음')
        else:
            # 스택에 저장된 데이터의 개수만큼 반복하며 스택에 저장된 데이터를 출력한다.
            print('view :: stack = [ ',end=' ')
            for i in range(self.top):
                print(self.stack[i], end=' ')
            print(' ]')


sta=Stack()
sta.push(100)
sta.push(200)
sta.push(300)
sta.push(300)
sta.push(400)
sta.pop()
sta.push(500)
sta.push(600)
sta.pop()
sta.push(700)
sta.push(800)
sta.view()
sta.push(900)
sta.pop()
sta.pop()
sta.pop()
sta.pop()
sta.pop()


















        
        
