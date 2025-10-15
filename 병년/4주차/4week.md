| 이번주 풀이 문제🧩  |                   |                |
|:-------------:|:-------------------:|:-------------------:|
| **1.** [2*n타일링](https://school.programmers.co.kr/learn/courses/30/lessons/12900) | **2.** [개인정보 수집 유효기간](https://school.programmers.co.kr/learn/courses/30/lessons/150370) | **3.** [게임 맵 최단거리](https://school.programmers.co.kr/learn/courses/30/lessons/1844) |
| **4.** [프렌즈4블록](https://school.programmers.co.kr/learn/courses/30/lessons/17679) | **5.** [의상](https://school.programmers.co.kr/learn/courses/30/lessons/42578) | **6.** [크레인 인형뽑기 게임](https://school.programmers.co.kr/learn/courses/30/lessons/64061) |
| **7.** [신규 아이디 추천](https://school.programmers.co.kr/learn/courses/30/lessons/72410) | **8.** [N-Queen](https://school.programmers.co.kr/learn/courses/30/lessons/12952) | **9.** [문제이름](링크) |
|  **10.** [문제이름](링크) | **11.** [문제이름](링크) | **12.** [문제이름](링크) |

---

# 🧩 문제

## [2*n타일링](https://school.programmers.co.kr/learn/courses/30/lessons/12900)

### 💡 아이디어 / 접근법 
먼저 타일이 어떻게 증가하는 지 손으로 작성해보니 이전의 값과 2번째 전의 값을 더하면 값이 나오는 전형적인 피보나치 수열 DP 였음 따라서 값을 구하고 나머지 연산을 통해 결과를 도출했음

### 🤔 후기
전형적인 DP 문제였고 직접 손으로 규칙을 찾아보니 문제 푸는 데에는 어려움이 없었음

## [개인정보 수집 유효기간](https://school.programmers.co.kr/learn/courses/30/lessons/150370)

### 💡 아이디어 / 접근법 
일단 매개변수로 들어오는 term 배열을 잘라서 key-value 값을 가진 객체로 변환해주고 주어진 날짜에 key 에 해당하는 값을 더해서 오늘 날짜와 비교하고 만료된 날짜인 경우에 정답 배열에 넣어주는 것으로 생각했음

### 🤔 후기
날짜 계산을 할 때 Date 타입의 값끼리 비교가 가능하다는 걸 까먹고 있어서 좀 해멨다..

## [게임 맵 최단거리](https://school.programmers.co.kr/learn/courses/30/lessons/1844)

### 💡 아이디어 / 접근법 
기본적인 미로찾기 문제로 BFS, DFS 둘 다 가능한 문제로 보였음 하지만 효율적인 부분과 최단 거리를 찾는 문제이기 때문에 BFS로 문제를 풀기로 하였음

### 🤔 후기
기본적인 BFS 문제로 BFS 다시 복기하는 데 도움이 됐던 문제 같음

## [프렌즈4블록](https://school.programmers.co.kr/learn/courses/30/lessons/17679)

### 💡 아이디어 / 접근법 
먼저 2가지 경우를 생각하였음 1. 터뜨릴 수 있는 요소를 0으로 바꾼다. 2. 요소를 밑으로 내려서 다시 터뜨릴 수 있도록 바꿔줌
문제 상황: 처음에 상하좌우 인접한 요소들을 터뜨리고 중력 처리로 진행하였음 근데 결과 값이 너무 크게 나옴
지문을 다시 보니 2x2만 확인하면 됐었음 따라서 {i,j}, {i+1,j} {i,j+1}, {i+1,j+1} 요소만 확인해주는 걸로 바꿨음
마지막으로 while 문으로 계속 반복하며 해당 요소가 '0' 이 아니면서 지금 요소와 동일할 때 check의 값과 해당 부분을 터뜨려줌(0으로) 그 후 answer 값 누적 후 반환 

### 🤔 후기
엄청 어려운 문제는 아니었다고 생각해서 바로 풀려고 했는데 생각보다 신경 쓸 게 좀 있었던 거 같다. 처음에 상하좌우 인접 판별로 잘못 이해한 것도 그렇고 0인 경우에 어떻게 중력 처리를 할 것인 지에 대한 부분을 생각하는 것이 좀..ㅋ 그리고 문제 제대로 좀 읽자..

## [의상](https://school.programmers.co.kr/learn/courses/30/lessons/42578)

### 💡 아이디어 / 접근법 
해시 맵에 key-value 값으로 넣고 몇 개 나왔는지 계산하기

### 🤔 후기
실제로 그렇게 풀렸다..

## [크레인 인형뽑기 게임](https://school.programmers.co.kr/learn/courses/30/lessons/64061)

### 💡 아이디어 / 접근법 
세로로 순회하고 인형 뽑고 스택에 있으면 터뜨리고 결과 값에 2개씩 누적하면 될 거 같다

### 🤔 후기
정답이다.. 그냥 쉬운 스택 문제 였던 거 같음

## [신규 아이디 추천](https://school.programmers.co.kr/learn/courses/30/lessons/72410)

### 💡 아이디어 / 접근법 
문제에 접근법이 다 나와있기 때문에 해당 접근법을 차근차근 따라 가면서 풀기

### 🤔 후기
처음에 단순 조건문이랑 반복문을 통해서 풀다가 너무 복잡하고 귀찮아서 정규 표현식 찾아서 써봤는데 신세계임..

## [N-Queen](https://school.programmers.co.kr/learn/courses/30/lessons/12952)

### 💡 아이디어 / 접근법 
가로, 세로, 대각선에 이미 말이 존재하는 지 판별하고 백트래킹을 이용하여 문제를 푸는 유명한 N-Queen 문제..

### 🤔 후기
대각선 판별이 조금 어려웠던 것 같고 굳이 2차원 배열로 탐색을 안해도 되는 문제였는데 좀 오래걸린 것 같음

---
