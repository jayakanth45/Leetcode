class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         map<char,int>m1,m2;
        for(char c : s1)
            m1[c]++;
        int n1 = s1.size() , n2 = s2.size();
        int i=0,j=0;
        while(j<n2)
        {
                m2[s2[j]]++;
                 
                    if(j-i+1 == n1)
                    {
                         if(m1==m2)
                            return true;
                         m2[s2[i]]--;
                         if(m2[s2[i]]==0)
                            m2.erase(s2[i]);
                        i++; 
                       
                    }
                    j++;
        }
    return false;
    }
};