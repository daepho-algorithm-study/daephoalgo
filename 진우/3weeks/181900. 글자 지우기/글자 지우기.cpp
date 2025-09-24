#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = my_string;

    // 인덱스를 정렬하고 뒤에서부터 제거
    sort(indices.rbegin(), indices.rend());
    for (int i : indices) {
        if (i >= 0 && i < (int)answer.size()) {
            answer.erase(i, 1);
        }
    }
    return answer;
}
