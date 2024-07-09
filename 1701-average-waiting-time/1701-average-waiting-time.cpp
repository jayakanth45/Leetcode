class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double arr_time=double(customers[0][0]);
        double com_time=double(customers[0][1]+customers[0][0]);
        double count=com_time-arr_time;
        
        for(int i=1;i<customers.size();i++){
            
            arr_time=double(customers[i][0]);
            if(arr_time>=com_time){
                count+=customers[i][1];
                com_time=customers[i][0]+customers[i][1];
                continue;
            }
            com_time=double(com_time+customers[i][1]);
            count+=(com_time-arr_time);
            
            
        }
        return count/double(customers.size());
        
    }
};