package baekjoon.Silver.level5;

import java.util.Scanner;

public class p1316 { // 백준 1316번 문제, 그룹 단어 체커(심화1)
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int tc = sc.nextInt();
        int cnt = 0;

        for (int i = 0; i < tc; i++) {
            if (check() == true) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    public static boolean check() {
        boolean[] arr = new boolean[26];
        int prev = 0;
        String word = sc.next();

        for (int i = 0; i < word.length(); i++) {
            int now = word.charAt(i); // i 번째 문자 저장(현재 문자)

            // 앞선 문자와 i 번째 문자가 같지 않다면?
            if (prev != now) { // 처음엔 당연히 다름

                // 해당 문자가 처음 나오는 경우 (false인 경우)
                if (arr[now - 'a'] == false) {
                    arr[now - 'a'] = true;
                    prev=now;
                } else { // 해당 문자가 이미 나온 적이 있는 경우(그룹 단어가 아니게 됨)
                    return false; // 함수 종료
                }
            }

            // 앞선 문자와 i 번째 문자가 같다면? (연속된 문자)
            else {
                continue;
            }
        }
        // 모든 조건을 통과 한다면 그룹단어임
        return true;
    }
}
