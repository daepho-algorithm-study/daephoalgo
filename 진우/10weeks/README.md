# 이번주 풀이 문제🧩

| 번호 | 문제 | 번호 | 문제 | 번호 | 문제 | 번호 | 문제 |
|:--:|:--|:--:|:--|:--:|:--|:--:|:--|
| **1** | [단어 정렬 - 1181](https://www.acmicpc.net/problem/1181) | **2** | [소트인사이드 - 1427](https://www.acmicpc.net/problem/1427) | **3** | [수 정렬하기 2 - 2751](https://www.acmicpc.net/problem/2751) | **4** | [나이순 정렬 - 10814](https://www.acmicpc.net/problem/10814) |
| **5** | [수 정렬하기 3 - 10989](https://www.acmicpc.net/problem/10989) | **6** | [좌표 정렬하기 - 11650](https://www.acmicpc.net/problem/11650) | **7** | [좌표 정렬하기 2 - 11651](https://www.acmicpc.net/problem/11651) | **8** | [좌표 압축 - 18870](https://www.acmicpc.net/problem/18870) |

---

# 🧩 문제

## [수 정렬하기 3 - 10989](https://www.acmicpc.net/problem/10989)

### 💡 아이디어 / 접근법
첫 번째
- 입력 받은 값을 전부 배열에 넣고 sort를 사용 => 메모리 초과(최대 10,000,000의 입력 받은 값 전부를 넣게 되어 메모리 초과)

두 번째
- 미리 10,000,000까지의 배열을 만들어두고 빈도를 저장하는 카운팅 정렬 사용

### 🤔 후기
범위가 10,000,000이기 때문에 하나 하나 전부 배열에 저장하게 되면 메모리 초과가 발생하게 된다. 카운팅 정렬을 구현 할 줄 알면 쉽게 풀리는 문제
카운팅 정렬을 구현하라고 만들어둔 문제 같음
 
---

# 🧩 문제

## [좌표 정렬하기 - 11650](https://www.acmicpc.net/problem/11650)

### 💡 아이디어 / 접근법
- sort 사용

### 🤔 후기
sort 자체가 x, y의 배열을 정렬 할 경우 x의 값이 같으면 y순으로 정렬하는 규칙이 있었음 

---

# 🧩 문제

## [좌표 정렬하기 2 - 11651](https://www.acmicpc.net/problem/11651)

### 💡 아이디어 / 접근법
- 입력 받은 값을 y, x 형태로 배열에 저장 그리고 sort로 정렬 후 x, y 형태로 출력

### 🤔 후기
배열에 저장 할 때 y, x로 하면 끝

---

# 🧩 문제

## [단어 정렬 - 1181](https://www.acmicpc.net/problem/1181)

### 💡 아이디어 / 접근법
- sort로 사전 순으로 정렬 후 길이 순으로 다시 정렬 c++ => stable sort / python => key=len

### 🤔 후기
sort는 사전순으로 정렬이 된다. 하지만 길이 순으로도 정렬을 해야 하기 때문에 정렬을 2번 해야 함

---

# 🧩 문제

## [나이순 정렬 - 10814](https://www.acmicpc.net/problem/10814)

### 💡 아이디어 / 접근법
- stable sort 사용
- stable sort: 정렬 기준이 같은 요소들끼리는 원래의 입력 순서를 유지

### 🤔 후기
안정 정렬인 stable sort만 사용하면 되는 문제

---

# 🧩 문제

## [좌표 압축 - 18870](https://www.acmicpc.net/problem/18870)

### 💡 아이디어 / 접근법
- 좌표 중복 제거 후 정렬, 그 후 각 좌표에 해당하는 index 값을 출력
- c++: map을 활용하여 key-value 형태로 저장
- python: enumerate 사용하여 해당 값과 index 값을 추출 후 저장

### 🤔 후기
처음에 문제를 이해하기도 어려웠고, 해당 값에 해당하는 index를 출력하는 것도 되게 헤맸다. key-value로 index를 출력해야 하는 그런 문제

---