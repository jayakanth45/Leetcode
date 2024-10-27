class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        std::vector<int> hashmap(26);
        for (char letter : s) {
            ++hashmap[int(letter) - 97];
        }
        int MOD = 1000000007;
        for (int rep = 0; rep < t; ++rep) {
            std::vector<int> new_hashmap(26);
            for (int letter = 0; letter < 26; ++letter) {
                if (letter == 25) {
                    new_hashmap[0] = (new_hashmap[0] + hashmap[25]) % MOD;
                    new_hashmap[1] = (new_hashmap[1] + hashmap[25]) % MOD;
                } else {
                    new_hashmap[letter + 1] = (new_hashmap[letter + 1] + hashmap[letter]) % MOD;
                }
            }
            hashmap = new_hashmap;
        }
        int countFreq = 0;
        for (int freq : hashmap) {
            countFreq = (countFreq + freq) % MOD;
        }
        return countFreq;
        
    }
};