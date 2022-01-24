'''
진법 변환
'''
num=int(input('10진수 입력 : '))
print()

def change(num):
    nd2=[]
    nd8=[]
    nd16=[]
    a,b,c=num,num,num
    while a != 0:
        nd2.append(a%2)
        a = a//2
    print('2진수 : [ ',end='')
    #이렇게도 출력가능
    # 1. print(nd2[::-1])
    # 2. nd2.reverse() --> print(nd2)
    for i in range(len(nd2)-1,-1,-1):
        print(nd2[i],end=' ')
    print(']')
    print()

    while b != 0:
        nd8.append(b%8)
        b = b//8
    print('8진수 : [ ',end='')
    for i in range(len(nd8)-1,-1,-1):
        print(nd8[i],end=' ')
    print(']')
    print()

    while c != 0:
        nd16.append(c%16)
        c = c//16
    print('16진수 : [ ',end='')
    for i in range(len(nd16)-1,-1,-1):
        if nd16[i]>9:
            print(chr(65+(nd16[i]-10)),end=' ')
        else :
            print(nd16[i],end=' ')
    print(']')
    print()
    # for문 간략화 하는법 3항연산
    '''
    for i in range(len(nd16)-1,-1,-1):
       print(nd16[i] if nd16[i]<10 else chr(convert[i] + 55),end=' ')
    '''

change(num)

# 다른 방법
convert=[]
# 16진수를 기억하는 리스트를 만든다.
hex_16 =['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']

while True:
    m=num // 16
    r= num%16
    convert.append(hex_16[r])
    if m == 0:
        break
    num = m
for i in range(len(convert)-1,-1,-1):
    print(convert[i],end=' ')







