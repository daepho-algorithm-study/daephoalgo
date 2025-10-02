package Programmers;

import java.util.*;

public class arrangement_2 {

    // 1. 문자열 변환
    // 2. 숫자 놀이
    
    // 2번 방법으로 접근


    // 보조용 함수
    // 자리수가 5나 0인지 확인하는 기능을 가진 함수
    private boolean check(int number) {
        while (number > 0) {
            int check = number % 10;
            if (check != 0 && check != 5) {
                return false;
            }
            number /= 10;
        }
        return true;
    }


    public int[] solution(int l, int r) {

        
        List<Integer> checkList = new ArrayList<>();
        
        for (int left = l; left <= r; left++) {
            if (check(left)) {
                checkList.add(left);
            }
        }
        
        // 아무것도 없으면 반
        if (checkList.isEmpty()) {
            return new int[]{-1};
        }


        int[] answer = new int[checkList.size()];

        for (int index = 0; index < checkList.size(); index++) {
            answer[index] = checkList.get(index);
        }
        return answer;
    }

}

