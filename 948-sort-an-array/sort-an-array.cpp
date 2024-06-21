class Solution {
public:
    void merge(vector<int> &arr,int low,int mid,int high){
        int l=low;
        int r=mid+1;
        vector<int> v;
        while(l<=mid && r<=high){
            if(arr[l]>arr[r]){
                v.push_back(arr[r]);
                r++;
            } else{
                v.push_back(arr[l]);
                l++;
            }
        }
        for(int i=l;i<=mid;i++){
            v.push_back(arr[i]);
        }
        for(int i=r;i<=high;i++){
            v.push_back(arr[i]);
        }
        for(int i=low;i<=high;i++){
         arr[i]=v[i-low];   
        }
        return;
    }
    void mergeSort(vector<int> &arr,int low,int high){
        if(low>=high)return;
        int mid=(low+high)/2;
       
         mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
      
       return;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};