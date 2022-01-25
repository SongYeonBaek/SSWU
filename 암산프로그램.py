question = int(input("암산 능력 강화 프로그램 입니다. \n연습할 문제의 갯수를 입력하시오 :"))
print(" \n ")
import time
s = time.time()
right = 0
for x in range(question):
    import random
    x = random.randint(1,99)
    y = random.randint(1,99)
    z = random.randint(1,3)

    if z == 1:
        print(x,"+",y,"= ?")
        u_answer = int(input('정답: '))
        r_answer = x + y
    elif z ==2 :
        print(x,"-",y,"= ?")
        u_answer = int(input('정답: '))
        r_answer = x - y
    else :
        print(x,"*",y,"= ?")
        u_answer = int(input('정답: ' ))
        r_answer = x* y


    if u_answer == r_answer:
        print(" 정답입니다.\n")
        right += 1
    else :
        print(" 오답입니다.  답은: ", r_answer, "입니다.\n")

   

e = time.time()
print(" 총  ",question, " 문제 중", right, "문제를 맞추셨습니다.")
print(" 총 ", int(e-s)," 초 걸렸습니다.")
print(" 수고하셨습니다.")
        