"""
def factorial(N): # 팩토리얼 일반 함수 사용
    fact = 1
    for s in range(1,N+1):
        fact*=s
    return fact

number=int(input('숫자입력 : '))
fact=factorial(number)
print("팩토리얼 결과 값 :",fact)
print("{} factorial ={}".format(number,fact))
"""
"""
def factorial_re(N): # 재귀함수
    if N==1:
        return 1
    return N*factorial_re(N-1)
#함수 실행 순서 --> 5넘어 오면 factorial_re(N-1)함수 찾으러 간다.
number=int(input('숫자입력 : '))
fact=factorial_re(number)
print("팩토리얼 결과 값 :",fact)
print("{} factorial ={}".format(number,fact))
"""




















