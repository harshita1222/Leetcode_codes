class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)return false;
        String num = Integer.toString(x);
        int left = 0;
        int right = num.length()-1;
        while(left<=right){
            if(num.charAt(left)==num.charAt(right)){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
}