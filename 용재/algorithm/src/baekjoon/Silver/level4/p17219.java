package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p17219 { // 백준 17219번 문제, 비밀번호 찾기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 사이트의 주소 수 n
        int m = Integer.parseInt(st.nextToken()); // 찾으려는 사이트 주소의 수 m

        HashMap<String, String> site = new HashMap<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            site.put(st.nextToken(), st.nextToken());
        }

        for (int j = 0; j < m; j++) {
            String target = br.readLine();

            System.out.println(site.get(target));

        }
    }
}
