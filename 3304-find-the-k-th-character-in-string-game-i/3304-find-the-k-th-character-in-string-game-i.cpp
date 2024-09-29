class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            string temp=word;
            string temp1="";
            for(int i=0;i<temp.size();i++){
                char c=int(temp[i])+1;
                temp1+=c;
                
                
            }
    
            word+=temp1;
            cout<<word<<endl;
        }
       
        return word[k-1];
        
    }
};