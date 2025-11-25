class Solution {
public:
    bool kmp_match(string &t, string &goal){
        vector<int>lps(goal.size(),0);
        int pre=0, suff=1;
        while(suff<goal.size()){
            if(goal[pre]==goal[suff]){
                lps[suff]= pre+1;
                pre++;
                suff++;
            }
            else if(pre==0){
                lps[suff]=0;
                suff++;
            }
            else{
                pre = lps[pre-1];
            }
        }
        int mainindex=0, subindex=0;
        while(mainindex<t.size()){
            if(t[mainindex]==goal[subindex]){
                mainindex++;
                subindex++;
            }
            else if(subindex==0){
                mainindex++;
            }
            else{
                subindex = lps[subindex-1];
            }
            if(subindex==goal.size()){
                return true;
            }
        }
        return false;
    }
    bool rotateString(string s, string goal) {
        if(s==goal){
            return true;
        }
       if(s.size()!=goal.size()){
        return false;
       }
       string t=s;
       t+=s;
       return kmp_match(t,goal);
       
    }
};