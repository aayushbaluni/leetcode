class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        set<int> row,col;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it:row){
            for(int i=0;i<v[0].size();i++){
                v[it][i]=0;
            }
        }
        for(auto it:col){
            for(int i=0;i<v.size();i++){
                v[i][it]=0;
            }
        }
    }
};