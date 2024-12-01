class Solution {
public:
    void giveans(vector<string> &ans,int n,string temp,int oc,int cc){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(oc<n){
            
            giveans(ans,n,temp+'(',oc+1,cc);
        }
    
        if(cc<oc)
        giveans(ans,n,temp+')',oc,cc+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        giveans(ans,n,"",0,0);
        return ans;
        
    }
};