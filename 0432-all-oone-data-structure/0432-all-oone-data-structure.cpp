class AllOne {
public:
    map<string, int> mp; 
    set<pair<int, string>> freqSet; 

    AllOne() {}

    void inc(string key) {
        if(mp.find(key) != mp.end()) {
            freqSet.erase({mp[key], key});
        }
        mp[key]++;
        freqSet.insert({mp[key], key});
    }

    void dec(string key) {
        if(mp.find(key) != mp.end()) {
            freqSet.erase({mp[key], key});
            mp[key]--;
            if(mp[key] == 0) {
                mp.erase(key);
            } else {
                freqSet.insert({mp[key], key});
            }
        }
    }

    string getMaxKey() {
        if(freqSet.empty()) return "";  
        return freqSet.rbegin()->second;
    }

    string getMinKey() {
        if(freqSet.empty()) return ""; 
        return freqSet.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */