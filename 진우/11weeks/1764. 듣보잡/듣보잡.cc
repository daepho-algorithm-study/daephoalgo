#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;   // N: 듣도 못한 사람 수, M: 보도 못한 사람 수

    string name;

    // 듣도 못한 사람들의 이름을 저장할 set (자동 정렬 + 중복 제거)
    set<string> N_set;
    for (int i = 0; i < N; i++) {
        cin >> name;
        N_set.insert(name);    // set에 저장
    }

    vector<string> result;     // 듣보잡 명단을 저장할 벡터

    // 보도 못한 사람들 이름 입력 → 듣도 못한 명단(N_set)에 존재하면 결과에 추가
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (N_set.find(name) != N_set.end()) {  
            // set에 해당 이름이 있으면 듣보잡
            result.push_back(name);
        }
    }

    // 듣보잡 명단을 사전순으로 정렬
    sort(result.begin(), result.end());

    // 듣보잡의 수 출력
    cout << (int)result.size() << "\n";

    // 듣보잡 이름 출력
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
