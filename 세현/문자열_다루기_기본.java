class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        
        if (s.length() < 4 || s.length() == 5 || s.length() > 6) return false;
        
        for (int i = 0; i < s.length(); i++) {
            if (Character.isLetter(s.charAt(i))) return false;
        }
        
        return answer;
    }
}