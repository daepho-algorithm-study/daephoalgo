import math

T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    tree = [0 for _ in range(N + 1)]
    num = 1
    def inorder(idx) :
        global num
        if idx > N:
            return
        inorder(idx * 2)
        tree[idx] = num
        num += 1
        inorder(idx * 2 + 1)
    inorder(1)
    root = tree[1]
    node = tree[math.floor(N / 2)]
    print(f'#{tc} {root} {node}')