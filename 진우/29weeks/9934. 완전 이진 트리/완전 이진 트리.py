# 중위 순회처럼 재귀로 노드를 탐색하고 각 깊이(depth)에 노드를 저장하는 함수
def inorder(start, end, depth):
    # start가 end보다 크면 범위를 벗어난 것이므로 종료
    if start > end:
        return

    # 중간 위치를 루트로 선택
    root = (start + end) // 2

    # 현재 깊이(depth)에 root 노드 값을 추가
    answer[depth].append(arr[root])

    # 왼쪽 서브트리 탐색 (중간보다 왼쪽 범위)
    inorder(start, root - 1, depth + 1)

    # 오른쪽 서브트리 탐색 (중간보다 오른쪽 범위)
    inorder(root + 1, end, depth + 1)



k = int(input())  # 트리의 높이 입력

node = 2 ** k - 1  # 완전 이진 트리 노드 총 개수 = 2^k - 1

arr = list(map(int, input().split()))  # 노드 값 입력
answer = [[] for _ in range(k)]        # 각 깊이별 노드 저장 공간 생성

# 전체 배열 범위를 중위 순회로 탐색
inorder(0, node - 1, 0)

# 각 깊이별로 출력
for level in answer:
    print(*level)  # 리스트 요소를 공백으로 구분하여 출력

