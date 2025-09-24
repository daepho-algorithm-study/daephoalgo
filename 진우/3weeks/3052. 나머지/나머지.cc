#include <iostream>
#include <set>   // set 사용
using namespace std;

int main() {
    set<int> num;           // 중복을 허용하지 않는 집합

    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;           // 숫자 입력
        num.insert(n % 42); // 42로 나눈 나머지를 집합에 삽입
    }

    cout << num.size() << endl; // 집합 크기(서로 다른 나머지 개수) 출력
    return 0;
}
