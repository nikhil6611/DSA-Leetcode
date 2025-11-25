class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                t.push_back(s[i]-'A'+'a');
            }
            if(s[i]>='a' && s[i]<='z'){
                t.push_back(s[i]);
            }
             if(s[i]>='0' && s[i]<='9'){
                t.push_back(s[i]);
             }
               
            
        }
            int start=0, end= t.size()-1;
            while(start<=end){
                if(t[start]!=t[end]){
                    return false;
                }
                start++;
                end--;
            }
            return true;
        
    }
};