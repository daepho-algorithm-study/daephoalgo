package baekjoon.Silver.level3;

import java.io.*;
import java.util.*;

public class p2567 { // 백준 2567번 문제, 색종이 - 2
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); // 색종이의 수
        int[][] paper = new int[100][100]; // 명시적인 도화지의 최대크기


        // 도화지에 색종이 면적만큼 색칠하기
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine()); // 색종이의 좌하단 좌표를 줌
            int x = Integer.parseInt(st.nextToken()); // x 좌표
            int y = Integer.parseInt(st.nextToken()); // y 좌표

            // 색종이는 가로, 세로가 10임
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    paper[y + j][x + k] = 1;
                }
            }

        }

        int ans = 0;

        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        // 시작 좌표 찾기
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (paper[i][j] == 1) {
                    // 상하좌우를 확인
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        // 1. 범위 밖으로 나가면? -> 거기가 바로 도화지 끝 경계선임! (카운트 +1)
                        if (ny < 0 || nx < 0 || ny >= 100 || nx >= 100) {
                            ans++;
                        }
                        // 2. 범위 안인데 값이 0이면? -> 빈칸 경계선임! (카운트 +1)
                        else if (paper[ny][nx] == 0) {
                            ans++;
                        }
                    }
                }
            }


        }
        System.out.println(ans);
    }
}