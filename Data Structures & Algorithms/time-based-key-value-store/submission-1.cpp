class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (m.find(key)==m.end()) {
            unordered_map<int,string> t;
            t[timestamp]=value;
            m[key] = t;
        }
        else {
            m[key][timestamp]=value;
        }
    }
    
    string get(string key, int timestamp) {
        if (m.find(key)==m.end()) return "";
            while (m[key].find(timestamp)==m[key].end() && timestamp--);
            if(timestamp<=0) return "";
            return m[key][timestamp];
    }
};
