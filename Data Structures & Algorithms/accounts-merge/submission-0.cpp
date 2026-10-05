class Solution {
public:

    class DSU {
        public:
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            for (int i=0;i<n;i++) {
                parent[i]=i;
            }
        }
        int find(int x) {
            if (parent[x]==x) return x;
            return find(parent[x]);
        }
        bool unite(int a,int b) {
            a=find(a);
            b=find(b);
            if (a==b) return false;
            parent[b]=a;
            return true;
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        DSU dsu(n);
        unordered_map<string,int> m;
        for (int i=0;i<n;i++) {
            for (int j=1;j<acc[i].size();j++) {
                if (m.count(acc[i][j])) {
                    dsu.unite(i,m[acc[i][j]]);
                } else {
                    m[acc[i][j]]=i;
                }
            }
        }
        unordered_map<int,vector<string>> m2;
        for (auto x:m) {
            int top = dsu.find(x.second);
            m2[top].push_back(x.first);
        }
        vector<vector<string>> ans;
        for (auto x:m2) {
            x.second.insert(x.second.begin(),acc[x.first][0]);
            ans.push_back(x.second);
        }
        return ans;
    }
};