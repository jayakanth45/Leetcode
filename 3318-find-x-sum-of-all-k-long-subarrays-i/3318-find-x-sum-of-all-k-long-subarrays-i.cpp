class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int b) {
        map<int,int> um;
        vector<int> ans;
        int j=0;
        
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            um[nums[i]]++;
            if(i-j+1==k){
                map<int,vector<int>> mp;
                stack<pair<int,vector<int>>> st;
                for(auto x:um){
                    mp[x.second].push_back(x.first);
                }
                int p=um.size();
                if(p<b){
                
                    ans.push_back(sum);
                    
                }
                else{
                    
                    
                    
                    for(auto x:mp){
                        st.push({x.first,x.second});
                    }
                    int count=0,alpha=0;
                    
                    while(!st.empty()){
                        int k=st.top().first;
                        
                        vector<int> temp=st.top().second;
                        for(int i=temp.size()-1;i>=0;i--){
                            if(count==b){
                                break;
                            }
                            int h=k;
                            while(h--){
                                alpha+=temp[i];
                            }
                            
                            
                            count++;
                        }
                        if(count==b){
                            break;
                        }
                        st.pop();
                    }
                    ans.push_back(alpha);
                    
                }
                um[nums[j]]--;
                if(um[nums[j]]==0){
                    um.erase(nums[j]);
                }
                sum-=nums[j];
               j++; 
                
            }
        }
        return ans;
        
    }
};