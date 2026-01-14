package baekjoon.Gold.level5;

import java.io.*;
import java.util.*;

public class p7576 { // 백준 7576번 문제, 토마토
    static int m, n;
    static int[][] box;
    // 큐를 전역으로 빼서 입력을 받으면서 바로 넣을 수 있게 함
    static Queue<int[]> q = new LinkedList<>();

    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken()); // 가로
        n = Integer.parseInt(st.nextToken()); // 세로

        box = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                box[i][j] = Integer.parseInt(st.nextToken());
                // 입력 받을 때 익은 토마토(1)는 큐에 미리 다 넣음, 여러군데서 동시에 bfs 실행하기 위함
                if (box[i][j] == 1) {
                    q.add(new int[]{i, j});
                }
            }
        }

        // BFS 한번만 돌리기 (매일매일 반복문 돌릴 필요 없음, 이전 시도에서 그렇게 하니 시간초과 발생)
        bfs();

        // 결과 확인
        int maxDay = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 안 익은 토마토가 하나라도 남아있으면 실패 (-1)
                if (box[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
                maxDay = Math.max(maxDay, box[i][j]);
            }
        }

        // 시작할 때 1부터 시작했으니까 실제 걸린 날짜는 -1을 해줘야 함
        // 하루만에 익으면 box값은 2가 됨 -> 정답은 1
        System.out.println(maxDay - 1);
    }

    static void bfs() {
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cy = cur[0];
            int cx = cur[1];

            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    // 안 익은 토마토인 경우에만 익게 만들고 큐에 넣음
                    if (box[ny][nx] == 0) {
                        // 현재 토마토의 날짜 + 1을 저장 (하루 지남)
                        box[ny][nx] = box[cy][cx] + 1;
                        q.add(new int[]{ny, nx});
                    }
                }
            }
        }
    }
}