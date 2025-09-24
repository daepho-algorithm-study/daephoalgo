#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer;
    for (int i = start_num; i >= 0; i--) {
        answer.push_back(i);
        if (i == end_num) {
            break;
        }
    }
    return answer;
}