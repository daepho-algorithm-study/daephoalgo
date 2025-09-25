num = set()

for _ in range(10):
    n = int(input())
    x = n % 42
    num.add(x)
    
print(len(num))