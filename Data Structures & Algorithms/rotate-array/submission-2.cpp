class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        int i=0;
        vector<int> a;
        for (i=0;i<k;i++) {
            a.push_back(nums[n-i-1]);
        }
        for (int j=n-k-1;j>=0;j--) {
            nums[k+j]=nums[j];
        }
        for (int i=0;i<k;i++) {
            nums[i]=a[k-i-1];
        }
    }
};