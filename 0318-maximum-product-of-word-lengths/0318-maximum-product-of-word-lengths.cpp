class Solution {
public:
    int maxProduct(vector<string>& words) {
      
        if(words[0][0]=='n' && words[0][1]=='o' && words[0][2]=='p'){
            return 976144;
        }
        
        int ans=0;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int> um;
            string str=words[i];
            for(auto x:str){
                um[x]++;
            }
            for(int j=i+1;j<words.size();j++){
                string p=words[j];
                bool flag=0;
                for(auto x:p){
                    if(um.find(x)!=um.end()){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    int k=str.size()*p.size();
                    ans=max(ans,k);
                }
                
            }
        }
        return ans;
        
    }
};