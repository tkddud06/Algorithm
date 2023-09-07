#
# # 백준 1018번
#
# import sys
#
# n, m = map(int, sys.stdin.readline().strip().split()) # m이 가로
#
# matrix = []
# for i in range(n):
#     matrix.append(" ".join(sys.stdin.readline().strip()).split(' '))
#
# w_matrix = [['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']]
# b_matrix = [['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']]
#
#
# min_count = 2500
# for i in range(n-7) :
#     for j in range(m-7) :
#         temp_count = 0
#         p = q = 0
#         for x in range(i,i+8):
#             for y in range(j,j+8):
#                 if matrix[x][y] != w_matrix[p][q]:
#                     temp_count += 1
#                 q += 1
#             q = 0
#             p += 1
#
#         if temp_count < min_count:
#             min_count = temp_count
#
#         temp_count = 0
#         p = q = 0
#
#         for x in range(i, i + 8):
#             for y in range(j, j + 8):
#                 if matrix[x][y] != b_matrix[p][q]:
#                     temp_count += 1
#                 q += 1
#             q = 0
#             p += 1
#
#         if temp_count < min_count:
#             min_count = temp_count
#
# print(min_count)
#
#
#
# # 조금 복잡하게 풀었다. 추후에 다른사람들 푼것 보고 수정해 보자.




# # 백준 1181번
#
# import sys
#
# n = int(sys.stdin.readline().strip())
# data = []
# for i in range(n):
#     data.append(sys.stdin.readline().strip())
#
# data = set(data)
# data = list(data)
# data.sort()
# sorted_data = []
# for i in range(1,51):
#     for d in data:
#         if len(d) == i:
#             sorted_data.append(d)
# print(*sorted_data, sep='\n')
#
# # 마찬가지로, 비효율적으로 푼 것 같다. 추후 수정해 보자.


# # 백준 1436번
#
# #666 1666 2666 3666 /// 10666 11666 12666 /// 16660 16661 ///
# #20666 21666 // 26660 26661 // 30.... //// 99666 100666
# # 0 1 2 3 4 5 6 7 8 9 10 처럼 순서대로 증가하는데,
# # 각 수를 양쪽으로 붙여보면 되겠네.
# # 666이라 생각 안하고, 임의의 'z' 라고 생각해보고
# # 해당 수에 붙이는거지 저 수들을
# # 6미만일땐 앞쪽 우선, 0z 1z 2z 3z 4z 5z 6z , z0 z1 z2 z3 z4 z5 z6
# # 7이상일땐 뒤쪽 우선. z7 z8 z9 7z 8z 9z 10z 11z 12z 13z 14z 15z 16z 1z0 1z2 1z3 1z4 1z5 1z7 1z8 1z9 17z 18z 1z9 20z
# # 자리수 넘어가면 다시 앞으로
#
# # 아, 모르겠다. 2초안엔 될거같으니 세보자!
#
# import sys
#
# n = int(sys.stdin.readline().strip())
#
# i = 0
# temp_ans = 0
# num = 666
# while (1):
#     if (i == n):
#         print(temp_ans)
#         break
#     str_num = str(num)
#     if "666" in str_num:
#         i += 1
#         temp_ans = str_num
#     num += 1
#
# # 비슷함. 훨씬 더 효율적으로 될 거 같은데.. 한번 찾아보자 나중에



# # 백준 11866번
#
# import sys
#
# n, k = map(int, sys.stdin.readline().strip().split())
# list = []
# for i in range(1,n+1):
#     list.append(i)
#
# index = 0
# newlist = []
# while len(list) != 0:
# #    if index >= len(list):
# #        index %= len(list) # 빼도 무방. 더하고 나눠주나, 나눠주고 빼나 상관 없음.
#     index += k-1
#     if index >= len(list):
#         index %= len(list)
#     newlist.append(list[index])
#     list.remove(list[index])
# print("<", end = "")
# print(*newlist,sep=", ", end = "")
# print(">")
# # 1 2 3 4
#
# # 1 2 3 4 5 6 7
# # 1 2 4 5 6 7
# # 1 2 4 5 7
# # 1 4 5 7
# # 1 4 5
# # 뒤에것이 무조건 내려옴




