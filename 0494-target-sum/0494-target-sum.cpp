class Solution {
public:
   map<pair<int,int>, int> memo;
    int recursive(vector<int>&a, int index, int target){
        if(index==0){
            if(target==0) return 1;
            return 0;
        }
        pair<int,int> p= make_pair(index,target);
        if(memo.count(p)) return memo[p];
        return memo[p]= recursive(a,index-1,target-a[index-1]) + recursive(a,index-1,target+a[index-1]);

    }
    int findTargetSumWays(vector<int>& a, int target) {
        /*
            What are my choices?
            1. Add the element
            2. Subtract the element

            What we want to do?
            Count the number of ways in which we can achieve the target sum.

            What are the base conditions?
            => what are the minimum valid inputs?
            => n could be 0 and target could be 0

            Write a recursive funtion

            func(a[],n,target){
                // Base condition
                if(n==0){
                    if(target==0) return 1;
                    else return 0;
                }
                return func(a[],n-1,target-a[n-1])+ func(a[],n-1,target+a[n-1]);
            }
        */
        return recursive(a ,a.size(),target);
    }
};