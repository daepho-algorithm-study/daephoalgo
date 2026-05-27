|                    이번주 풀이 문제🧩                    |                       |                         |
| :------------------------------------------------------: | :-------------------: | :---------------------: |
| **1.** [중간 평균값 구하기)](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pw_-KAdcDFAUq) | **2.** [보급로](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD) | **3.** [여행](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AZyNUDmaATzHBIRj) | 
**4.** [미로2](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD) || 

---

# 🧩 문제

## [중간 평균값 구하기)](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pw_-KAdcDFAUq)

### 💡 아이디어 / 접근법

1. 리스트 정렬
2. 처음, 끝을 뺀 나머지 값 더해서 평균값 구하기

### 🤔 후기

easy

## [보급로](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD)

### 💡 아이디어 / 접근법
(0-1 bfs)
1. dist 배열 생성
2. 시작점과 cost 넣기
3. 반복 돌리면서 델타 탐색 진행
4. 다음의 값을 weight 으로 설정
5. weight + cost 의 값보다 다음 거리가 더 크면 갱신
6. weight 이 0일 때 (벽이 아닐 때)는 왼쪽에 넣어주고
7. weight 이 1일 때는 (벽일 때)는 오른쪽에 넣어주기
8. dist[n-1][n-1] 출력

(다익스트라)
1. 데크에서 heap으로 바뀜
2. weight 값 없이 그냥 dist[nx][ny] 가 arr[nx][ny] + cost 보다 크면 갱신 후 넣기

### 🤔 후기
 
0-1 bfs 랑 다익스트라를 연습할 수 있는 좋은 문제였음 문제 설명 쓰다보니까 느낀건데 이게 굳이 weight이라는 변수가 필요가 없었네

## [여행](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AZyNUDmaATzHBIRj)

### 💡 아이디어 / 접근법

1. N,E,S,W 를 key 로 가지는 객체 생성
2. 카운팅
3. 만약 obj[N] > 0 and obj[S] == 0 거나 obj[S] > 0 and obj['N'] == 0 일 때 false
4. WE 도 동일하게 맞춰주기
5. flag 가 true 면 yes 아니면 no

### 🤔 후기
 
그냥 동서, 남북 묶어서 각각 개수가 둘 중 하나라도 0이 있으면 false 아니면 true 하는 문제


## [미로2](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD)

### 💡 아이디어 / 접근법

1. 델타 배열 생성
2. 방문체크용 배열 생성
3. 출발지 좌표 queue에 삽입
4. 방문 체크 후 bfs 돌리기
5. 만약 도착하면 flag = true 후 종료
6. 델타 탐색 하면서 다음 값이 1 이 아니면 (길 or 도착지) 방문 체크 후 queue에 삽입

### 🤔 후기
 
그냥 bfs 기초 문제였음