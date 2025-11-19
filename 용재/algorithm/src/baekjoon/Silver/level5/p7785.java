package baekjoon.Silver.level5;

import java.io.*;
import java.util.*;

public class p7785 { // 백준 7785번 문제, 회사에 있는 사람 (집합과 맵)
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> checkList = new HashMap<>();
        for(int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String status= st.nextToken();
            if(checkList.containsKey(name)) {
                checkList.remove(name);
            }else {
                if(status.equals("enter")){
                    checkList.put(name, 1);
                }
            }
        }

        StringBuilder sb= new StringBuilder();
        List<String> curList = new ArrayList<>(checkList.keySet());
        Collections.sort(curList,(a,b) -> b.compareTo(a));
        for(String s : curList) {
            sb.append(s+"\n");
        }
        System.out.println(sb.toString());

    }
}