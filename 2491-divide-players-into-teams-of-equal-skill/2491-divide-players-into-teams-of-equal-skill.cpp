class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        long long sum=accumulate(skill.begin(),skill.end(),0);
        long long each_sum=sum/(n/2);
        long long ans=0;
        unordered_map<long long,long long> um;
        int count=0;
        for(int i=0;i<skill.size();i++){
           long long t= each_sum-skill[i];
            if(um.find(t)!=um.end() && um[t]>0){
                count+=2;
                um[t]--;
                ans+=(skill[i]*t);
                
            }
            else{
                um[skill[i]]++;
            }
        }
        return count==n?ans:-1;
    }
};