package baekjoon.Gold.level5;

import java.io.*;
import java.util.*;

/**
 * 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
 * 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
 * 2-1.바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
 * 2-2.바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
 * 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
 * 3-1. 반시계 방향으로 90도 회전한다.
 * 3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
 * 3-3. 1번으로 돌아간다.
 */
public class p14503 { // 백준 14503번 문제, 로봇 청소기
    static int n, m;
    static int total = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[][] room = new int[n][m]; // 방 크기
        st = new StringTokenizer(br.readLine());

        int si = Integer.parseInt(st.nextToken()); // 시작 i 좌표
        int sj = Integer.parseInt(st.nextToken()); // 시작 j 좌표
        int sd = Integer.parseInt(st.nextToken()); // 시작 방향

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                room[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        clean(room, si, sj, sd);
        System.out.print(total);
    }

    static void clean(int[][] room, int i, int j, int d) {

        // 반시계 방향 회전
        int[] di = {-1, 0, 1, 0};
        int[] dj = {0, 1, 0, -1};
        // 1. 현재칸이 청소되어 있지 않다면 현재칸 청소
        int cnt = 0;
        if (room[i][j] == 0) {
            room[i][j] = 2;
            total++;
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                if (room[ni][nj] == 0) {
                    // 바라보는 방향에 청소안한 칸 있는경우
                    cnt++;
                }
            }
        }
        // 2. 현재칸 주변 4칸중 청소되지 않은 빈 칸이 없는 경우
        if (cnt == 0) {
            // 2-1 바라보는 방향을 유지한 채로 한칸 후진하고 1번으로 돌아간다.
            int bi = i, bj = j;
            if (d == 0) bi += 1;
            else if (d == 1) bj -= 1;
            else if (d == 2) bi -= 1;
            else if (d == 3) bj += 1;
            // 범위 체크 AND 벽(1)이 아닌지 체크
            if (bi >= 0 && bj >= 0 && bi < n && bj < m && room[bi][bj] != 1) {
                clean(room, bi, bj, d); // 방향 유지한 채 후진
            } else {
                return; // 벽이면 종료
            }
        } else {
            // 반시계 90도 회전: (d+3)%4
            // 북(0)->서(3)->남(2)->동(1)
            int nd = (d + 3) % 4;

            // 바라보는 앞쪽 좌표
            int ni = i + di[nd];
            int nj = j + dj[nd];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m && room[ni][nj] == 0) {
                clean(room, ni, nj, nd); // 앞이 0이면 전진
            } else {
                clean(room, i, j, nd); // 앞이 0이 아니면 회전만 한 상태로 다시 탐색(재귀)
            }
        }
    }
}

