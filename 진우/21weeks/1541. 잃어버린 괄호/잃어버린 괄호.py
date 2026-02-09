import sys
input = sys.stdin.readline

s = input().strip()

arr = s.split('-')  # '-' 기준으로 나누기

# 첫 번째 그룹은 그대로 더함
result = sum(map(int, arr[0].split('+')))

# 나머지 그룹들은 다 빼기
for i in arr[1:]:
    result -= sum(map(int, i.split('+')))

print(result)
