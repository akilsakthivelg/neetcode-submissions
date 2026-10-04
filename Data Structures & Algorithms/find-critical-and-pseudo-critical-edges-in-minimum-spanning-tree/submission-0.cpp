class Solution {
public:

    class DSU {
        public:
        vector<int> parent,rank;
        int n;
        DSU(int n) {
            this->n=n;
            parent.resize(n);
            rank.resize(n);
            for (int i=0;i<n;i++) parent[i]=i;
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

    int getMST(int n,vector<vector<int>>& edges,int skip,int force) {
        DSU dsu(n);
        int count=0,cost=0;
        if(force!=-1) {
            dsu.unite(edges[force][0],edges[force][1]);
            count++;
            cost+=edges[force][2];
        }
        for (int i=0;i<edges.size();i++) {
            if (i==skip) continue;
            if (i==force) continue;
            if (dsu.unite(edges[i][0],edges[i][1])) {
                count++;
                cost+=edges[i][2];
            }
        }
        if (count==n-1) return cost;
        return INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i=0;i<edges.size();i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](vector<int>& a,vector<int>&b) {
            return a[2]<b[2];
        });
        int originalCost = getMST(n,edges,-1,-1);
        vector<int> critical,pseudo;
        for (int i=0;i<edges.size();i++) {
            int withoutThisEdge = getMST(n,edges,i,-1);
            if (withoutThisEdge>originalCost) {
                critical.push_back(edges[i][3]);
            } else {
                int withThisEdge = getMST(n,edges,-1,i);
                if (withThisEdge==originalCost) {
                    pseudo.push_back(edges[i][3]);
                }
            }
        }
        return {critical,pseudo};
    }
};