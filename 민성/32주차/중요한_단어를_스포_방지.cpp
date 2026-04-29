#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 단어 정보 저장 구조체 할당
struct word
{
    int s, e;
    string wd;
};

int solution(string message, vector<vector<int>> spoiler_ranges)
{
    int answer = 0;
    // 문자 길이 할당
    int ms = message.size();
    // 단어 저장 해시 할당
    unordered_map<string, int> h;
    // 단어 시작점 할당 변수
    int idx = 0;
    // 단어 할당 변수
    string temp;
    // 단어 저장 배열
    vector<word> w;
    // 단어 모자이크 유무 체크 배열
    vector<bool> moz(ms, false);
    // 문자 구분 작업
    for (int i = 0; i < ms; i++)
    {
        // 해당 위치가 공백이면 단어 정보 저장 및 시작점과 단어 변수 초기화
        if (message[i] == ' ')
        {
            word m;
            m.s = idx;
            m.e = i - 1;
            m.wd = temp;
            w.push_back(m);
            temp = "";
            idx = i + 1;
            continue;
        }
        // 단어 생성 및 단어 넘버링 표시
        temp += message[i];
        // 문자 끝에 도달 시 단어 저장
        if (i == ms - 1)
        {
            word m;
            m.s = idx;
            m.e = i;
            m.wd = temp;
            w.push_back(m);
        }
    }
    // 해당 단어 개수 표시
    for (int i = 0; i < w.size(); i++)
        h[w[i].wd]++;
    // 스포일러 부분 표시
    for (int i = 0; i < spoiler_ranges.size(); i++)
    {
        // 범위 할당
        int l = spoiler_ranges[i][0], r = spoiler_ranges[i][1];
        // 모자이크 표시
        for (int i = l; i <= r; i++)
            moz[i] = true;
    }
    // 단어에 모자이크 처리가 들어가 있으면 개수 차감
    for (int i = 0; i < w.size(); i++)
        for (int j = w[i].s; j <= w[i].e; j++)
            if (moz[j])
            {
                h[w[i].wd]--;
                break;
            }
    for (auto p : h)
        if (p.second == 0)
            answer++;
    return answer;
}