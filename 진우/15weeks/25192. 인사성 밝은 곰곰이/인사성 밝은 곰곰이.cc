#include <iostream>  // 표준 입출력 사용
#include <set>       // 중복을 허용하지 않는 set 컨테이너 사용

using namespace std;

int main() {
    int N;
    cin >> N;  // 채팅 로그의 총 개수 입력

    set<string> users;  // 현재 채팅방에서 등장한 사용자들을 저장 (중복 자동 제거)
    string user;        // 입력받을 문자열 ("ENTER" 또는 사용자 이름)
    int cnt = 0;        // 전체 인사 횟수(정답)

    for (int i = 0; i < N; i++) {
        cin >> user;

        // 새로운 채팅방이 시작되는 경우
        if (user == "ENTER") {
            // 이전 채팅방에서 인사한 사람 수를 누적
            cnt += users.size();

            // 다음 채팅방을 위해 사용자 목록 초기화
            users.clear();
        }
        else {
            // 현재 채팅방에서 사용자 이름 저장
            // set이므로 이미 등장한 이름은 자동으로 무시됨
            users.insert(user);
        }
    }

    // 마지막 채팅방에서 인사한 사람 수 누적
    cnt += users.size();

    cout << cnt << "\n";  // 최종 인사 횟수 출력

    return 0;
}
