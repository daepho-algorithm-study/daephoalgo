#include <iostream>
#include <string>

using namespace std;

// 가로 세로 대각선 인덱스 저장 배열
int ln[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (1)
    {
        cin >> s;
        // 입력으로 end가 들어오면 반복 종료
        if (s == "end")
            break;
        // 가능 여부 체크 변수
        bool check = true;
        // X와 O의 개수 저장 변수
        int x = 0, o = 0;
        // X와 O 개수 카운팅
        for (int i = 0; i < 9; i++)
            if (s[i] == 'X')
                x++;
            else if (s[i] == 'O')
                o++;
        // X와 O의 개수가 맞지 않은 경우 제외
        if (x < o || x > o + 1)
            check = false;
        else
        {
            // X와 O의 게임 승리 조건 충족 여부 체크 변수
            bool xw = false, ow = false;
            // 가로, 세로, 대각선 탐색 후 조건 체크
            for (int i = 0; i < 8; i++)
            {
                string temp = "";
                for (int j = 0; j < 3; j++)
                    temp += s[ln[i][j]];
                if (temp == "XXX")
                    xw = true;
                if (temp == "OOO")
                    ow = true;
            }
            // X와 O가 조건을 충족하여 게임이 끝났을 때 나올 수 없는 상황 제외
            if (xw && x == o)
                check = false;
            if (ow && x == o + 1)
                check = false;
            // 아직 결판 나지 않은 경우도 제외
            if (!xw && !ow && x + o < 9)
                check = false;
        }
        if (check)
            cout << "valid";
        else
            cout << "invalid";
        cout << "\n";
    }
    return 0;
}