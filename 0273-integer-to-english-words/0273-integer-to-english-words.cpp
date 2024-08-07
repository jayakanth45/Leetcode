class Solution {
    unordered_map<int, pair<string, string>> positions = {
        {1, {"One", ""}},
        {2, {"Two", "Twenty"}},
        {3, {"Three", "Thirty"}},
        {4, {"Four", "Forty"}},
        {5, {"Five", "Fifty"}},
        {6, {"Six", "Sixty"}},
        {7, {"Seven", "Seventy"}},
        {8, {"Eight", "Eighty"}},
        {9, {"Nine", "Ninety"}}
    };

    unordered_map<int, string> number = {
        {10, "Ten"},   
        {11, "Eleven"},  
        {12, "Twelve"},  
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"}
    };

    unordered_map<int, string> suffix = {
        {4, "Thousand"},
        {7, "Million"},
        {10, "Billion"}
    };

    int getNumber(int dt1, int dt2) {
        return dt1 * 10 + dt2;
    }

    string getThreeNumString(int dt1, int dt2, int dt3) {
        string ans = "";

        if (dt1 != 0) {
            ans = positions[dt1].first + " Hundred"; 
        }
    
        string twoNumString = getTwoNumString(dt2, dt3);

        if (twoNumString != "") {
            if (ans == "")
                ans = twoNumString;
            else
                ans = ans + " " + twoNumString;
        }

        return ans;
    }

    string getTwoNumString(int dt2, int dt3) {
        string ans = "";

        if (dt2 != 0) {
            int num = getNumber(dt2, dt3);

            if (num < 20) {   
                if (ans == "")
                    ans = number[num];
                else           
                    ans = ans + " " + number[num];
            }
            else {
                if (ans == "")
                    ans = positions[dt2].second;
                else
                    ans = ans + " " + positions[dt2].second;

                if (dt3 != 0) {
                    if (ans == "")
                        ans = positions[dt3].first;
                    else
                        ans = ans + " " + positions[dt3].first;
                }
            }
        }
        else if (dt3 != 0) {
            if (ans == "")
                ans = positions[dt3].first;
            else
                ans = ans + " " + positions[dt3].first;
        }

        return ans;
    }

    string getOneNumString(int dt) {
        return positions[dt].first;
    }

public:
    string numberToWords(int num) {
        string ans = "";

        if (num == 0)
            return "Zero";

        int dt1 = -1, dt2 = -1, dt3 = -1, place = 0;

        while (true) {
            int cnt = 3;

            while (num && cnt > 0) {
                int ld = num % 10;

                if (cnt == 3) {
                    dt3 = ld;
                }
                else if (cnt == 2) {
                    dt2 = ld;
                }
                else {
                    dt1 = ld;
                }

                num /= 10;
                place++;
                cnt -= 1;
            }

            string curString = "";

            if (cnt == 0 && !(dt1 == 0 && dt2 == 0 && dt3 == 0)) {
                curString = getThreeNumString(dt1, dt2, dt3);
            }
            else if (cnt == 1 && !(dt2 == 0 && dt3 == 0)) {
                curString = getTwoNumString(dt2, dt3);
            }
            else if (cnt == 2 && dt3 != 0) {
                curString = getOneNumString(dt3);
            }

            if (curString != "") {
                if (place >= 4 && place <= 6)
                    curString = curString + " " + suffix[4];
                else if (place >= 7 && place <= 9)
                    curString = curString + " " + suffix[7];
                else if (place == 10)
                    curString = curString + " " + suffix[10];
                
                if (ans != "") 
                    ans = curString + " " + ans;
                else
                    ans = curString;
            }

            if (num == 0)
                break;
        }

        return ans;
    }
};