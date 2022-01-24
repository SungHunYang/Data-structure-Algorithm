'''
유클리드 호제법을 이용한 최대공약수와 최소공배수 계산하기
숫자2개를 입력 받아 큰수와 작은수를 구분한다.
큰수를 작은수로 나눈 나머지가 0이면 작은수가 최대 공약수가 되고 큰수를 작은수로 나눈 나머지가
0이 아니면 큰수를 기억하던 기억장소에 작은수를 넣어주고 작은수를 기억하던 기억장소에 나머지를
넣어준 후 작업을 반복한다.
최대공약수가 계산되면 입력받은 숫자 2개를 곱한 결과를 최대공약수로 나눠주면 최소공배수를 얻을 수있다,
'''
def check(big,small,a,b):
    if big%small != 0:
        big,small=small,(big%small)
        check(big,small,a,b)
    else :
        _min = small
        _max = a*b//small
        print('[ {} ] , [ {} ] -> 최소 공배수 [ {} ] , 최대 공약수[ {} ]'.format(a,b,_max,_min)) 

a, b=map(int, input('값을 넣으세요 : ').split() )# 여러개 데이터 받을 때
#map(원하는 자료형, input().split()) split()으로 나눠서 a,b에 각각 넣어줌

if a >= b :
    big,small = a,b
else:
    small,big = a,b
    
print(big)
print(small)

check(big,small,a,b)

# 무한 반복문 이용법
while True:
    r= big%small # 큰수를 작은수로 나눈 나머지를 계산
    if r == 0: # 무한 루프 종료 조건
        break
    big, small = small, r

print('while 사용 => 최대공약수 : {}, 최소공배수: {}'.format(small,a*b/small))










