class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while (i<=j) {
            int m=i+(j-i)/2;
            if (nums[m]==target) return true;
            if (nums[m]>nums[i]) {
                if (nums[i]<=target && target<=nums[m]) j=m-1;
                else i=m+1;
            } else if (nums[m]<nums[i]) {
                if (nums[m]<target && nums[j]>=target) i=m+1;
                else j=m-1;
            } else i++;
        }
        return false;
    }
};