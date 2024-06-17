class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        int n=v.size();
        sort(v.begin(),v.end());
        // map<int,vector<int>> mp;
        set<vector<int>> st;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum=(v[i]*1ll+v[j]*1ll+v[l]*1ll+v[r]*1ll);
                    if(sum==target){
                        st.insert({v[i],v[j],v[l],v[r]});
                        l++;
                        r--;
                    } else if(sum>target){
                        r--;
                    } else l++;
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};