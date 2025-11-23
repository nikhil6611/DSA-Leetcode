class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int CHAR[256]={0};
        int i=0, len=INT_MAX;
        int ans_front=-1 ,ans_back= -1;
        if(t.size()==0){
            return ans;
        }
        if(s.size()< t.size()){
            return ans;
        }
        for(int i=0;i<t.size();i++){
            CHAR[t[i]]++;
        }
        int front=0, back=0, count= t.size();
        while(front<s.size()){
            while(count!=0 && front<s.size()){
                
                if(CHAR[s[front]]>0){
                    count--;
                }
                CHAR[s[front]]--;
                front++;
            }
            while(count==0){
                if(front-back < len){
                    len= front-back;
                       ans_front = front-1;
                       ans_back = back;
                }
                CHAR[s[back]]++;
                if(CHAR[s[back]]>0){
                    count++;
                }
                back++;
            }
        }
        if(ans_front!=-1){
            for(int i= ans_back; i<=ans_front;i++){
                  ans.push_back(s[i]);
            }
        }
       
        return ans;
    }
};