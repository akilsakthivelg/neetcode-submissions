class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n=s.size();
        unordered_map<char,int> lastOccurence;
        for (int i=0;i<n;i++) {
            lastOccurence[s[i]]=i;
        }
        int end=0;
        int size=0; 
        for (int i=0;i<n;i++) {
            size++;
            end=max(end,lastOccurence[s[i]]);
            if (end==i) {
                ans.push_back(size);
                size=0;
            }
        }
        return ans;
        
        
        
        
        
        
        // unordered_map<char,int> totFreq;
        // for (auto c:s) {
        //     totFreq[c]++;
        // }
        // int i=0;
        // int n=s.size();
        // unordered_map<int,int> freq; 
        // vector<int> ans;
        // while (i<n) {
        //     if (freq.find(s[i])==freq.end()) freq[s[i]]=totFreq[s[i]];
        //     int size=1;
        //     freq[s[i]]--;
        //     if (freq[s[i]]==0) freq.erase(s[i]);
        //     i++;
        //     while (freq.size()) {
        //         if (freq.find(s[i])==freq.end()) freq[s[i]]=totFreq[s[i]];
        //         freq[s[i]]--;
        //         if (freq[s[i]]==0) freq.erase(s[i]);
        //         i++;
        //         size++;
        //     }
        //     ans.push_back(size);
        // }
        // return ans;
    }
};
