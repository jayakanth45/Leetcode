class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        deque<int> dq;
        int n = positions.size();
        map<int, int> pos;
        for(int i=0;i<n; i++){
            pos[positions[i]] = i;
        }
        sort(positions.begin(), positions.end());

        vector<int> ans;
        for(int i=0;i<n;i++){
            int actualIndex = pos[positions[i]]; 
            if(directions[actualIndex] == 'R')
                dq.push_back(actualIndex);
            else{
                while(!dq.empty() && healths[dq.back()] < healths[actualIndex]){
                    dq.pop_back();
                    healths[actualIndex]--;
                }
                if(dq.empty())
                    ans.push_back(actualIndex);
                else if(healths[dq.back()] != healths[actualIndex]){
                    healths[dq.back()]--;
                }
                else
                    dq.pop_back();
            }
 
        }
   
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        n = ans.size();
        sort(ans.begin(), ans.end());
        for(int i=0;i < n; i++){
            ans[i] = healths[ans[i]];
        }
        return ans;
        
    }
};