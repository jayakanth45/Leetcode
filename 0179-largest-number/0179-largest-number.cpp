class Solution {
public:

    static bool comparator(string &a, string &b){
        return (a+b) > (b+a);
    }

    string largestNumber(vector<int>& nums) {
        vector<string>v;

        for(auto it : nums){
            v.push_back(to_string(it));
        }

        sort(v.begin(), v.end(), comparator);

        string output="";
        int sum=0;
        for(auto it : v){
            output += it;
          
        }
        if(output[0] == '0')return "0";

        return output;
    }
};