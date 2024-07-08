class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m;
        while(l<=h){
            int mid=(l+h)/2;
            int maxi=INT_MIN;
            int index=-1;
            for(int i=0;i<n;i++){
                // maxi=max(maxi,mat[i][mid]);
                if(maxi<mat[i][mid]){
                    maxi=mat[i][mid];
                    index=i;
                }
            }
            int left=mid==0?-1:mat[index][mid-1];
            int right=mid==m-1?-1:mat[index][mid+1];
            if(maxi>left && maxi>right){
                return {index,mid};
            }else if(maxi>left)l=mid+1;
            else h=mid-1;
        }
        return {-1,-1};
    }
};