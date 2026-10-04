class Solution {
public:

    void dfs(int n,unordered_map<int,vector<int>>& adj,unordered_set<int>& visited) {
        visited.insert(n);
        for (auto x:adj[n]) {
            if (!visited.count(x)) {
                dfs(x,adj,visited);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return true;
        if (find(nums.begin(),nums.end(),1)!=nums.end()) return false;
        int mx=*max_element(nums.begin(),nums.end());
        sort(nums.begin(), nums.end()), nums.erase(unique(nums.begin(), nums.end()), nums.end());
        vector<int> sieve(mx+1,0);
        for (int i=2;i*i<=mx;i++) {
            if (sieve[i]==0) {
                for (int j=i*i;j<=mx;j+=i) {
                    sieve[j]=i;
                }
            }
        }
        unordered_map<int,vector<int>> adj;
        for (auto x:nums) {
            int num=x;
            while (num>1) {
                int prime = (sieve[num]==0)?num:sieve[num];
                adj[x].push_back(mx+prime);
                adj[mx+prime].push_back(x);
                while (num%prime==0) num/=prime;
            }
        }
        unordered_set<int> visited;
        dfs(nums[0],adj,visited);
        for (auto x:nums) if (!visited.count(x)) return false;
        return true;
    }
};