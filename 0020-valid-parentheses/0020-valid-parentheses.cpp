class Solution {
public:
    bool isValid(string s){
        if(s.length()%2!=0) return false;
        if(s.length()==0) return true;
        
        char myStack[s.length()];
        int stackLoc = 0;
        
        myStack[stackLoc] = s[0];
        stackLoc++;
        
        for(int i=1; i<s.length(); i++){
            if(stackLoc==0){
                myStack[stackLoc] = s[i];
                stackLoc++;
                continue;
            }
            
            char end = '*';
            if(myStack[stackLoc-1]=='(') end=')';
            else if(myStack[stackLoc-1]=='{') end='}';
            else if(myStack[stackLoc-1]=='[') end=']';
            
            if(s[i]==end){
                myStack[stackLoc-1] = '\0';
                stackLoc--;
            }
            else{
                myStack[stackLoc] = s[i];
                stackLoc++;
            }
        }
        
        if(myStack[0]!='\0') return false;
        
        return true;
    }
};