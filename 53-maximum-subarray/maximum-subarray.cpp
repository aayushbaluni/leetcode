class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int curr=0;
        for(auto it:nums){
            curr=max({curr+it,it});
            ans=max(ans,curr);
        }
        return ans;
    }
};