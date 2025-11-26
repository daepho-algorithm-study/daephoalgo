package baekJoon;

import java.io.*;

public class B25501 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        while (t > 0) {
            // 입력 횟수 먼저 차감하고
            t--;
            // 입력 받은 다음
            String s = br.readLine();
            // 팰린드롬 재귀함수에 집어넣고
            int result = isPalindrome(s);
            // 현재 결과와 카운트를 담아서 쓴다음 몰아서 출력
            bw.write(result + " " + cnt + "\n");
        }

        br.close();
        bw.close();
    }

    // 호출 횟수를 저장할 변수
    // static 영역에 담으면 어디서든 쓸 수 있다
    static int cnt;

    // 카운트 초기화 및 팰린드롬 체크 호출 함수
    // 해당 함수 호출과 동시에 cnt 값을 초기화 해서
    // 이번 입력값에 대한 호출 횟수를 셀거니까!
    public static int isPalindrome(String s){
        cnt = 0;
        return check(s, 0, s.length() - 1);
    }

    // 코드 호출 할때마다 카운트 ++
    // 카운트도 정하고, 동시에 팰린드롬인지 아닌지도 전달해줌
    public static int check(String s, int l, int r) {
        cnt++;

        // 약간 투포인터? 느낌?
        // 문자열의 시작과 끝이 교차하거나 같으면 팰린드롬
        if (l >= r) {
            return 1;
        } else {
            // 좌우 문자가 다르면 팰린드롬 아님
            if (s.charAt(l) != s.charAt(r)) {
                return 0;
                // 좌우 문자가 같으면 범위 줄여서 재귀
            } else {
                return check(s, l + 1, r - 1);
            }
        }

    }
}

