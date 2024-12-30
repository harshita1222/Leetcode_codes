class Solution {
    public int[] searchRange(int[] nums, int target) {
        int j=0;
        int result[] = new int[2];
        result[0] = -1;
        result[1] = -1;
        if(nums.length < 1){
            return result;
        }


       for(int i=0;i<nums.length;i++){
        if(nums[i] == target && nums[j] == target){
            result[0] = j;
            result[1] = i;
            
        }
        if(nums[j] != target && j<nums.length-1){
            j++;
        }
       }
       System.out.println(result[0]+" "+result[1]);
        return result;
    }
}