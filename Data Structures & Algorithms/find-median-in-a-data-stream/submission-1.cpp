class MedianFinder {
public:

vector<int> arr;


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
        sort(arr.begin(),arr.end());
    }
    
    double findMedian() {
        int n=arr.size();
        if (n&1) return arr[n/2];
        return (0.0+arr[n/2]+arr[n/2-1])/2;
    }
};
