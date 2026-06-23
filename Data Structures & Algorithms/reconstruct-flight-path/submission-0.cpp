class Solution {

public:


    void dfs(string a,unordered_map<string,vector<string>>& adj,vector<string>& ans) {
        vector<string> &s=adj[a];
        while (!s.empty()) {
            string t=s.back();
            s.pop_back();
            dfs(t,adj,ans);
        }
        ans.push_back(a);
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        unordered_map<string,vector<string>> adj;
        for (auto x:tickets) {
            adj[x[0]].push_back(x[1]);
        }
        for (auto &x:adj) sort(x.second.rbegin(),x.second.rend());
        vector<string> ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
