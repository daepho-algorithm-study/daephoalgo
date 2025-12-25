#include <iostream>   
#include <string>     
#include <set>        

using namespace std;

int main() {
    int N;
    cin >> N;  // 만남의 개수 입력

    set<string> dance;
    dance.insert("ChongChong");    // 처음부터 춤을 추고 있는 사람은 ChongChong

    // N번의 만남 정보를 처리
    for (int i = 0; i < N; i++) {
        pair<string, string> person;   // 두 사람의 이름을 저장할 pair
        cin >> person.first >> person.second; // 두 이름 입력

        // 첫 번째 사람이 이미 춤을 추고 있다면
        if (dance.find(person.first) != dance.end()) {
            // 두 번째 사람도 춤을 추게 됨
            dance.insert(person.second);
        }
        // 첫 번째 사람은 아니지만, 두 번째 사람이 이미 춤을 추고 있다면
        else if (dance.find(person.second) != dance.end()) {
            // 첫 번째 사람도 춤을 추게 됨
            dance.insert(person.first);
        }
    }

    // 최종적으로 춤을 추고 있는 사람의 수 출력
    cout << dance.size() << "\n";

    return 0;  
}
