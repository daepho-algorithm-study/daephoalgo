# 이번주 풀이 문제🧩

| 번호 | 문제 | 번호 | 문제 | 번호 | 문제 | 번호 | 문제 |
|:--:|:--|:--:|:--|:--:|:--|:--:|:--|
| **1** | [직사각형에서 탈출 - 1085](https://www.acmicpc.net/problem/1085) | **2** | [분해합 - 2231](https://www.acmicpc.net/problem/2231) | **3** | [소수 - 2581](https://www.acmicpc.net/problem/2581) | **4** | [블랙잭 - 2798](https://www.acmicpc.net/problem/2798) |
| **5** | [네 번째 점 - 3009](https://www.acmicpc.net/problem/3009) | **6** | [삼각형과 세 변 - 5073](https://www.acmicpc.net/problem/5073) | **7** | [대지 - 9063](https://www.acmicpc.net/problem/9063) | **8** | [삼각형 외우기 - 10101](https://www.acmicpc.net/problem/10101) |
| **9** | [소인수분해 - 11653](https://www.acmicpc.net/problem/11653) | **10** | [세 막대 - 14215](https://www.acmicpc.net/problem/14215) | **11** | [수학은 체육과목 입니다 - 15894](https://www.acmicpc.net/problem/15894) | **12** | [알고리즘 수업 - 알고리즘의 수행 시간 1~6 + 점근적표기1](https://www.acmicpc.net/step/53) |
| **13** | [직사각형 - 27323](https://www.acmicpc.net/problem/27323) |  |

---

# 🧩 문제

## [소수 - 2581](https://www.acmicpc.net/problem/2581)

### 💡 아이디어 / 접근법
-첫 번째
브루트포스 방식으로 M ~ N 사이의 소수를 전부 찾아서 배열에 저장한 후 배열의 합과 0번째 인덱스 값을 출력

-두 번째
에스테라토네스의 체를 활용하여 시간을 줄임


### 🤔 후기
브루트포스로도 풀리긴 하지만 에스테라토네스의 체를 활용하는게 확실히 빠르다.
```
j = i * i 부터 시작하는 이유

🔸 핵심: “그 이전의 배수는 이미 지워졌기 때문!”

예시: i = 5일 때

배수는: 5×2=10, 5×3=15, 5×4=20, 5×5=25, 5×6=30 …

그런데 보세요 👇

10, 15, 20은 이미 2나 3의 배수 제거할 때 지워졌습니다.

새로 지울 필요가 있는 건 5×5 = 25부터예요.

즉,
i * i보다 작은 배수(i×2, i×3, … i×(i−1))는 이미 이전 소수들의 배수로 제거됨.
```

<details>
<summary>에스테라토네스의 체 cpp</summary>

```
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<bool> isPrime(N + 1, true); // 0~N까지 소수 여부

    isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아님

    // 에라토스테네스의 체
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false; // i의 배수는 소수가 아님
            }
        }
    }

    int sum = 0;
    int minPrime = -1;

    // M~N 사이 소수 합과 최소 소수 찾기
    for (int i = M; i <= N; i++) {
        if (isPrime[i]) {
            sum += i;
            if (minPrime == -1) minPrime = i; // 최소 소수 저장
        }
    }

    if (minPrime == -1) { // 소수가 없는 경우
        cout << -1 << "\n";
    } else {
        cout << sum << "\n" << minPrime << "\n";
    }

    return 0;
}

```
</details>

<details>
<summary>에스테라토네스의 체 py</summary>

```
M = int(input())
N = int(input())

# 0~N까지 소수 여부 True로 초기화
is_prime = [True] * (N + 1)
is_prime[0] = is_prime[1] = False  # 0과 1은 소수가 아님

# 에라토스테네스의 체
for i in range(2, int(N ** 0.5) + 1):
    if is_prime[i]:
        for j in range(i * i, N + 1, i):
            is_prime[j] = False  # i의 배수는 소수가 아님

# M~N 사이 소수만 추출
primes = [i for i in range(M, N + 1) if is_prime[i]]

# 결과 출력
if primes:
    print(sum(primes))   # 소수 합
    print(primes[0])     # 최소 소수
else:
    print(-1)            # 소수가 없는 경우

```
</details>

---

# 🧩 문제

## [분해합 - 2231](https://www.acmicpc.net/problem/2231)

### 💡 아이디어 / 접근법
그냥 1부터 시작해서 i의 분해합을 전부 계산한 다음 N이 되는 분해합을 출력


### 🤔 후기
처음에는 문제를 어떻게 풀어야 하는지 이해가 되지 않았는데 브루트포스인걸 생각하고 그냥 1부터 찾기로 했음