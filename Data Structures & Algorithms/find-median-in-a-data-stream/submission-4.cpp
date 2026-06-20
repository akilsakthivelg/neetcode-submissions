class MedianFinder {
public:

    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (small.empty() && large.empty()) small.push(num);
        else if (small.empty() || large.empty()) small.push(num);
        else if (small.top()<=num && large.top()>=num) small.push(num);
        else if (small.top()>=num) small.push(num);
        else large.push(num);
        if (small.size()+1<large.size()) {
            small.push(large.top());
            large.pop();
        }
        if (small.size()>large.size()+1) {
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if (small.size()==large.size()) return (small.top()+large.top())/2.0;
        if (small.size()>large.size()) return small.top();
        return large.top();
    }
};
