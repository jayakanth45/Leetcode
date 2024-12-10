class Solution {
public:
    int n;
    string s;
    int alphabet[26][3];
    inline void push(int x, int lens[3]){
        if (x>=lens[0]){
            lens[2]=exchange(lens[1], lens[0]);
            lens[0]=x;
        }
        else if (x>=lens[1]) lens[2]=exchange(lens[1], x);
        else if (x>=lens[2]) lens[2]=x;
    }
    inline void table(){
        char prev=s[0]; 
        int f=1;
        for(int i=1; i<n; i++){
            if (s[i]==prev)
                f++;
            else{
                push(f, alphabet[prev-'a']);
                f=1;
                prev=s[i];  
            }   
        }
        push(f, alphabet[s.back()-'a']);
    }
    inline int maxLen3x(int* v){
        return max({v[2], min(v[0]-1, v[1]), v[0]-2});
    }

    int maximumLength(string& s) {
        this->s=s;
        n=s.size();
        memset(alphabet, -1, sizeof(alphabet));
        table();
        int ans=-1;
        for (int* lens: alphabet){
            if (lens[0]==-1) continue;
            ans=max(ans,  maxLen3x(lens));
        }
        return ans<=0?-1:ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();