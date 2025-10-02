#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int first = -1, last = -1;

    // arr에서 첫 번째 2와 마지막 2의 위치 찾기
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == 2) {
            if (first == -1) first = i; // 처음 발견된 2
            last = i;                  // 계속 갱신 → 마지막 2
        }
    }

    if (first == -1) {       // 2가 없는 경우
        return {-1};
    }

    // first~last 구간을 추출
    for (int i = first; i <= last; i++) {
        answer.push_back(arr[i]);
    }

    return answer;
}
