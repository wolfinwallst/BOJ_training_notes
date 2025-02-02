# 25304 영수증_반복문
x = int(input())
n = int(input())

sum = 0
for i in range(n):
    a, b = map(int, input().split())
    sum += (a * b)

print("Yes" if sum == x else "No")

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 25304 영수증_반복문
x = int(input())
n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    x -= (a * b)

print("Yes" if x == 0 else "No")