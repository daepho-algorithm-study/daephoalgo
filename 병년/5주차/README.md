| 이번주 풀이 문제🧩  |                   |                |
|:-------------:|:-------------------:|:-------------------:|
| **1.** [미로 탈출](https://school.programmers.co.kr/learn/courses/30/lessons/159993) | **2.** [귤 고르기](https://school.programmers.co.kr/learn/courses/30/lessons/138476) | **3.** [연속 부분 수열 합의 개수](https://school.programmers.co.kr/learn/courses/30/lessons/131701) |
---

# 🧩 문제

## [미로 탈출](https://school.programmers.co.kr/learn/courses/30/lessons/159993)

### 💡 아이디어 / 접근법 
1. 최단 거리 탐색이므로 BFS 로 접근
2. 시작점과 레버점의 위치를 찾기
3. BFS의 매개변수로 레버인 경우, 끝인 경우 두 가지를 시행
4. 두 가지의 결과중 하나라도 -1 일 경우 -1 리턴 그렇지 않다면 두 값을 더해서 결과 반환

### 🤔 후기
일단 문제 이해는 빠르게 했고 로직도 금방금방 새웠는데 문제가 하나의 배열로 두 가지의 경우를 돌리다보니 초기화가 원활하게 이루어지지 않았음 따라서 깊은 복사를 통해 두 가지의 배열을 두고 BFS 를 실행하였음 그러니까 됐음 이상 끝

## [귤 고르기](https://school.programmers.co.kr/learn/courses/30/lessons/138476)

### 💡 아이디어 / 접근법 
1. 귤의 개수를 담고 있는 객체 
2. 객체 내림차순
3. for of 반복으로 목표값 갱신 및 목표값 초과시 종료
4. 반복문 안쪽에서 answer ++

### 🤔 후기
객체 내림차순이랑 배열 요소의 빈도 수 세기만 할 줄 알면 쉬운 문제였음

## [연속 부분 수열 합의 개수](https://school.programmers.co.kr/learn/courses/30/lessons/131701)

### 💡 아이디어 / 접근법 
1. 수열을 탐색해서 구하기
2. 해당 수열의 합을 저장
3. 중복 제거를 위한 set

### 🤔 후기
기본적으로 수열 구할 줄 알면 어려운 문제는 아니었다고 생각함. 근데 굳이 dfs말고 다른 방법이 더 좋을 거 같음..

---