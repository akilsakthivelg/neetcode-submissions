class Solution {
public:

    int bs(vector<int>& nums,int target,int i,int j) {
        while (i<=j) {
            int mid = i+(j-i)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]>target) j=mid-1;
            else i=mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        while (i<j) {
            int mid = i+(j-i)/2;
            if (nums[mid] >= nums[n-1]) i=mid+1;
            else j=mid;
        }
        
        if (target<=nums[n-1]) return bs(nums,target,i,n-1);
        else return bs(nums,target,0,i-1);
    }
};
