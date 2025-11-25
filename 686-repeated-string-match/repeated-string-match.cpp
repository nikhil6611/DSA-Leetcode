class Solution {
public:
    bool kmp_match(string &a, string &sub){
      vector<int>lps(sub.size(),0);
      int pre=0, suff=1;
      while(suff<sub.size()){
        if(sub[pre]==sub[suff]){
            lps[suff]=pre+1;
            pre++;
            suff++;
        }
        else if(pre==0){
            lps[suff]=0;
            suff++;
        }
        else{
            pre= lps[pre-1];
        }
      }
      int mainindex=0, subindex=0;
      while(mainindex<a.size()){
        if(a[mainindex]==sub[subindex]){
            mainindex++;
            subindex++;
        }
        else if (subindex==0){
            mainindex++;
        }
        else{
            subindex = lps[subindex-1];
        }
        if(subindex==sub.size()){
            return true;
        }
      }
      return false;
    }
    int repeatedStringMatch(string a, string b) {
        string temp =a;
        if(a==b){
            return 1;
        }
        int repeat=1;
        while(temp.size()<b.size()){
            temp+=a;
            repeat++;
        }
        if(kmp_match(temp,b)){
            return repeat;
        }
        temp+=a;
        repeat++;
        if(kmp_match(temp,b)){
            return repeat;
        }
        return -1;
    }
};