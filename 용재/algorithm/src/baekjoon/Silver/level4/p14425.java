package baekjoon.Silver.level4;

import java.io.*;
import java.util.*;

public class p14425 { // 백준 14425번 문제, 문자열 집합 (집합과 맵)
    public static void main(String[] args) throws IOException {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N =Integer.parseInt(st.nextToken()); //집합 S의 개수
        int M =Integer.parseInt(st.nextToken()); //비교할 대상의 문자열 개수

        //집합 S 문자열들의 중복을 제거 해당 집합 S에 같은 값이 있으면 집합에 하나로 속하는 것으로 해야함
        Set<String> array = new HashSet<>();

        for(int i = 0; i < N; i++) {
            array.add(br.readLine()); //중복 제거해서 넣고
        }

        int count = 0; //집합 S의 문자열에 비교할 대상의 문자열이 몇개가 속하는지 저장하는 변수

        for(int i = 0; i < M; i++) {
            String str = br.readLine();

            if(array.contains(str)) { //비교할 대상의 문자열이 해당 HashSet 안에 집합 S에 있는 문자열에 포함된다면
                count++; //집합에 속하기 때문에 count를 한다. => 중복을 제거했기 때문에 그냥 증가시켜도 됨.
            }
        }
        br.close();

        System.out.println(count);
    }
}
