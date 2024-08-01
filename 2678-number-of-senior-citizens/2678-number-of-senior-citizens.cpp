class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
            string str=details[i];
           if(int(str[11])-48>6)
               count++;
            else if(int(str[11])-48==6){
                if(str[12]!='0'){
                    count++;
                }
            }
        }
        return count;
    }
};