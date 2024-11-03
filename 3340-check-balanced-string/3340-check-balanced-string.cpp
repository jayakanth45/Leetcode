class Solution {
public:
    bool isBalanced(string num) {
        int ev_count=0,odd_count=0;
        for(int i=0;i<num.size();i++){
            if(i%2==0){
                ev_count+=int(num[i])-48;
            }
            else
                odd_count+=int(num[i])-48;
        }
        return ev_count==odd_count;
    }
};