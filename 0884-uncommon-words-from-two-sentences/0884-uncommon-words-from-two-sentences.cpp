class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> um;
        string part="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=' '){
                part+=s1[i];
            }
            else if(s1[i]==' ' && part!=""){
                um[part]++;
                part="";
            }
        }
        if(part!=""){
            um[part]++;
        }
        unordered_map<string,int> u;
        part="";
         for(int i=0;i<s2.size();i++){
            if(s2[i]!=' '){
                part+=s2[i];
            }
            else if(s2[i]==' ' && part!=""){
                u[part]++;
                part="";
            }
        }
        if(part!=""){
            u[part]++;
        }
        part="";
        vector<string> ans;
        for(int i=0;i<s1.size();i++){
             if(s1[i]!=' '){
                part+=s1[i];
            }
            else if(s1[i]==' ' && part!=""){
                if(u.find(part)==u.end() && um[part]==1){
                    ans.push_back(part);
                }
                part="";
            }
           
        }
        cout<<um[part];
        if(part!=""){
             if(u.find(part)==u.end() && um[part]==1){
                    ans.push_back(part);
                }
        }
        
        part="";
         for(int i=0;i<s2.size();i++){
             if(s2[i]!=' '){
                part+=s2[i];
            }
            else if(s2[i]==' ' && part!=""){
                if(um.find(part)==um.end() && u[part]==1){
                    ans.push_back(part);
                }
                part="";
            }
           
        }
        
         if(part!=""){
             if(um.find(part)==um.end() && u[part]==1){
                    ans.push_back(part);
                }
        }
        return ans;
    }
};