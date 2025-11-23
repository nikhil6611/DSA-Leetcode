class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int CHAR[256]={0};
        int front=0, back=0,len=0;
        while(front < s.size()){
           
                while(CHAR[s[front]]!=0){
                CHAR[s[back]]=0;
                back++;
            }
           
                CHAR[s[front]]++;
                len = max(len, front-back+1);
                front++;
            
            
        
        }
        return len;
    }
};