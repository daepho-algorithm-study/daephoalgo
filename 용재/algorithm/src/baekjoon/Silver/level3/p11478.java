package baekjoon.Silver.level3;

import java.util.*;
import java.io.*;

public class p11478 { // 백준 11478, 서로 다른 부분 문자열의 갯수 (집합과 맵)

    static HashSet<String> result = new HashSet<>();

    public static Integer makeWord(char[] arr, int n) {
        if (n == arr.length) return 0;
        StringBuilder sb = new StringBuilder();
        for (int i = n; i < arr.length; i++) {
            sb.append(arr[i]);
            result.add(sb.toString());
        }
        makeWord(arr, n + 1);

        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String words = br.readLine();

        char[] word = new char[words.length()];

        for (int i = 0; i < words.length(); i++) {
            word[i] = words.charAt(i);
        }
        makeWord(word, 0);


        bw.write(String.valueOf(result.size()));
        bw.flush();


        br.close();
        bw.close();

    }
}
