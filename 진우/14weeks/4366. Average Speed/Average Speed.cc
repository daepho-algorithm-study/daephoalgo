#include <iostream>
#include <string>
#include <iomanip>  // 소수점 출력용
using namespace std;

int main() {
    string line;      // 입력 줄을 저장할 변수
    int speed = 0;    // 현재 속도 (km/h)
    double km = 0.0;  // 누적 거리 (km)
    int time1 = 0;    // 이전 시간(초 단위)

    while (getline(cin, line)) {  // 한 줄씩 입력 읽기
        string time = line.substr(0, 8);  // HH:MM:SS 부분만 추출

        // 시, 분, 초를 각각 정수로 변환
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));

        // 현재 시간을 초 단위로 변환
        int time2 = h * 3600 + m * 60 + s;

        // 이전 시간부터 현재 시간까지 이동 거리 계산
        // (초 단위 시간 차 * 속도) / 3600 = km 단위 거리
        km += (time2 - time1) * speed / 3600.0;

        // 현재 시간을 이전 시간으로 갱신
        time1 = time2;

        // 속도 정보가 있는 경우, 속도 갱신
        if (line.length() > 8) {
            speed = stoi(line.substr(9));
        }
        else {
            // 속도 정보가 없는 경우, 누적 거리 출력 (소수점 2자리)
            cout << time << " " << fixed << setprecision(2) << km << " km\n";
        }
    }
    return 0;
}
