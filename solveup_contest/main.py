# n = int(input())
# # 가위는 0 바위는 1 보는 2
# for i in range(1,n+1):
#     a,b = map(int,input().split())
#     a -= 1
#     b -= 1
#     if (a + 1)%3 == b:
#         print(f"#{i} B")
#     else:
#         print(f"#{i} A")

# s = input()
# print(s.upper())

# N = 과목수
# Ai = 과목별 인원수
# B = 과목별 기본 최대 감당 인원수
# C = 조교 1명이 추가로 감당할 수 있는 인원수.

# 각 과목별 기본 교수 1명

# 과목별 인원 1 + Ai + (if Ai > B면 temp에 B-Ai 저장, C씩 뺴며 과목별 인원에 1 +)

# n = int(input())
# a = list(map(int, input().split()))
# b, c = map(int,input().split())
#
# all = 0
# for i in range(n):
#     all += 1
#     if a[i] > b:
#         temp = a[i]-b
#         while(temp > 0):
#             temp -= c
#             all += 1
# print(all)


# 기본 부품(쪼개기 x) 중간 부품(쪼개기 가능, 기본or중간더함) 으로 장난감 만듬
# 관계를 줄테니, 기본부품 사용수 뽑아내라

# n, n번이 완제품, n-1번까지가 기본부품 및 중간부품
# M, M은 관계도의 수
# X Y K, X를 만드는데 Y가 K개 필요함

# n, k = map(int,input().split())
# n = pow(n,k)
# print(n%20091024)
#
# import sys
#
# n = int(input())
# m = int(input())
# middle_set = set()
# inst = []
# inst_what = []
# for i in range(m):
#     x,y,k = map(int,sys.stdin.readline().strip().split())
#     middle_set.add(x)
#     inst_what.append(x)
#     inst.append((x,y,k))
#
# middle_how = list(middle_set)
# middle_how.sort(reverse=True)
# middle_how_backup = middle_how.copy()
# made = {}
# for i in range(1,n+1):
#     made[i] = 0
# while len(middle_how):
#     i = middle_how[0]
#     middle_how.pop(0) # 777 이 있을때 두번쨰꺼가 가장 큰거에 참조하도록
#     inst_temp = []
#     while 1:
#         try:
#             inst_temp.append(inst[inst_what.index(i)])
#         except:
#             break
#         inst.pop(inst_what.index(i))
#         inst_what.remove(i)
#     inst_tempd = list(sorted(inst_temp, key=lambda z: z[1], reverse=True))
#     while inst_tempd:
#         if made[inst_tempd[0][0]] > 0:
#             made[inst_tempd[0][1]] += made[inst_tempd[0][0]] * inst_tempd[0][2]
#             inst_tempd.pop(0)
#         else:
#             made[inst_tempd[0][1]] += inst_tempd[0][2]
#             inst_tempd.pop(0)
#
# ma = min(middle_how_backup)
# for i in range(1,ma):
#     print(f"{i} {made[i]}")

from collections import deque

n , k = map(int,input().split())

a = deque()
a.extend(list(map(int,input().split())))

man_list = [0 for i in range(n)]

man_list = deque(man_list)

i = 0
while a.count(0) < k:
    i += 1
    a.rotate(1)
    man_list.rotate(1)
    if a[0] > 0:
        man_list[0] = 1
        a[0] -= 1
    man_list[n-1] = 0
    for i in range(n-2,0, -1):
        if a[i] > 0 and man_list[i+1] == 0 and man_list[i-1] == 1:
            man_list[i] = 1
            man_list[i-1] = 0
            a[i] -= 1
print(i)