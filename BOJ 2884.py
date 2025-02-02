# 2884 알람 시계_조건문
h, m = map(int, input().split())

if m >= 45:
    print(h, m-45)    
else:
    print(h-1, m+15) if h >= 1 else print(23, m+15)