class Solution {
public:
    bool f(vector<int> v,int d,int t){
        int ans=0;
        if(d==0)return false;
        for(auto it:v){
            ans+=ceil(((double)it)/((double)(d)));
        }
        return ans<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=0;
        int r=1000000000;
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(nums,mid,threshold)){
                ans=min(ans,mid);
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        return ans;
    }
};