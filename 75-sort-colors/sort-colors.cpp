class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0, cnt1=0, cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){cnt0++;}
            else if(nums[i]==1){cnt1++;}
            else cnt2++;
        }
        int index=0;
        for(int i=0;i<cnt0;i++) {nums[index++]=0;}
        for(int i=0;i<cnt1;i++) {nums[index++]=1;}
        for(int i=0;i<cnt2;i++) {nums[index++]=2;}
    }
};