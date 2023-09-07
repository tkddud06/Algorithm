# 백준 2293번

# n개의 동전으로 k원 만들건데
# 해당 가치들로 그거 만들수 있는 경우의 수 몇개?

# 각각의 동전은 몇 개라도 사용할 수 있다.

# 스택에 큰거부터 쌓는데, k보다 커지면 다시 빼고

# 가장 큰 가치로 나누기 해서 최대 사용 횟수 뽑아님.
# 위 방법보다는 dp가 정석적인 풀이방법인 듯.
# dp

#
# n,k = map(int,input().split())
# data = [[0 for i in range(k+1)] for j in range(2)]
# money = []
# for i in range(n):
#     money.append(int(input()))
# money.sort()
# for i in money:
#     for j in range(1, k+1):
#         if j-i > 0:
#             data[1][j] += data[0][j-i]
#         if j % i == 0:
#             data[1][j] += 1
#     data[0] = data[1].copy() # copy 안써주면 정말 같은것으로 취급됨
# print(data[0][k])




# 백준 2164번
# 2164번 수식으로 보면, 홀수만 다 버리는 방식으로도 구현 가능.
# 큐 사용
#
# from collections import deque
# import sys
#
# n = int(sys.stdin.readline().strip())
# list = [i for i in range(1,n+1)]
# list = deque(list)
# while(len(list) != 1):
#     list.popleft()
#     temp = list.popleft()
#     list.append(temp)
# print(list.pop())



# 백준 3896번

# 에라토스테네스의 체 사용
# import math
# import sys
# list = [1 for i in range(1300001)]
# list[0] = list[1] = 0
# for i in range(2,int(math.sqrt(1300000)+1)):
#     if list[i]:
#         for j in range(i*i, 1300001, i):
#             list[j] = 0
# sosu_list = [i for i in range(1300001) if list[i]]
# sosu_set = set(sosu_list)
# n = int(sys.stdin.readline().strip())
# for i in range(n):
#     temp = int(sys.stdin.readline().strip())
#     if temp not in sosu_set:
#         x = 0
#         while list[temp] != 1:
#             temp -= 1
#         x = sosu_list.index(temp) + 1
#         print(sosu_list[x]-sosu_list[x-1])
#     else:
#         print(0)


import math
import sys
list = [1 for i in range(1300001)]
list[0] = list[1] = 0
for i in range(2,int(math.sqrt(1300000)+1)):
    if list[i]:
        for j in range(i*i, 1300001, i):
            list[j] = 0
# sosu_list = [i for i in range(1300001) if list[i]]
# sosu_set = set(sosu_list)
n = int(sys.stdin.readline().strip())
for i in range(n):
    temp = int(sys.stdin.readline().strip())
    if list[temp] != 1:
        temp_left = temp_right = temp
        while list[temp_left] != 1:
            temp_left -= 1
        while list[temp_right] != 1:
            temp_right += 1
        print(temp_right-temp_left)
    else:
        print(0)
# 밑 방식처럼, 1300000개 해당하는걸로 소수리스트 만들지 않고, 그냥 와일문 두번 돌려서 찾는게 훨씬 빠르다.
# 가능하니까, 이렇게 하는게 나을듯.