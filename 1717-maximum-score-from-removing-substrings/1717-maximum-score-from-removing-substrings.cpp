class Solution {
public:
    int maximumGain(string s, int x, int y) {
       int n = s.size();
        int a_count = 0, b_count = 0;
        int sum = 0;
        if (x < y){
            reverse(s.begin(), s.end());
            swap(x,y);
        }

        for (int i=0; i<n; i++){
            if (s[i] == 'a'){
                a_count++;
            }

            else if (s[i] == 'b'){
                if (a_count > 0){
                    a_count--;
                    sum += x;
                }
                else {
                    b_count++;
                }
            }
            else {
                int time = min(a_count, b_count);
                sum += y*time;
                a_count=0;
                b_count=0;
            }
        }
        sum += y*min(a_count,b_count);
        return sum;
    }
};