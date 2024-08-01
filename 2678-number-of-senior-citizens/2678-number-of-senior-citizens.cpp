class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
            string str=details[i];
            string s="";
            s+=str[11];
            s+=str[12];
            if(stoi(s)>60){
                count++;
            }
        }
        return count;
    }
};