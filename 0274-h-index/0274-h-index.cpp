class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sum=citations.size();
        map<int,int> um;
        for(auto x:citations){
            um[x]++;
        }
        int max1=0;
        for(int i=0;i<=citations.size();i++){
            if(i<=sum){
                max1=i;
            }
            if(um.find(i)!=um.end()){
                sum-=um[i];
            }
        }
        return max1;
        
    }
};