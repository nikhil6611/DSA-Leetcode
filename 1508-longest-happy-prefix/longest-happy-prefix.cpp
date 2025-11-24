class Solution {
public:
    string longestPrefix(string s) {
        vector<int>lps(s.size(),0);
        int pre=0, suff=1;
        string ans="";
        while(suff<s.size()){
            if(s[pre]==s[suff]){
                lps[suff]= pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pre= lps[pre-1];
                }
            }
        }
        
            for(int i=0;i<lps[suff-1];i++){
                         ans.push_back(s[i]);
            }
        
       return ans;
    }
};