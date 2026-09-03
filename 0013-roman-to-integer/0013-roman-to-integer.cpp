class Solution {
public:
    int romanToInt(string s){
        int n=  s.length();
        unordered_map<char,int> symbols = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = symbols[s[i]];
            int next = (i + 1 < n) ? symbols[s[i+1]] : 0;
            if(curr < next){
                ans -= curr;
            }else{
                ans += curr;
            }
        }
        return  ans;


    }
};