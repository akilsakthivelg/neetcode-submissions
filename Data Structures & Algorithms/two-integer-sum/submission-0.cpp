class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i=0;i<nums.size();i++) {
            int d=target-nums[i];
            if (map[d]>0) {
                return vector<int>{map[d]-1,i};
            }
            map[nums[i]]=i+1;
        }
        return vector<int>{-1,-1};
    }
};
