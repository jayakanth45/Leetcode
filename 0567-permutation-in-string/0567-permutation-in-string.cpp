class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if (s1.size() > s2.size()) return false;
    
    unordered_map<char, int> um;
    // Count frequencies of characters in s1
    for (char c : s1) {
        um[c]++;
    }
    
    int count = um.size(); // Number of distinct characters in s1
    int k = s1.size();
    
    int j = 0; // Sliding window start
    
    // Sliding window over s2
    for (int i = 0; i < s2.size(); i++) {
        if (um.find(s2[i]) != um.end()) {
            um[s2[i]]--;
            if (um[s2[i]] == 0) count--; // One character fully matched
        }
        
        if (i - j + 1 == k) {
            if (count == 0) return true; // All characters matched
            
            // Move left side of the window
            if (um.find(s2[j]) != um.end()) {
                if (um[s2[j]] == 0) count++; // Unmatch the character
                um[s2[j]]++;
            }
            j++;
        }
    }
    
    return false;
    }
};