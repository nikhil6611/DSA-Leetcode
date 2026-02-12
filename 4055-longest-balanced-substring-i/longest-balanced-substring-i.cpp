class Solution {
public:
    int longestBalanced(string s) {
        int ans=0,temp=0;
        for(int i=0;i<s.size();i++){
            vector<int>freq(26,0);
            for(int j=i;j<s.size();j++){
                bool flag= true;
                freq[s[j]-'a']++;
                temp= freq[s[j]-'a'];
                for(int i=0;i<26;i++){
                    if(freq[i]!=temp && freq[i]!=0){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    ans= max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};