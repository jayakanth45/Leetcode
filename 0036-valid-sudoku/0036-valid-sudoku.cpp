class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> um;
        int m=9;
        for(int i=0;i<9;i++){
            um.clear();
            for(int j=0;j<9;j++){
                if(um.find(board[i][j])!=um.end()){
                 
                    return false;
                }
                if(board[i][j]!='.')
                um[board[i][j]]=1;
                
            }
        }
        for(int i=0;i<9;i++){
            um.clear();
            for(int j=0;j<9;j++){
                if(um.find(board[j][i])!=um.end()){
                    
                    return false;
                }
                if(board[j][i]!='.')
                um[board[j][i]]=1;
                
            }
        }
        int cnt=0;
        int k=0,start1=0,start=0,p=0;
        um.clear();
        while(cnt<9){
            start=k;
            start1=p;
            for(int i=start;i<start+3;i++){
                for(int j=start1;j<start1+3;j++){
                    if(um.find(board[i][j])!=um.end()){
                    return false;
                }
                if(board[i][j]!='.')
                um[board[i][j]]=1;
                    if(i==start+2 && j==start1+2){
                        cnt++;
                        um.clear();
                       
                       p+=3;
                        
                        
                        
                    }
                    
                }
            }
            if(cnt%3==0){
               
                k+=3;
                            
                p=0;
            }
            
        }
        
        return true;
        
    }
};