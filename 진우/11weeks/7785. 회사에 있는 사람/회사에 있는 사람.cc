#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> work;  
    // 회사에 "현재" 남아 있는 사람들의 이름을 저장하는 집합
    // set → 자동 정렬 + 중복 없음

    string name, log;
    for (int i = 0; i < n; i++) {
        cin >> name >> log;  
        // name : 이름
        // log  : enter 또는 leave

        if (log == "enter") {
            work.insert(name);  
            // 회사에 들어왔으므로 set에 추가
        }
        else {
            work.erase(name);   
            // leave → 회사에서 나갔으므로 set에서 삭제
        }
    }

    // 역순으로 출력하기 위해 vector로 옮김
    vector<string> people(work.begin(), work.end());

    // 내림차순 문자열 정렬
    sort(people.begin(), people.end(), greater<string>());

    // 결과 출력
    for (int i = 0; i < (int)people.size(); i++) {
        cout << people[i] << "\n";
    }

    return 0;
}
