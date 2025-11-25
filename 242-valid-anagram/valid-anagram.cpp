class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int CHAR[256]={0};
        for(int i =0;i<s.size();i++){
            CHAR[s[i]]++;
            CHAR[t[i]]--;
        }
        for(int i=0; i<256;i++){
            if(CHAR[i]!=0){
                return false;
            }
        }
        return true;
    }
};