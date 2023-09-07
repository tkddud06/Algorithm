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

#
# # 문제 6588번 ////////////// 진행중
# # 소수 리스트에서, 가장 작은거 + 가장 큰거해보고, 그다음으로 큰거 해보고, 그러다가 둘 더한게 본수보다 작아지면
# # 가장 작은거 다음으로 넘기고 반복.
#
# import sys
# import math
#
# sosu = [1 for i in range(1000001)]
#
# sosu[0] = sosu[1] = 0
#
# for i in range(2,int(math.sqrt(1000001)+1)):
#     if sosu[i]:
#         for j in range(i*i,1000001,i):
#             sosu[j] = 0
# sosu[2] = 0
# #sosu_list = [i for i in range(1000001) if sosu[i]]
# # print(sosu_list)
#
# # 소수 리스트에서, 가장 작은거 + 가장 큰거해보고, 그다음으로 큰거 해보고, 그러다가 둘 더한게 본수보다 작아지면
# # 가장 작은거 다음으로 넘기고 반복.
#
# t = int(sys.stdin.readline().strip())
# while(t):
#     goldwrongcheck = 1
#     check = 1
#     x = y = 0
#     for i in range(3, 1000001):
#         if sosu[i] == 0:
#             pass
#         elif check == 0:
#             break
#         for j in range(1000000,-1,-1):
#             if sosu[j] == 0:
#                 pass
#             elif i+j > t:
#                 pass
#             elif i+j == t:
#                 x = i
#                 y = j
#                 check = 0
#                 break
#             elif i+j < t:
#                 break
#         if i > t/2:
#             goldwrongcheck = 0
#             break
#     if(goldwrongcheck == 1):
#         print(f"{t} = {x} + {y}")
#     else:
#         print("Goldbach's conjecture is wrong.")
#
#     t = int(sys.stdin.readline().strip())

# 아, 차라리 아래쪽것만 가지고 t에서 빼보고, 걔가 소수 리스트에 속하는지 보는식으로 하면 훨씬 빠르고 간단해지겠네.


# 백준 문제 7568
# 키, 몸무게가 둘다 크다면 더 크다
# 둘중 하나만 크다면 판단 불가

# 둘다 차이가 일정하게 난다면
# 키와 몸무게 따로 정렬해도
# 순위가 정해지겠지.
# 1,2,3 이런식으로.
# 만약 그렇지 않고, 모호하게 섞이는 얘들은
# 동순위로 치면 됨.
#

# 이런식으론 접근이 어려울 거 같은데...
# 섞이지 않아도 그런 경우가 있어.

# 뽑은 쌍의 데이터를 각각 저장한다
# 순위를 매긴다. 둘다 크다면 큰걸로.
# 그렇지 않다면 작은 순위로.
# 만약 애매하게 나왔다면, 둘중 작은 값을 저장해준다.
# 새로 나온 쌍이 둘다 작다면, 낮은 순위로 지정한다.


# 1. 0,1인덱스 비교시 크므로 1순위, 2순위 지정
# 2. 1,2인덱스 비교시 애매하므로 58, 175 저장후 넘어감(2순위 지정. 순위유지)
# 3.

# 지금 보니까, 그냥 한 데이터 기준으로 정렬 때리고, 다른 데이터로는 수동으로 비교하면서, 더 작다고 나오는경우만 순위 높여주고, 아니면 유지하면 되는거 아닌가?

import sys

# n = int(sys.stdin.readline().strip())
#
# classic_datalist = []
# grade_list = [0 for i in range(n)]
# datalist = []
# for i in range(n):
#     x, y = map(int, sys.stdin.readline().strip().split())
#     classic_datalist.append((x,y))
#     datalist.append((x, y))
#
# datalist.sort(reverse=True)
# grade = 1
#
# grade_list[classic_datalist.index(datalist[0])] = 1
# classic_datalist[classic_datalist.index(datalist[0])] = -1
#
# for i in range(1, n):
#     if datalist[i-1][0] > datalist[i][0] and datalist[i-1][1] > datalist[i][1]:
#         grade = i+1
#         grade_list[classic_datalist.index(datalist[i])] = grade
#         classic_datalist[classic_datalist.index(datalist[i])] = -1
#     else:
#         grade_list[classic_datalist.index(datalist[i])] = grade
#         classic_datalist[classic_datalist.index(datalist[i])] = -1
# # 88 60 58 55 46
# # 186 175 183 185 155
# print(*grade_list)

n = int(sys.stdin.readline().strip())
datalist = []
grade = [1 for i in range(n)]
for i in range(n):
     x, y = map(int, sys.stdin.readline().strip().split())
     datalist.append((x,y))
for i in range(n):
    for j in range(i+1, n):
        if datalist[i][0] < datalist[j][0] and datalist[i][1] < datalist[j][1]:
            grade[i] += 1
        elif datalist[i][0] > datalist[j][0] and datalist[i][1] > datalist[j][1]:
            grade[j] += 1 

print(*grade)

# 사실 별개 아니고, 대진표같은 느낌이라고 생각하면 됨. 개수가 매우 작잖아, 그럼 이런걸 생각해봐야지.
# 서로 뜨게 시켜서, 덩치가 작은 쪽에 순위를 뒤로 미뤄주는거지.
# 등수나 순서라고 해서, 무조건 정렬 박는게 아니다...
# 결국 싸울 횟수와 사람은 입력값에 따라 고정치로 정해져 있으니, 각 사람의 승패의 횟수가 등수를 결정짓는거지. 패배의 횟수+1이 직접적으로 순위를 표현하고.