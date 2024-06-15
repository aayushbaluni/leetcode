class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        for(auto it:nums){
            sum+=it;
            if(sum==k)ans++;
            if(mp[sum-k])ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};