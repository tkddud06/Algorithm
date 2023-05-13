# 1011번
# 대칭 느낌이겠는데?
# 짝수면 2분의1해서 1이 차인 등차수열이라치고 그만큼 가는거 세면 되고
# 홀수면 짝수 최대항 + 하나더 해서 하면 될듯?
# 이라 생각했는데 안될거 같다

# 1 : 1, 2 : 11 , 3: 111, 4:121, 5:1211 or 1121 , 6 : 1221, 7: 12211or 11221, 8 : 12221, 9: 12321
# 영향을 주는 범위는 16, 4제곱수라 치면 13~20까지. 4가 영향주는 범위.
# 9라치면 7부터 12
# 1234321
# 최댓값이 루트m에 floor한거네
#
# import sys
#
# t = int(sys.stdin.readline().strip())
# for i in range(t):
#     x, y = map(int, sys.stdin.readline().strip().split())
#     km = y-x
#     if km % 2 == 0:
#         km = km / 2
#         conut = 0
#         km =
#         while


# 문제 1085번
# 무조건 수직 수평 단일로 움직이는게, 대각선보다 최소가 나옴.
# 대충생각해봐도 나오고, 피타고라스 공식만봐도 x나 y만 움직이는게.. 두개다 움직이는거보단..

# import sys
#
# x,y,w,h = map(int,sys.stdin.readline().strip().split())
#
# m = []
# m.append(x)
# m.append(y)
# m.append(w-x)
# m.append(h-y)
#
# print(min(m))

# 문제 1149

# 문제 4948번
# 에라토스테네스의 체 사용

#
# import sys
# import math
#
# sosu = [1 for i in range(123456*2+1)]
# sosu[0] = sosu[1] = 0
# for i in range(2,int(math.sqrt(123456*2))+1):
#     if sosu[i]==1:
#         for j in range(i*i,123456*2+1,i):
#             sosu[j] = 0
# t = int(sys.stdin.readline().strip())
# while(t):
#     count = 0
#     for i in range(t+1,(2*t)+1):
#         if(sosu[i]):
#             count += 1
#     print(count)
#     t = int(sys.stdin.readline().strip())


# 문제 6588번
# 소수 리스트에서, 가장 작은거 + 가장 큰거해보고, 그다음으로 큰거 해보고, 그러다가 둘 더한게 본수보다 작아지면
# 가장 작은거 다음으로 넘기고 반복.

import sys
import math

sosu = [1 for i in range(1000001)]

sosu[0] = sosu[1] = 0

for i in range(2,int(math.sqrt(1000001)+1)):
    if sosu[i]:
        for j in range(i*i,1000001,i):
            sosu[j] = 0
sosu[2] = 0
#sosu_list = [i for i in range(1000001) if sosu[i]]
# print(sosu_list)

# 소수 리스트에서, 가장 작은거 + 가장 큰거해보고, 그다음으로 큰거 해보고, 그러다가 둘 더한게 본수보다 작아지면
# 가장 작은거 다음으로 넘기고 반복.

t = int(sys.stdin.readline().strip())
while(t):
    goldwrongcheck = 1
    check = 1
    x = y = 0
    for i in range(3, 1000001):
        if sosu[i] == 0:
            pass
        elif check == 0:
            break
        for j in range(1000000,-1,-1):
            if sosu[j] == 0:
                pass
            elif i+j > t:
                pass
            elif i+j == t:
                x = i
                y = j
                check = 0
                break
            elif i+j < t:
                break
        if i > t/2:
            goldwrongcheck = 0
            break
    if(goldwrongcheck == 1):
        print(f"{t} = {x} + {y}")
    else:
        print("Goldbach's conjecture is wrong.")

    t = int(sys.stdin.readline().strip())

# 아, 차라리 아래쪽것만 가지고 t에서 빼보고, 걔가 소수 리스트에 속하는지 보는식으로 하면 훨씬 빠르고 간단해지겠네.