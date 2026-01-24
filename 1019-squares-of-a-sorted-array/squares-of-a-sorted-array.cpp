class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>arr(nums.size());
       int index = nums.size()-1;
     int i=0, j= nums.size()-1;
     while(i<=j){
        if(nums[j]*nums[j]> nums[i]*nums[i]){
            arr[index]= nums[j]*nums[j];
            j--;
        }
        else{
            arr[index]=nums[i]*nums[i];
            i++;
        }
        index--;
     }
     return arr;
    }
};