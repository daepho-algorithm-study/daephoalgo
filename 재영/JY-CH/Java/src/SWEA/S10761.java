package SWEA;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class S10761 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        class tuple {
            String color;
            int number;

            public tuple(String color, int number) {
                this.color = color;
                this.number = number;
            }
        }

        int tc = Integer.parseInt(br.readLine());

        for (int test = 1; test <= tc; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int button = Integer.parseInt(st.nextToken());

            List<tuple> list = new ArrayList<>();

            for (int i = 0; i < button; i++) {
                String color = String.valueOf(st.nextToken());
                int number = Integer.parseInt(st.nextToken());

                list.add(new tuple(color, number));
            }
            
            // 순서대로 눌러야한다
            // 남는 로봇 하나가 버튼을 누르는 시간동안
            // 딴놈도 이동이 가능하다. 단지 버튼만 못누른다.
            // 마지막 버튼 누른 시간과, 현재 시간이 흘러간 것을 비교한다.

            int posBlue = 1;
            int posOrange = 1;

            int timeBlue = 0;
            int timeOrange = 0;

            int totalTime = 0;
            
            for (int i = 0; i < list.size(); i++) {

                tuple check = list.get(i);

                if (check.color.equals("B")) {
                    // 현재위치에서 버튼 위치까지 소요시간
                    int moveTime = Math.abs(posBlue - check.number);
                    // 마지막에 버튼 누른 시간에 이동시간을 더한것
                    int readyTime = timeBlue + moveTime;

                    // totalTime이 많을 경우
                    // 이쪽은 한참 전에 준비가 됬는데 저 쪽이 아직도 버튼을 못누름
                    // readyTime이 많을 경우
                    // 이미 이전에 저쪽은 버튼을 눌렀는데 얘는 아직 버튼 누를 준비도 안된거임
                    // 그래서 max에 버튼 누르는 시간 + 1
                    totalTime = Math.max(totalTime, readyTime) + 1;
                    
                    // 마지막 버튼 누른 시점 저장
                    timeBlue = totalTime;
                    // 현재 위치 변경
                    posBlue = check.number;
                } else {
                    // 오렌지일경우, 로직은 위와 동일
                    int moveTime = Math.abs(posOrange - check.number);
                    int readyTime = timeOrange + moveTime;

                    totalTime = Math.max(totalTime, readyTime) + 1;

                    timeOrange = totalTime;
                    posOrange = check.number;
                }
            }



            bw.write("#" + test + " " + totalTime + "\n");



        }

        bw.close();
        br.close();
    }


}
