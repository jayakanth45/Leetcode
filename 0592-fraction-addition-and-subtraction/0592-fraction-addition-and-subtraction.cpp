class Solution {
public:
    string fractionAddition(string expression) {
        int i=0;
        int n=expression.size();
        int num=0;
        int den=1;
        while(i<n){
            int currnum=0;
            int currden=0;
            bool sign=(expression[i]=='-');
            if(expression[i]=='+' or expression[i]=='-'){
            i++;
        }
        while(i<n and isdigit(expression[i]))
        {
            int value=expression[i]-'0';
            currnum=currnum*10+value;
            i++;
        }
        i++;
        if(sign== true) currnum=currnum*-1; 
        while(i<n and isdigit(expression[i])){
            int value=expression[i]-'0';
            currden=currden*10+value;
            i++;
        }
        num=num*currden+den*currnum;
        den=den*currden;
        }
        int GCD= abs(__gcd(num,den));
        num /= GCD;
        den /= GCD;

        return to_string(num) + "/" + to_string(den);
    }
};