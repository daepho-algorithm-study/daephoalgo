package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p14889 { // 백준 14889번 문제, 스타트와 링크
    static int N;
    static int[][] map;
    static boolean[] visited; // true면 스타트팀, false면 링크팀
    static int minDiff = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        visited = new boolean[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        combi(0, 0);

        System.out.println(minDiff);
    }

    // idx: 현재 탐색할 사람의 번호, count: 지금까지 뽑은 사람 수
    static void combi(int idx, int count) {
        // N/2명을 다 뽑았으면 능력치 계산하러 감
        if (count == N / 2) {
            diff();
            return;
        }

        // [탐색] 조합 만들기 (내 다음 번호부터 탐색)
        for (int i = idx; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;      // 스타트팀으로 영입
                combi(i + 1, count + 1); // 다음 사람 뽑으러 재귀
                visited[i] = false;
            }
        }
    }

    // 두 팀의 능력치 차이를 계산하는 함수
    static void diff() {
        int teamStart = 0;
        int teamLink = 0;

        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                // 두 명(i, j)이 모두 방문 처리됐다면 -> 스타트팀
                if (visited[i] && visited[j]) {
                    teamStart += map[i][j];
                    teamStart += map[j][i];
                }
                // 두 명(i, j)이 모두 방문 처리 안 됐다면 -> 링크팀
                else if (!visited[i] && !visited[j]) {
                    teamLink += map[i][j];
                    teamLink += map[j][i];
                }
            }
        }

        // 차이의 절댓값 계산
        int val = Math.abs(teamStart - teamLink);

        // 최솟값 갱신
        if (val == 0) {
            System.out.println(val);
            System.exit(0); // 0이면 더 줄일 수 없으므로 바로 종료
        }

        minDiff = Math.min(val, minDiff);
    }
}
