class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m; 
        unordered_map<char,int> n; 
        for(auto c : t){
            m[c]++;
        }

        int required = m.size(); 
        int formed = 0;          
        int l = 0, r = 0;         
        int minLen = INT_MAX;     
        int start = 0;               
        while(r < s.size()){
            n[s[r]]++; 

            if(m.count(s[r]) && n[s[r]] == m[s[r]]){
                formed++;
            }

            
            while(l <= r && formed == required){
                
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }
  
                n[s[l]]--;
                if(m.count(s[l]) && n[s[l]] < m[s[l]]){
                    formed--;
                }
                l++; 
            }
            r++; 
        }    
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};