class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v(profit.size());
        for(int i=0;i<profit.size();i++){
            v.push_back({difficulty[i],profit[i]});
            }
        sort(v.begin(),v.end());
        priority_queue<int> p;
        int count=0;
        int j=0;
        sort(worker.begin(),worker.end());
        for(int i=0;i<worker.size();i++){    
            while(j<v.size() && v[j].first<=worker[i] ){
            p.push(v[j].second);
            j++;
            }
            if(!p.empty())
                     count+=p.top();                     
            
            }
        return count;
        
        
    }
};