#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
    vector<vector<int>> answer;
    // ext 문자열 해당 인덱스 저장 해시
    unordered_map<string, int> h;
    // 문자열에 인덱스 할당
    h["code"] = 0, h["date"] = 1, h["maximum"] = 2, h["remain"] = 3;
    // val_ext 값보다 작은 데이터 추출
    for (int i = 0; i < data.size(); i++)
        if (data[i][h[ext]] < val_ext)
            answer.push_back(data[i]);
    // 정렬 기준에 따라 정렬
    switch (h[sort_by])
    {
    case 0:
        sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b)
             { return a[0] < b[0]; });
        break;
    case 1:
        sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b)
             { return a[1] < b[1]; });
        break;
    case 2:
        sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b)
             { return a[2] < b[2]; });
        break;
    default:
        sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b)
             { return a[3] < b[3]; });
    }
    return answer;
}