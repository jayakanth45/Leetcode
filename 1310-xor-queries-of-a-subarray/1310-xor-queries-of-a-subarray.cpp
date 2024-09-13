class Solution {
public:
     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {   //Initialize result to 0 and size of queries
        vector<int> result(queries.size(),0);

        for(int i=0;i<queries.size();i++)   //first loop for the size of queries
        {
            result[i] = arr[queries[i][0]]; //initialize of first element, so that there is no XOR with 0
            for(int j= queries[i][0]+1; j<= queries[i][1];j++) //second loop from queries[i][0] to queries[i][1]
                result[i] ^= arr[j];    //XOR operations
        }    
        
        return result;
    }
    
};