#include <iostream>
#include <string>

using namespace std;

// 시간을 초로 환산하는 함수 정의
int sec(int h, int m, int s);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string q;
    // 현재 속도와 시간 저장 변수 정의
    int v = 0, cur = 0;
    // 이동거리 저장 변수 정의
    double d = 0;
    // 소수점 두 자리까지 출력되게 설정
    cout << fixed;
    cout.precision(2);
    while (1)
    {
        // 공백 포함 한 줄 입력 받기
        getline(cin, q);
        // 더 이상 입력이 없으면 종료
        if (cin.eof())
            break;
        // 이전 쿼리의 시간 저장
        int prev = cur;
        // 시간 추출
        int h = stoi(q.substr(0, 2)), m = stoi(q.substr(3, 2)), s = stoi(q.substr(6, 2));
        // 현재 시간 초로 환산 후 저장
        cur = sec(h, m, s);
        // 이동거리 계산
        double dis = v * (cur - prev) / 3600.0;
        // 현재까지의 이동거리에 합산
        d += dis;
        // 속도가 포함된 쿼리일 때
        if (q.size() > 8)
            // 속도 갱신
            v = stoi(q.substr(9));
        // 속도가 포함되지 않은 쿼리일 때
        else
            // 현재까지 이동거리 출력
            cout << q << " " << d << " km" << "\n";
    }
    return 0;
}

int sec(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}