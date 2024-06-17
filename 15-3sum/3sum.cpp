class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        // set<vector<int>>st;
        sort(v.begin(),v.end());
        int n=v.size();
        set<vector<int>>st;
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=v[i]+v[l]+v[r];
                if(sum==0){
                    st.insert({v[i],v[l],v[r]});
                    l++;
                    r--;
                } else if(sum>0){
                    r--;
                } else l++;
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};