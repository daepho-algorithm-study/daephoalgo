N, K = map(int, input().split())

arr = []

num = []

for i in range(1, N+1):
    arr.append(i)

j = 0
while len(arr) > 0:
    j += K - 1
    
    if j >= len(arr):
        j = j % len(arr)

    num.append(arr[j])
    
    arr.pop(j)

print('<', end = '')
for l in num:
    if l == num[-1]:
        print(l, end = '')
    else:
        print(l, end = ', ') 
print('>')


