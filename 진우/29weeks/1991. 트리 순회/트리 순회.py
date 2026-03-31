import sys
input = sys.stdin.readline

# -----------------------------------
# 각 노드의 왼쪽, 오른쪽 자식을 저장
# node['A'] = ('B', 'C') 형태
# -----------------------------------
node = {}

# -----------------------------
# 전위 순회 (Preorder)
# 순서: 루트 → 왼쪽 → 오른쪽
# -----------------------------
def preorder(n):
    if n == '.':  # 자식이 없는 경우 종료
        return
    
    print(n, end='')           # 1. 루트 출력
    preorder(node[n][0])       # 2. 왼쪽 자식
    preorder(node[n][1])       # 3. 오른쪽 자식


# -----------------------------
# 중위 순회 (Inorder)
# 순서: 왼쪽 → 루트 → 오른쪽
# -----------------------------
def inorder(n):
    if n == '.':
        return
    
    inorder(node[n][0])        # 1. 왼쪽 자식
    print(n, end='')           # 2. 루트 출력
    inorder(node[n][1])        # 3. 오른쪽 자식


# -----------------------------
# 후위 순회 (Postorder)
# 순서: 왼쪽 → 오른쪽 → 루트
# -----------------------------
def postorder(n):
    if n == '.':
        return
    
    postorder(node[n][0])      # 1. 왼쪽 자식
    postorder(node[n][1])      # 2. 오른쪽 자식
    print(n, end='')           # 3. 루트 출력


# -----------------------------------
# 입력
# -----------------------------------
N = int(input())

for _ in range(N):
    parent, left, right = input().split()
    node[parent] = (left, right)  # 딕셔너리에 저장

# -----------------------------------
# 순회 실행 (루트는 'A')
# -----------------------------------
preorder('A')
print()

inorder('A')
print()

postorder('A')