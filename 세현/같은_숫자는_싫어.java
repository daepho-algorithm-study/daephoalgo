import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> list = new ArrayList<>();
        
        list.add(arr[0]);
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[i-1]) {
                list.add(arr[i]);
            }
        }
        
        // 중간 연산의 종류: stream(), filter(), map(), boxed(), sorted()...
        // 중간 연산은 단독으로 실행되지 않음. 
        
        // mapToInt() -> Stream<Integer> → IntStream 으로 변환하는 메서드
        //      map() 이랑 비슷하게 동작함. 결과가 IntStream (primitive) 으로 나옴
	// Integer::intValue -> Integer 객체를 int 로 꺼내는 메서드(언박싱)
        // toArray() -> Stream을 배열로 수집함
        
        // Java에서 int 와 Integer은 다름. int는 Primative, Integer는 정수 객체를 의미함
        // Primative -> int, long, double, float, boolean, char, byte, short (8개)
        
        return list.stream().mapToInt(Integer::intValue).toArray();
        
    }
}