class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long arr_time=(customers[0][0]);
        long long com_time=(customers[0][1]+customers[0][0]);
        long long count=com_time-arr_time;
        
        for(int i=1;i<customers.size();i++){
            
            arr_time=(customers[i][0]);
            if(arr_time>=com_time){
                count+=customers[i][1];
                com_time=customers[i][0]+customers[i][1];
                continue;
            }
            com_time=(com_time+customers[i][1]);
            count+=(com_time-arr_time);
            
            
        }
        return double(count)/double(customers.size());
        
    }
};