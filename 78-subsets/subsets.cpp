class Solution {
public:
void helper(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, int i){
    if(i==nums.size()){
        result.push_back(current);
        return;
    }
    current.push_back(nums[i]);
    helper(nums,current,result,i+1);
    current.pop_back();
    helper(nums,current,result,i+1);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>current;
        helper(nums,current,result,0);
        return result;
    }
};