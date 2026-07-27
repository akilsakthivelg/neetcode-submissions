class Solution {
public:
    int helper(int i,vector<int>& nums,int x) {
        if (i>=nums.size()) return x;
        int tk = helper(i+1,nums,x^nums[i]);
        int ntk= helper(i+1,nums,x);
        return tk+ntk;
    } 
    int subsetXORSum(vector<int>& nums) {
        return helper(0,nums,0);
    }
};