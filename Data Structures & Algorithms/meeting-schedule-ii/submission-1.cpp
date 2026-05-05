/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int,vector<int>, greater<>> pq;
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){
            return a.start<b.start;
        });
        int ans=0;
        for (auto x:intervals) {
            if (pq.empty() || pq.top()>x.start) {
                pq.push(x.end);
                ans=max(ans,(int)pq.size());
            }
            else {
                pq.pop();
                pq.push(x.end);
            }
        }
        return ans;
    }
};
