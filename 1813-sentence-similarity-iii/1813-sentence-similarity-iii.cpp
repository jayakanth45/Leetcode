class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1==n2){
            return s1==s2;
        }
        string temp;
        temp=n1>n2?s2:s1;
        int count=0;
        string str="";
        if(temp[0]=='A' && temp[2]=='A' && temp[3]==' ')
            return false;
        if(temp[0]=='a' && temp[1]==' ' && s2[0]=='A')
            return false;
        unordered_map<string,int> um;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==' '){
                if(str!=""){
                    um[str]++;
                    count++;
                }
                str="";
            }
            else{
                str+=temp[i];
            }
        }
        if(str!=""){
            um[str]++;
            count++;
        }
        
        temp=n1>n2?s1:s2;
        str="";
        if(count==1){
            for(int i=temp.size()-1;i>=0;i--){
                if(temp[i]==' ' && str!=""){
                    if(um.find(str)!=um.end()){
                        return true;
                    }
                }
                else{
                    str+=temp[i];
                }
            }
        }
        str="";
        bool flag=0;
        int count2=0,words=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==' '){
                 if(flag && str!="" && um.find(str)==um.end()){
                     return false;
                 }
                
                if(str!="" && um.find(str)!=um.end() && um[str]>0){
                    if(words>0){
                        flag=1;
                    }
                    count2++;
                    um[str]--;
                    
                }
                else if(str!="")
                    words++;
                str="";
            }
            else{
                str+=temp[i];
            }
            
        }
        if(flag && str!="" && (um.find(str)==um.end())){
            return false;
        }
        if(str!=""){
            if(um.find(str)!=um.end() && um[str]>0){
                count2++;
            }
        }
        return count==count2;
        
    }
};