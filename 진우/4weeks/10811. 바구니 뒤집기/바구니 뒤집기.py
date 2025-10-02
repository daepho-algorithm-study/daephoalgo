N, M = map(int, input().split())

box = []

for x in range(1, N + 1):
    box.append(x)

for tc in range(M):
    i, j = map(int, input().split())

    box[i - 1:j] = reversed(box[i - 1:j])

print(*box)
