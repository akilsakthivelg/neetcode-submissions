class Solution {
public:

    // k -> groupSize

    bool isNStraightHand(vector<int>& hand, int k) {
        if (hand.size()%k) return false;
        unordered_map<int,int> m;
        for (auto &x:hand) {
            m[x]++;
        }
        sort(hand.begin(),hand.end());
        for (auto &x:hand) {
            if (m[x]) {
                for (int i=0;i<k;i++) {
                    if (m[x+i]!=0) m[x+i]--;
                    else return false;
                }
            }
        }
        return true;
    }
};
