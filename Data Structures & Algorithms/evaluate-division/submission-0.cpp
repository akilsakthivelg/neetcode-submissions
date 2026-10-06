class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string,unordered_map<string,double>> m;
        for (int i=0;i<n;i++) {
            m[equations[i][0]][equations[i][1]]=values[i];
            m[equations[i][1]][equations[i][0]]=1.0/values[i];
        }
        for (auto &x1:m) {
            for (auto &x2:m[x1.first]) {
                for (auto &x3:m[x1.first]) {
                    if (!m[x2.first].count(x3.first)) {
                        m[x2.first][x3.first]=m[x1.first][x3.first]/m[x1.first][x2.first];
                    }
                }
            }
        }
        vector<double> ans;
        for (auto &x:queries) {
            if (m.count(x[0])==0 || m[x[0]].count(x[1])==0) ans.push_back(-1);
            else ans.push_back(m[x[0]][x[1]]);
        }
        return ans;
    }
};