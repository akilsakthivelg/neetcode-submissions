class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        map<int,int> m;
        for (auto x:nums) m[x]++;
        int ans=0;
        int c=0;
        int prev=m.begin()->first;
        for (auto x:m) {
            if(x.first==prev) continue;
            if (prev+1==x.first) c++;
            else c=0;
            prev=x.first;
            ans=max(c,ans);
        }
        ans++;
        return ans;
    }
};
