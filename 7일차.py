class BinaryTree:
    #생성자에서 이진트리의 root 노드를 만든다.
    def __init__(self,data=None):
        self.data = data
        self.left = None #왼쪽 자식 노드의 주소 기억
        self.right = None  #오른쪽 자식 노드의 주소 기억
        
    # 트리에 노드를 삽입하는 메소드
    def insert(self, data):
        # 트리에 삽입할 데이터의 값과 부모 노드의 데이터 값을 비교해서 트리에 데이터를 삽입 할
        # 위치가 결정된다.
        # 트리에 삽입할 데이터가 부모 노드의 데이터보다 작으면 부모 노드의 왼쪽에 삽입
        # 트리에 삽입할 데이터가 부모 노드의 데이터보다 크면 부모 노드의 오른쪽에 삽입
        print('트리에 삽입하려는 데이터 [ {} ] 의 부모 노드는 [ {} ] 입니다.'.format(data,self.data))

        # 삽입하려는 데이터가 부모 데이터보다 작은가?
        if data < self.data:
            # 부모 노드의 왼쪽에 삽입한다.
            print('부모 노드의 데이터가 크기 때문에 왼쪽 노드에 데이터 삽입')
            # 부모 노드의 왼쪽 링크(self.left)가 비어(None)있어야 데이터 삽입가능
            if self.left is None:
                # 부모 노드의 왼쪽 링크가 비어있으므로 데이터를 추가한다.
                # 새 데이터를 추가 해야 하므로 트리에 추가 할 데이터로 BinaryTree 클래스 객체를 생성해서
                # 부모 노드의 비어있는 왼쪽 링크에 생선된 BinaryTree 클래스 객체의 주소를 넣어준다.
                self.left = BinaryTree(data)
                print('부모 ({}) 의 왼쪽에 [ {} ] 추가'.format(self.data,data))
            else:
                # 부모 노드가 비어있지 않기 때문에 데이터 추가 불가.
                print('부모 ({}) 의 왼쪽에 [ {} ] 추가 불가!!'.format(self.data,data),end=' --> ')
                print('따라서 부모 왼쪽 노드 ({}) 에서 insert() 메소드 실행'.format(self.left.data))
                self.left.insert(data) # --> 이게 재귀 호출 식인데 뭔가 반복 해야 할것 같지만
                # 재귀 호출 하면서 알아서 반복을 해준다. 그래서 자동으로 삽입된다.
                
        # 삽입하려는 데이터가 부모 데이터보다 큰가?
        elif data > self.data:
            # 부모 노드의 오른쪽에 삽입한다.
            print('부모 노드의 데이터가 크기 때문에 오른쪽 노드에 데이터 삽입')
            # 부모 노드의 오른쪽 링크(self.right)가 비어(None)있어야 데이터 삽입가능
            if self.right is None:
                # 부모 노드의 오른쪽 링크가 비어있으므로 데이터를 추가한다.
                # 새 데이터를 추가 해야 하므로 트리에 추가 할 데이터로 BinaryTree 클래스 객체를 생성해서
                # 부모 노드의 비어있는 오른쪽 링크에 생선된 BinaryTree 클래스 객체의 주소를 넣어준다.
                self.right = BinaryTree(data)
                print('부모 ({}) 의 오른쪽에 [ {} ] 추가'.format(self.data,data))
            else :
                # 부모 노드가 비어있지 않기 때문에 데이터 추가 불가.
                print('부모 ({}) 의 오른쪽에 [ {} ] 추가 불가!!'.format(self.data,data),end=' --> ')
                print('따라서 부모 오른쪽 노드 ({}) 에서 insert() 메소드 실행'.format(self.right.data))
                self.right.insert(data) # --> 이게 재귀 호출 식인데 뭔가 반복 해야 할것 같지만
                # 재귀 호출 하면서 알아서 반복을 해준다. 그래서 자동으로 삽입된다.
        # 삽입하려는 데이터가 부모와 같은가? 삽입하려는 데이터가 이미 트리에 존재
        else :
            print(data,' -> 이미 트리에 존재하는 데이터 입니다.')
        '''
        이진 트리의 운행(트레이스)은 같은 노드를 중복해서 방문하지 않고 모든 노드를 방문하는 방법
        부모(root) 노드를 언제 방문하느냐에 따라 아래와 같이 3가지 방법이 있다.
        inorder : L -> C -> R
        preorder : C -> L -> R
        postorder : L -> R -> C
        '''
        # inorder
    def inorder(self):
        # 왼쪽 자식 노드가 있나 검사한다. => Link(self.left, self.right)에 주소가 저장되에 있으면 True, 없으면 False
        if self.left : # -> 이렇게 되면 뭐라도 있으면 True 없으면 False 니까 -
            # ->왼쪽에 자식 있으면 왼쪽 자식 가서 또 부른다 이런 식으로 재귀 호출을 불러 버린다.
            self.left.inorder()
        # 더 이상 자식 노드가 없으면 출력한다.
        print(self.data,end=' ')
        # 오른 쪽 자식 노드가 있나 검사한다.
        if self.right:
            self.right.inorder()
    def preorder(self):
        print(self.data,end=' ')
        if self.left : 
            self.left.preorder()
        if self.right:
            self.right.preorder()
    def postorder(self):
        if self.left : 
            self.left.postorder()
        if self.right:
            self.right.postorder()
        print(self.data,end=' ')


# 이진 트리의 root 노드를 만든다.
root = BinaryTree(12)
# 이진 트리에 데이터를 추가한다.
root.insert(12)
print('='*20)
print()
root.insert(6)
print('='*20)
print()
root.insert(20)
print('='*20)
print()
root.insert(3)
print('='*20)
print()
root.insert(25)
print('='*20)
print()
root.insert(10)
print('='*20)
print()
root.insert(15)
print('='*20)
print()

root.preorder()
print()
root.postorder()
print()
root.inorder()
print()


