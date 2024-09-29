class Solution {
public:
    int countOfSubstrings(string word, int k) {
         int count = 0;
        unordered_set<char> set;
        for (int j = 0; j < word.size(); j++) {
            set.clear();
            int remainingK = 0;
            for (int i = j; i < word.size(); i++) {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                    set.insert(word[i]);
                } else {
                    remainingK++;
                }
                if (set.size() == 5 && remainingK ==k) {
                    count++;
                }
            }
        }
        return count;
    }
};