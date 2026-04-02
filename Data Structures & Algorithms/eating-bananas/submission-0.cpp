class Solution {
public:

    bool canEat(vector<int>& piles,int n,int h) {
        int c=0;
        for (int i=0;i<piles.size();i++) {
            c+= (piles[i]-1)/n + 1;
            if (c>h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int j=*max_element(piles.begin(),piles.end());
        int i=1;
        while (i<=j) {
            int mid = i+(j-i)/2;
            if (canEat(piles,mid,h)) j=mid-1;
            else i=mid+1;
        }
        return i;
    }
};
