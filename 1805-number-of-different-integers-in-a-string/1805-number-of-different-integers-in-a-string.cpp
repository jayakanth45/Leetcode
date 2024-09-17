class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_map<string,int> um;
 
        string temp="";
        for(int i=0;i<word.size();i++){
            if(!isalpha(word[i])){
                
                temp+=word[i];
                
                
                
            }
            else{
                if(temp!=""){
                    int k=0;
                    while(temp[k]=='0' && k<temp.size()){
                        k++;
                    }
                    if(k==temp.size()){
                        um["0"]++;
                    }
                    else{
                        cout<<temp.substr(k,temp.size())<<" "<<i<<endl;
                        um[temp.substr(k,temp.size())]++;
                    }
                }
                
             
                temp="";
            }
            
            
        }
        if(temp!="")
        {
            int k=0;
                    while(temp[k]=='0' && k<temp.size()){
                        k++;
                    }
                    if(k==temp.size()){
                        um["0"]++;
                    }
                    else{
                        
                        um[temp.substr(k,temp.size())]++;
                    }
        }
      
        return um.size();
        
    }
};