class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>s;
        int rows=grid.size();
        int col=grid[0].size();
        vector<int>vec;
        int a;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(s.find(grid[i][j])!=NULL){
                 a=grid[i][j];
                 vec.push_back(a);  
                 break; 
                }
                s.insert(grid[i][j]);
            }
        }
        int actualsum=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                actualsum+=grid[i][j];
            }
        }
        int b= (rows*rows)*(rows*rows+1)/2 +a - actualsum;
        vec.push_back(b);
        return vec;

    }
};