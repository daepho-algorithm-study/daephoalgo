#include <iostream>
#include <vector>

using namespace std;

int bt(int cnt, const vector<vector<int>> &v); // 백트래킹 함수 정의
// 보드 이동 함수 정의
vector<vector<int>> moveboard(const vector<vector<int>> &b, int dir);
vector<int> compress(const vector<int> &v); // 보드 압축 함수 정의
int getmax(const vector<vector<int>> &b);   // 최대값 계산 함수 정의
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0)); // 보드 정보 저장 배열
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j]; // 보드 정보 저장
    cout << bt(0, board);
    return 0;
}

int bt(int cnt, const vector<vector<int>> &b)
{
    if (cnt == 5)
        return getmax(b); // 탐색 종료 시 최대값 출력
    int mx = getmax(b);   // 최대값 저장 변수
    for (int i = 0; i < 4; i++)
    {
        vector<vector<int>> nb = moveboard(b, i); // 보드 이동
        if (nb == b)
            continue;              // 이동 후 변화 없을 시 스킵
        int tmp = bt(cnt + 1, nb); // 탐색 재개
        if (mx < tmp)
            mx = tmp; // 최대값 갱신
    }
    return mx;
}

vector<vector<int>> moveboard(const vector<vector<int>> &b, int dir)
{
    vector<vector<int>> nb = b;
    if (dir == 0) // 왼 방향 압축
        for (int i = 0; i < n; i++)
        {
            vector<int> line;
            for (int j = 0; j < n; j++)
                line.push_back(b[i][j]); // 한 줄 복사
            vector<int> res = compress(line);
            for (int j = 0; j < n; j++)
                nb[i][j] = res[j]; // 압축 후 삽입
        }
    else if (dir == 1) // 오른 방향 압축
        for (int i = 0; i < n; i++)
        {
            vector<int> line;
            for (int j = n - 1; j >= 0; j--)
                line.push_back(b[i][j]); // 거꾸로 복사
            vector<int> res = compress(line);
            for (int j = n - 1; j >= 0; j--)
                nb[i][j] = res[n - 1 - j]; // 역순으로 삽입
        }
    else if (dir == 2) // 윗 방향 압축
        for (int j = 0; j < n; j++)
        {
            vector<int> line;
            for (int i = 0; i < n; i++)
                line.push_back(b[i][j]); // 세로 한 줄 복사
            vector<int> res = compress(line);
            for (int i = 0; i < n; i++)
                nb[i][j] = res[i]; // 압축 후 삽입
        }
    else // 아랫 방향 압축
        for (int j = 0; j < n; j++)
        {
            vector<int> line;
            for (int i = n - 1; i >= 0; i--)
                line.push_back(b[i][j]); // 세로 방향 거꾸로 복사
            vector<int> res = compress(line);
            for (int i = n - 1; i >= 0; i--)
                nb[i][j] = res[n - 1 - i]; // 역순으로 삽입
        }
    return nb;
}

vector<int> compress(const vector<int> &v)
{
    vector<int> tmp;
    for (int x : v)
        if (x != 0)
            tmp.push_back(x); // 0을 제외한 수 저장
    vector<int> merge;
    for (int i = 0; i < tmp.size(); i++)
        if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1])
        {
            merge.push_back(tmp[i] * 2); // 같은 수 병합 저장
            i++;                         // 한 칸 건너뛰기
        }
        else
            merge.push_back(tmp[i]); // 독립 수 저장
    while (merge.size() < v.size())
        merge.push_back(0); // 원본 벡터 길이만큼 뒤에 0 삽입
    return merge;
}

int getmax(const vector<vector<int>> &b)
{
    int mx = 0; // 최대값 저장 변수
    for (const auto &row : b)
        for (int x : row)
            if (mx < x)
                mx = x; // 최대값 갱신
    return mx;
}