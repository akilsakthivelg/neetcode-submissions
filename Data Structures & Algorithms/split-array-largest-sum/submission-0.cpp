class Solution {
public:

    bool canSplit(vector<int>& nums,int k,int maxsum) {
        int c=0;
        int sum = 0;
        for (auto &x : nums) {
            if (sum+x>maxsum) {
                c++;
                sum=x;
            } else sum+=x;
        }
        c++;
        return c<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int i=*max_element(nums.begin(),nums.end());
        int j=accumulate(nums.begin(),nums.end(),0);
        while (i<=j) {
            int m=i+(j-i)/2;
            if (canSplit(nums,k,m)) j=m-1;
            else i=m+1;
        }
        return i;
    }
};