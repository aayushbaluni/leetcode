class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m)return findMedianSortedArrays(nums2,nums1);
        int l=0;
        int r=n;
        int last=(n+m+1)/2;
        while(l<=r){
            int mid=(l+r)/2;
            int mid2=(last-mid);
           int r1=INT_MAX,r2=INT_MAX,l1=INT_MIN,l2=INT_MIN;
           if(mid<n){
            r1=nums1[mid];
           }
           if(mid>0){
                l1=nums1[mid-1];
            }
           if(mid2<m){
            r2=nums2[mid2];
           }
            if(mid2>0){
                l2=nums2[mid2-1];
            }
            if(l1<=r2 && l2<=r1){
                if((n+m)%2){
                    return (double)(max(l1,l2));
                }else {
                    return (double)((double)(max(l1,l2)+min(r1,r2))/2.0);
                }
            }
            else {
                if(l1>r2){
                    r=mid-1;
                }else l=mid+1;
            }  
        }
        return 0;
    }
};