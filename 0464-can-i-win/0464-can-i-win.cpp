class Solution {
public:
   
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int total = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (total < desiredTotal) return false;
        if (desiredTotal <= 0) return true;

        unordered_map<int, bool> memo;


        function<bool(int, int)> canWin = [&](int usedNumbers, int currentTotal) {
            if (memo.count(usedNumbers)) return memo[usedNumbers];

            for (int i = 1; i <= maxChoosableInteger; i++) {
                int bit = 1 << (i - 1);
                if ((usedNumbers & bit) == 0) { 
                    if (currentTotal + i >= desiredTotal || 
                        !canWin(usedNumbers | bit, currentTotal + i)) {
                        return memo[usedNumbers] = true;
                    }
                }
            }

            return memo[usedNumbers] = false;
        };

    
        return canWin(0, 0);
    }
};