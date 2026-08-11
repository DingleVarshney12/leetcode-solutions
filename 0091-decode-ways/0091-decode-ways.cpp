class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.length();
        int prev2= 1;
        int prev1 = 1;
        for(int i = 2; i <= n;i++){
            int curr = 0;
            if(s[i-1] >= '1' && s[i-1]<='9'){
                curr += prev1;
            }
            int num = (s[i-2]-'0') * 10 + (s[i-1]-'0');
            if(10 <= num && num <=26){
                curr+= prev2;
            }
            prev2 = prev1;
            prev1 =  curr;
        }
        return prev1;

    }
};