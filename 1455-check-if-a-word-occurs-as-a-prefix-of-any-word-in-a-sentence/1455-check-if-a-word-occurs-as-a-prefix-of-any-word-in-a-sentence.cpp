class Solution {
public:
    int isPrefixOfWord(string sentence, string str) {
        int count=1,i=0,j=0;
        string temp="";
        while(i<sentence.size()){
            if(sentence[i]==' '){
              // cout<<temp<<endl;
                if(temp.size()>=str.size()){
                     bool flag=0;
                for(int k=0;k<str.size();k++){
                    if(str[j++]==temp[k]){
                        
                    }
                    else{
                        flag=1;
                    }
                }
                if(!flag){
                    return count;
                }
                else{
                    j=0;
                }
                }
                count++;
                temp="";
            }
            else{
                temp+=sentence[i];
            }
            
            i++;
            
        }
        if(temp!=""){
            cout<<temp;
             if(temp.size()>=str.size()){
                     bool flag=0;
                for(int k=0;k<str.size();k++){
                    cout<<j;
                    if(str[j++]==temp[k]){
                        
                    }
                    else{
                        flag=1;
                    }
                }
                if(!flag){
                    return count;
                }
                else{
                    j=0;
                }
                }
        }
        return -1;
    }
};