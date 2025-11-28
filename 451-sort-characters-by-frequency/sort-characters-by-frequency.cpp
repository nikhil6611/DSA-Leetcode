class Solution {
public:
    string frequencySort(string s) {
        string ans;
        vector<int>CHAR(256,0);
        vector<int>temp(256,0);
        for(int i=0;i<s.size();i++){
            CHAR[s[i]]++;
            temp[s[i]]++;
        }
        sort(temp.begin(),temp.end(),greater<int>());
        int i=0;
       while(temp[i]!=0&& i<256){
        for(int j=0;j<256;j++){
            if(temp[i]==CHAR[j]){
                while(CHAR[j]){
                    ans.push_back(j);
                    CHAR[j]--;
                }
            }
        }
        i++;
       }
       return ans;
    }
};