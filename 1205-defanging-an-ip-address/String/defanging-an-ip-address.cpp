class Solution {
public:
    string defangIPaddr(string address) {
        int i = 0;
        string ans;
        while(address[i]!='\0'){
            if(address[i]=='.'){
               ans+="[.]";
            }
            else{
              ans.push_back(address[i]);
            }
            i++;
        }
        return ans;
    }
};
