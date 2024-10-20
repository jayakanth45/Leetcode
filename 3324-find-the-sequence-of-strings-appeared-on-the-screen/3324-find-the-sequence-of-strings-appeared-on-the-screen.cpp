class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string str="",p="";
        for(auto x:target){
            char temp='W';
            int k=97;
            while(temp!=x){
                temp=k++;
                string s="";
                s+=temp;
                p=str+temp;
                ans.push_back(p);
                }
            str+=x;
            
            
        }
        return ans;
        
        
        
    }
};