class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,vector<int>> um;
        for(int i=0;i<obstacles.size();i++){
            um[obstacles[i][0]].push_back(obstacles[i][1]);
        }
        int x=0;
        int y=0;
        bool flag1=0;
        int ans=0;
        string str="north";
        int flag2=0;
        for(int i=0;i<commands.size();i++){
            
            if(commands[i]!=-1 && commands[i]!=-2){
               
                
            
                int k;
                if(str=="north"){
                flag1=0;
                    k=1;
                while(k<=commands[i]){
                    if(um.find(x)!=um.end()){
                        int cnt = count(um[x].begin(), um[x].end(), y+k); 
                        if(cnt>0){
                      
                        y=y+k-1;
                        flag1=1;
                        break;
                        }
                    }
                    
                    
                    k++;
                }
                if(!flag1){
                 
                    y=y+commands[i];
                    
                }
                    
              
                }
                 if(str=="south"){
                flag1=0;
                     k=1;
                while(k<=commands[i]){
                    if(um.find(x)!=um.end()){
                        int cnt = count(um[x].begin(), um[x].end(), y-k); 
                        if(cnt>0){
                        y=y-k+1;
                        flag1=1;
                        break;
                        }
                    }
                    
                    
                    k++;
                }
                if(!flag1){
                    y=y-commands[i];
                }
                }
                 if(str=="east"){
                flag1=0;
                     k=1;
                while(k<=commands[i]){
                    if(um.find(x+k)!=um.end()){
                        int cnt = count(um[x+k].begin(), um[x+k].end(), y); 
                        if(cnt>0){
                        x=x+k-1;
                        flag1=1;
                        break;
                        }
                    }
                    
                    
                    k++;
                }
                if(!flag1){
                    x=x+commands[i];
                }
                }
                 if(str=="west"){
                flag1=0;
                     k=1;
                while(k<=commands[i]){
                    if(um.find(x-k)!=um.end()){
                        int cnt = count(um[x-k].begin(), um[x-k].end(), y); 
                        if(cnt>0){
                    
                        x=x-k+1;
                        flag1=1;
                        break;
                        }
                    }
                    
                    
                    k++;
                }
                if(!flag1){
                    x=x-commands[i];
                }
                }
                ans=max(ans,x*x+y*y);
                
                flag2=1;
                
            }
            if(commands[i]==-1){
                if(str=="north")
                    str="east";
                else if(str=="east")
                    str="south";
                else if(str=="south")
                    str="west";
                else
                    str="north";
                
            }
            if(commands[i]==-2){
                if(str=="north")
                    str="west";
                else if(str=="east")
                    str="north";
                else if(str=="south")
                    str="east";
                else
                    str="south";
                
            }
            
            
            
        }
        return ans;
        
        
    }
};