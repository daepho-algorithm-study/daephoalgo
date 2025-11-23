package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p1764 { // 백준 1764번 문제, 듣보잡 (집합과 맵)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());


        HashSet<String> hear = new HashSet<>();

        for (int i = 0; i < N; i++) { // 듣도 못한 사람
            String human = br.readLine();
            hear.add(human);
        }
//        System.out.print(hear); // 듣도 못한 사람 확인
        ArrayList<String> ans = new ArrayList<>();

        for (int j = 0; j < M; j++) {
            String human = br.readLine();
            if (hear.contains(human)) {
                ans.add(human);
            }
        }

        Collections.sort(ans);

        System.out.println(ans.size());
//        for (String s : ans) {
//            System.out.println(s);
//        }

        for (int s = 0; s<ans.size(); s++) {
            System.out.println(ans.get(s));
        }
    }
}
