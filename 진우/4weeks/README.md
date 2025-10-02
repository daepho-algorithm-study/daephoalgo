# 이번주 풀이 문제🧩

| 번호 | 문제 | 번호 | 문제 | 번호 | 문제 | 번호 | 문제 |
|:--:|:--|:--:|:--|:--:|:--|:--:|:--|
| **1** | [단어의 개수 - 1152](https://www.acmicpc.net/problem/1152) | **2** | [평균 - 1546](https://www.acmicpc.net/problem/1546) | **3** | [문자열 반복 - 2675](https://www.acmicpc.net/problem/2675) | **4** | [단어 길이 재기 - 2743](https://www.acmicpc.net/problem/2743) |
| **5** | [상수 - 2908](https://www.acmicpc.net/problem/2908) | **6** | [문자열 - 9086](https://www.acmicpc.net/problem/9086) | **7** | [알파벳 찾기 - 10809](https://www.acmicpc.net/problem/10809) | **8** | [바구니 뒤집기 - 10811](https://www.acmicpc.net/problem/10811) |
| **9** | [아스키 코드 - 11654](https://www.acmicpc.net/problem/11654) | **10** | [숫자의 합 - 11720](https://www.acmicpc.net/problem/11720) | **11** | [문자와 문자열 - 27866](https://www.acmicpc.net/problem/27866) | **12** | [배열 조각하기 - 181893](https://school.programmers.co.kr/learn/courses/30/lessons/181893) |
| **13** | [2의 영역 - 181894](https://school.programmers.co.kr/learn/courses/30/lessons/181894) | **14** | [배열 만들기 3 - 181895](https://school.programmers.co.kr/learn/courses/30/lessons/181895) | **15** | [첫 번째로 나오는 음수 - 181896](https://school.programmers.co.kr/learn/courses/30/lessons/181896) |  |

---

# 🧩 문제

## [알파벳 찾기 - 10809](https://www.acmicpc.net/problem/10809)

### 💡 아이디어 / 접근법
첫 번째
a~z까지 이루어진 문자열을 만든 후 하나씩 비교하여 계산 
-> 그런데 어떻게 알파벳 순서에 맞춰서 숫자를 정하지?

두 번째 
입력 받은 문자열을 아스키코드로 변환 후 'a'를 빼면 알파벳 순서대로 배열에 접근 가능 
-> -1로 이루어진 알파벳 숫자의 배열 생성
-> for문을 통해 입력 받은 배열을 인덱스 값을 -1로 이루어진 배열의 인덱스 위치에 삽입 


### 🤔 후기
알파벳이 나타난 순서를 찾는 내용이라 알파벳 순서대로 넣는 방법을 찾는 것이 어려웠다. 
처음에는 a~z까지 이루어진 문자열을 활용하여 조건을 만족시키려 했으나 막상 아스키 코드로 접근해 보니 굳이 문자열을 사용하지 않아도 'a'를 뺄 때 조건을 확인하므로 필요가 없었다.
 
---
