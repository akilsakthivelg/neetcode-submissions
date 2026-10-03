class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=n;
        int i=1;
        while (i<n) {
            if (ratings[i]==ratings[i-1]) i++;
            int inc=0;
            while (i<n && ratings[i]>ratings[i-1]) {
                inc++;
                ans+=inc;
                i++;
            }
            int dec=0;
            while(i<n && ratings[i]<ratings[i-1]) {
                dec++;
                ans+=dec;
                i++;
            }
            ans-=min(inc,dec);
        }
        return ans;
    }
};