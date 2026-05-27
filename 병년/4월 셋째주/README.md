|                    이번주 풀이 문제🧩                    |                       |                         |
| :------------------------------------------------------: | :-------------------: | :---------------------: |
| **1.** [이진탐색(중위순회)](https://swexpertacademy.com/main/code/problem/problemDetail.do) | **2.** [이진탐색](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWTLcyA6qAMDFAVT) | **3.** [반복문자 지우기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWTQbpTaQfEDFAVT) | 
**4.** [격자판 칠하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AYEXgKnKKg0DFARx&categoryId=AYEXgKnKKg0DFARx&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=5) || 

---

# 🧩 문제

## [이진탐색(중위순회)](https://swexpertacademy.com/main/code/problem/problemDetail.do)

### 💡 아이디어 / 접근법

1. 초기값 1로 설정
2. 후위 순회 실행
3. 왼쪽(idx * 2) 부터 저장
4. 중간 저장
5. 오른쪽 저장
6. 루트노드와 N / 2 번 노드 출력

### 🤔 후기

오랜만에 SWEA 문제 풀었는데 옛날 생각 나고 좋았음 이 문제는 이진 탐색이라고 되어 있지만 사실 트리의 후위순회를 묻는 문제여서 후위순회로 트리 저장하고 노드 출력하면 끝

## [이진탐색](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWTLcyA6qAMDFAVT)

### 💡 아이디어 / 접근법
1. mid 값 l + r / 2로 초기 설정
2. l이 r 미만일 때만 반복
3. cnt 증가
4. 만약 mid 값이 end 라면 return cnt
5. mid 가 end 보다 크다면 l 에 mid 할당 아니라면 r 에 mid 할당
6. a, b 각각 함수 실행 후 누가 더 큰지에 따라 출력 안되면 0 출력

### 🤔 후기
 
이진탐색 기본 문제인데 완벽한 이진탐색은 아니고 l,r 에 mid 값 자체를 할당하는 변형문제

## [반복문자 지우기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWTQbpTaQfEDFAVT)

### 💡 아이디어 / 접근법

1. 스택 생성
2. 스택에 아무것도 없으면 삽입
3. 만약 스택 마지막 값이 현재 값이랑 달라도 삽입
4. 아니면 pop
5. stack 의 길이 출력

### 🤔 후기
 
스택 기본 문제인데 뭐 별 거 없었음 쉬웠음


## [격자판 칠하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AYEXgKnKKg0DFARx&categoryId=AYEXgKnKKg0DFARx&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=5)

### 💡 아이디어 / 접근법

1. 델타 배열 생성
2. 방문체크용 배열 생성
3. 만약 다음 값이 랑 현재 값이랑 같으면 바로 false 반환
4. 방문한 적 없고 다음값이 ? 일 때 현재 값이 . 라면 다음 값 #로 바꾸기
5. 아니라면 반대로 하기
6. 방문 체크 후 큐에 삽입
7. 방문하지 않은 좌표에 대해 ?가 아니라면 큐에 삽입 후 방문체크
8. bfs 수행후 flag에 따라 값 출력

### 🤔 후기
 
예전에 풀었던 이분그래프와 동일한 문제임 그때는 dfs로 풀었고 이번에는 bfs로 풀어봤는데 큐에 넣을 때 알 수 없는 경우가 아닐 때 넣어주면 되는 점만 빼면 비슷한듯?