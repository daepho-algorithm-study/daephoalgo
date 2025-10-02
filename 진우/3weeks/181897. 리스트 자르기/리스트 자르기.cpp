#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    int a = slicer[0], b = slicer[1], c = slicer[2];

    if (n == 1) {
        // 0 ~ b까지
        answer.assign(num_list.begin(), num_list.begin() + b + 1);
    } else if (n == 2) {
        // a ~ 끝까지
        answer.assign(num_list.begin() + a, num_list.end());
    } else if (n == 3) {
        // a ~ b까지
        answer.assign(num_list.begin() + a, num_list.begin() + b + 1);
    } else if (n == 4) {
        // a ~ b까지 c 간격으로
        for (int i = a; i <= b; i += c) {
            answer.push_back(num_list[i]);
        }
    }
    return answer;
}
