#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    for (int i = 0; i < (int)intervals.size(); i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        
        for (int j = start; j <= end; j++ ) {
            answer.push_back(arr[j]);
        }
    }
    return answer;
}