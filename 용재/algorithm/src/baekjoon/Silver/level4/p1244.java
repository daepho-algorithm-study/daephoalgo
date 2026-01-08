package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p1244 { // 백준 1244번 문제, 스위치 켜고 끄기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); // 스위치 개수

        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] sw = new int[n]; // 스위치를 담을 배열

        for (int i = 0; i < n; i++) {
            sw[i] = Integer.parseInt(st.nextToken()); // 스위치 초기화
        }

        int student = Integer.parseInt(br.readLine()); // 학생 수
        for (int j = 0; j < student; j++) {
            st = new StringTokenizer(br.readLine());
            int gender = Integer.parseInt(st.nextToken()); // 학생 성별
            int num = Integer.parseInt(st.nextToken()); // 학생이 받은 수

            if (gender == 1) { // 남학생이라면
                int cur = num;
                // 자신의 배수의 스위치의 상태를 바꿈
                while (cur - 1 < n) {
                    // num-1 하는 이유 -> 배수지만 인덱스는 0부터 출발하는데 문제의 스위치 번호는 1부터 출발이라 배수 계산 후 -1 해주면됨
                    sw[cur - 1] = sw[cur - 1] == 0 ? 1 : 0; // 스위치 상태 변경 (0이면 1, 1이면 0)
                    cur += num; // 배수 더해주기
                }

            } else { // 여학생이라면
                // 대칭이 닿는 범위까지 최대한 가서 스위치 상태 바꾸기
                int range = 1; // 처음 확인할 범위
                num = num - 1; // 인덱스 보정

                sw[num] = sw[num] == 1 ? 0 : 1; // 대칭 확인 전에 일단 받은 스위치 번호는 상태변화 해줌

                while (num - range >= 0 && num + range < n) { // 늘려간 범위가 배열 범위 안쪽이어야 함

                    if (sw[num - range] == sw[num + range]) { // 두개가 대칭이라면 (둘 다 1이거나 0이라면)
                        if (sw[num - range] == 1 && sw[num + range] == 1) { // 둘 다 1이라면
                            sw[num - range] = 0;
                            sw[num + range] = 0;
                        } else {
                            sw[num - range] = 1;
                            sw[num + range] = 1;
                        }
                        range++; // 대칭이면 범위 한칸 더 늘려서 확인
                    } else {
                        break; // 대칭아니면 반복문 바로종료
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();

        for (int k = 0; k < n; k++) {
            if ((k + 1) % 20 != 0) { // 한줄에 20개만 출력하기 위해 인덱스+1이 20의 배수라면 줄바꿈을 넣어준다
                sb.append(sw[k]).append(" ");

            } else {
                sb.append(sw[k]).append("\n");
            }
        }

        System.out.print(sb);

    }
}
