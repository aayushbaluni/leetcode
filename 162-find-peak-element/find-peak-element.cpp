class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=0;
        int l=0;
        int r=nums.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(mid!=0 && mid!=nums.size()-1){
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]){
                return mid;
            }
        }
         if(mid!=0){
          if(nums[mid-1]<nums[mid]) {
            ans=mid;
            l=mid+1;
          } 
          else r=mid-1;
         }else {
            l=mid+1;
         }
    }
    return ans;
    }
};