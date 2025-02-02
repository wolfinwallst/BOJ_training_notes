# 25314 코딩은 체육과목 입니다_반복문
n = int(input())

for _ in range(n//4):
    print("long", end = " ") # end = " "가 없으면 자동으로 개행

print("int")

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 25314 코딩은 체육과목 입니다_반복문
n = int(input())
print(n//4 * "long " + "int")

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 25314 코딩은 체육과목 입니다_반복문
n = int(input())
print(n//4 * "long ", "int", sep='')

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 25314 코딩은 체육과목 입니다_반복문
n = int(input())
answer = 'int'

for _ in range(n//4):
    answer = 'long ' + answer
print(answer)