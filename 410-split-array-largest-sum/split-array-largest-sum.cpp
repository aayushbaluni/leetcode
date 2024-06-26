class Solution {
public:
    bool solve(vector<int> v,int mid,int k){
        int i=0;
        int sum=0;
        int maxi=0;
        int cnt=0;
        int n=v.size();
        while(i<n){
            sum+=v[i];
            if(v[i]>mid)return false;
            if(sum==mid){
                cnt++;
                sum=0;
            } else {
                if(sum>mid){
                    sum=v[i];
                    cnt++;
                }
            }
            i++;
        }
        if(sum)cnt++;
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=1000000000;
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(solve(nums,mid,k)){
                ans=min(ans,mid);
                r=mid-1;
            } else l=mid+1;

        }
        return ans;
    }
};