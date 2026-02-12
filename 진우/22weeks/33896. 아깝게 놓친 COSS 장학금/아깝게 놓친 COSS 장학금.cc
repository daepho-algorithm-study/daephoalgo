#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 비교 함수: 정렬 기준 정의
bool compare(const pair<string, pair<int, int>>& a,
             const pair<string, pair<int, int>>& b) {
    // 1️⃣ COSS 점수가 다르면, 점수 높은 학생이 먼저 오도록
    if (a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    }

    // 2️⃣ 점수가 같으면, 비용이 적은 학생이 먼저 오도록
    if (a.second.second != b.second.second) {
        return a.second.second < b.second.second;
    }

    // 3️⃣ 점수와 비용이 모두 같으면, 이름 순으로 사전 오름차순
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false); // cin/cout 속도 최적화
    cin.tie(nullptr);                 // cin과 cout 묶음 해제

    int n; // 학생 수 입력
    cin >> n;

    string name;  // 학생 이름
    int score;    // 장학 점수
    int risk;     // 위험도
    int cost;     // 프로젝트 비용

    // 학생 정보를 저장할 벡터
    // arr[i].first  -> 학생 이름
    // arr[i].second.first  -> COSS 점수
    // arr[i].second.second -> 프로젝트 비용
    vector<pair<string, pair<int, int>>> arr;

    // 학생 정보 입력 및 COSS 계산
    for (int i = 0; i < n; i++) {
        cin >> name >> score >> risk >> cost;

        // COSS 계산 공식: (score^3) / (cost * (risk + 1))
        int coss = (score * score * score) / (cost * (risk + 1));

        // 벡터에 학생 정보 추가
        arr.push_back({ name, {coss, cost}});
    }

    // 정렬: compare 함수 기준으로 정렬
    sort(arr.begin(), arr.end(), compare);

    // 정렬 후 앞에서 두 번째 학생 이름 출력
    cout << arr[1].first << "\n";

    return 0;
}
