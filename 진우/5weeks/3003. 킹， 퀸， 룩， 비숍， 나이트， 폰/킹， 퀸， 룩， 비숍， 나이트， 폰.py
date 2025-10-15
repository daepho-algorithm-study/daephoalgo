chess = list(map(int, input().split()))
correct = [1, 1, 2, 2, 2, 8]
result = [correct[i] - chess[i] for i in range(6)]
print(*result)
