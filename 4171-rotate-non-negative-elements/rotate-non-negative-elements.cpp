class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>aux;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                aux.push_back(nums[i]);
            }
        }
        if(aux.size()==0){
            return nums;
        }
        k=k%aux.size();
        reverse(aux.begin(),aux.begin()+k);
        reverse(aux.begin()+k, aux.end());
        reverse(aux.begin(),aux.end());
        int i=0,j=0;
        while(i<nums.size()&&j<aux.size()){
            if(nums[i]>=0){
                nums[i]=aux[j];
                j++;
            }
            i++;
        }
        return nums;
    }
};