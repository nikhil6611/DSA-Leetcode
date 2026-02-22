class Solution {
public:
     vector<vector<int>>ans;
   void makesubset(vector<int>& nums, vector<int>&subset,int idx){
       
        if(idx==nums.size()){
            ans.push_back(subset);
            return;
        }
        
            subset.push_back(nums[idx]);
            makesubset(nums,subset,idx+1);
            subset.pop_back();
            makesubset(nums,subset,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       ans.clear();
        vector<int>subset;
        makesubset(nums,subset,0);
        return ans;
        
    }
};