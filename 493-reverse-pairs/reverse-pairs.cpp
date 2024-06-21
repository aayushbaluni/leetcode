#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> 
 
class Solution {
public:
    int merge(vector<int> &arr,int low,int mid,int high){
      int l = low;
      int r=mid+1;
      long long int cnt=0;
      vector<int> temp;
      while(l<=mid && r<=high){
          if(arr[l]<=arr[r]){
                temp.push_back(arr[l]);
                l++;
          }else {
             if(arr[l]>(2*1ll*arr[r])) cnt+=mid-l+1;
              temp.push_back(arr[r]);
              r++;
          }
      }
      while(l<=mid){
          temp.push_back(arr[l]);
          l++;
      }
      while(r<=high){
         
          temp.push_back(arr[r]);
          r++;
      }
      for(int i=low;i<=high;i++){
          arr[i]=temp[i-low];
      }
      return cnt;
  }
    int mergeSort(vector<int> &arr,int low,int high){
        if(low>=high)return 0;
        long long int cnt=0;
        int mid=(low+high)/2;
        cnt+=mergeSort(arr,low,mid);
        cnt+=mergeSort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        ordered_set st;
        long long maxi=0;
        for(auto it:nums)maxi=max(maxi,it*1ll);
        maxi++;
        int ans=0;
        for(auto it:nums){
            long long tf=it*1ll*2;
            tf++;
            int l=st.order_of_key(tf);
            int r=st.order_of_key(maxi);
            ans+=r-l;
            st.insert(it);
        }
        return ans;
    }
};