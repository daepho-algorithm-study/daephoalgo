|                    이번주 풀이 문제🧩                    |                       |                         |
| :------------------------------------------------------: | :-------------------: | :---------------------: |
| **1.** [플로이드2](https://www.acmicpc.net/problem/11780) | **2.** [숫자 변환하기](https://school.programmers.co.kr/learn/courses/30/lessons/154538) | **3.** [주차 요금 계산](https://school.programmers.co.kr/learn/courses/30/lessons/92341) | 
**4.** [가장 많이 받은 선물](https://school.programmers.co.kr/learn/courses/30/lessons/258712) || 

---

# 🧩 문제

## [플로이드2](https://www.acmicpc.net/problem/11780)

### 💡 아이디어 / 접근법

1. 역추적을 위한 배열 선언
2. 입력값 그래프로 파싱
3. 플로이드 워셜 수행
4. path[i][j] 에 path[i][k] 값 넣기 (역추적을 위함)
5. 경로 복원 후 출력

### 🤔 후기

일단 플로이드 워셜 문제를 많이 풀어봤기 때문에 템플릿은 금방 떠올려서 작성했지만 역추적을 어떻게 넣어야 할 지 고민을 조금 했음

## [숫자 변환하기](https://school.programmers.co.kr/learn/courses/30/lessons/154538)

### 💡 아이디어 / 접근법
1. vistied 를 입력 최대범위로 잡기
2. x에 대해 bfs 수행
3. next = cur + n, cur * 2, cur * 3로 탐색 진행
4. cur === y 일 경우 출력
5. 안되면 -1 출력

### 🤔 후기
 
이전에 풀었던 숨바꼭질이랑 정확히 똑같은 문제임 바로 풀었음

## [주차 요금 계산](https://school.programmers.co.kr/learn/courses/30/lessons/92341)

### 💡 아이디어 / 접근법

1. 시간을 분으로 바꾸는 함수
2. 객체 정의
3. 객체 초기화 및 삽입
4. 조건에 맞게 코드 작성
5. 출력

### 🤔 후기
 
아이디어가 되게 불친절한데 그냥 구현 문제라서 아예 다 쓰면 별로일 것 같아서 키워드만 맞게 써봤슴당


## [가장 많이 받은 선물](https://school.programmers.co.kr/learn/courses/30/lessons/258712)

### 💡 아이디어 / 접근법

1. 준 사람과 받은 사람의 인덱스 뽑아서 배열에 저장
2. 배열 순회해서 조건에 맞게 결과값에 저장
3. 결과 배열 출력

### 🤔 후기
 
이 문제도 그냥 구현 문제라서 아이디어를 상세하게 적으면 크게 도움이 안될 것 같아서 이렇게 적었슴당