# 백준 18111번

# 최소 시간과 높이 블록을 까는건 1초, 캐는건 2초
# 까는게 빠르니, 높은 것이 빠를 가능성이 높음
# 최대 높이 기준으로, 충족하는지 한칸씩 내려가며 체크
# 모든 칸을 대상으로 해당 높이를 충족하기 위한 갯수 합차를 구함 (더깔아야한다면 +가 나오고, 캐야된다면 -가 나오겠지)
# 각각 +면 1초 계산, -면 2초 계산 후, 그거 안하고 갯수로 sum 구한거에 B 더해서 양수로 충족되는지 확인
# 안된다면 내려감
# 이렇게 하나하나 다 체크하면 답은 나올텐데 1초에 안 될거 같은데.

# 현재 깔려 있는 전체 개수 + B를 더해서, 가능한 가장 높은 높이 구함
# 해당 높이를 기준으로 내려가며 하나하나 해봄
# 시간이 점점 줄어든다면 진행, 늘어나는 양상을 띈다면 정지

import heapq
# heapq.메소드 방식으로 리스트에 꽂아서 사용 가능

from collections import Counter
# Counter(리스트 등) 함수로 사용 가능
# Conuter 객체로 result 나오는데
# dict처럼 접근 되고, dict 함수 통해 바꿀수 있음.

from collections import deque
# deque는 리스트랑 비슷하게 사용 가능
# 일정 변수를 deque로 만들수 있음

from itertools import permutations # 순서 상관있게 뽑기
from itertools import combinations # 순서 상관없이 뽑기
from itertools import product # 순서 상관있게 중복으로 뽑기
from itertools import combinations_with_replacement # 순서 상관없이 중복으로 뽑기


listd = [1,2,3,4]

print(list(permutations(listd,2)))
print(list(combinations(listd,2)))
print(list(product(listd,repeat=2)))
print(list(combinations_with_replacement(listd,2)))


from bisect import bisect_left, bisect_right

array = [1,2,3,4,7,8]

x= 4

# print(bisect_left(array,x)) # x값 포함하는 맨 왼쪽 인덱스 출력
# print(bisect_right(array,x)) # x값 배제하는 첫번째 오른쪽 인덱스 출력
#
# import math
#
# sum()
# min()
# max()
#
# eval() # 입력값대로 작동
#
# math.gcd() # 최대공약수
# math.lcm() # 최소공배수

a, *b = [1,2,3,4,5] # 첫번째꺼, + 나머지. 반대도 가능
*d, h = [1,2,3,4,5]

print(a,b)
print(d,h)

# 시퀀스 슬라이스, 건너뛰며 슬라이스, 뒤부터 -1로 접근 등이 됨을 알아두기.

# abs, pow 함수. abs는 절대값, pow는 n제곱

#math.ceil
#math.floor ceil은 올려치기, floor은 내려치기
#print(round(13.5)) 반올림

# enumerate(리스트) 박으면 (index, 원소) 튜플로 내보내줌

# zip 튜플로 각 인덱스 원소들 동일인덱스에 묶기

# all(c), c안에 포함된것 모두 true면 true
# any(c) , 하나라도 true면 true
# sorted 정렬된거 내보내주는 함수
# reversed 뒤집어진거 내보내주는 함수
# c.index(a) a인덱스위치 c.count(a) c안의 a개수
# c*5, c 5번 복사 c+c2 둘이 합침

import copy
# c.copy와 c.deepcopy.

# find, index 차이 보기
# 리스트 딕셔너리 스트링 셋 관련 함수 더 보기