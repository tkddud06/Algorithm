# n개의 동전으로 k원 만들건데
# 해당 가치들로 그거 만들수 있는 경우의 수 몇개?

# 각각의 동전은 몇 개라도 사용할 수 있다.

# 스택에 큰거부터 쌓는데, k보다 커지면 다시 빼고

# 가장 큰 가치로 나누기 해서 최대 사용 횟수 뽑아님.

# dp

n,k = map(int,input().split())
data = [[0 for i in range(k+1)] for j in range(2)]
money = []
for i in range(n):
    money.append(int(input()))
money.sort()
for i in money:
    for j in range(1, k+1):
        if j-i > 0:
            data[1][j] += data[0][j-i]
        if j % i == 0:
            data[1][j] += 1
    data[0] = data[1].copy() # copy 안써주면 정말 같은것으로 취급됨
print(data[0][k])

# 2164번 수식으로 보면, 홀수만 다 버리는 방식으로도 구현 가능.