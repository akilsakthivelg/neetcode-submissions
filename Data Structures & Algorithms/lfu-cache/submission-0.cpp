class LFUCache {
public:
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> mp;
    unordered_map<int,list<int>> freq;
    unordered_map<int,list<int>::iterator> pos;
    
    LFUCache(int capacity) {
        this->capacity=capacity;
        minFreq=0;
    }
    
    int get(int key) {
        if (mp.find(key)==mp.end()) return -1;
        int val = mp[key].first;
        int f = mp[key].second;
        freq[f].erase(pos[key]);
        if (freq[f].empty() && f==minFreq) minFreq++;
        f++;
        mp[key].second=f;
        freq[f].push_front(key);
        pos[key]=freq[f].begin();
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if (capacity==0) return;
        if (mp.find(key)!=mp.end()) {
            mp[key].first=value;
            get(key);
            return;
        }
        if (mp.size()==capacity) {
            int keyToRemove = freq[minFreq].back();
            freq[minFreq].pop_back();
            mp.erase(keyToRemove);
            pos.erase(keyToRemove);
        }
        mp[key]={value,1};
        freq[1].push_front(key);
        pos[key]=freq[1].begin();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */