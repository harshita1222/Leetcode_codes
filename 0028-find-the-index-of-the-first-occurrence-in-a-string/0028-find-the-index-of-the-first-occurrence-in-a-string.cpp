class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; 

        int i = 0, j = 0; 
        int m = haystack.size(), n = needle.size();

        while (i < m) {
            if (haystack[i] == needle[j]) {
                
                i++;
                j++;
                
                if (j == n) {
                    return i - j; 
                }
            } else {
                
                i = i - j + 1; 
                j = 0;         
            }
        }

        return -1; 
    }
};
