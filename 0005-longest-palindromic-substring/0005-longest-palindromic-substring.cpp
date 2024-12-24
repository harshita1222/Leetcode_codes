class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int i=0;i<2*s.length()-1;i++){
            int left=i/2;
            int right=left+i%2;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>ans.length()){
                ans=s.substr(left+1,right-left-1);
            }
        }
        return ans;
    }
};