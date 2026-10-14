class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";

        int nines = sum / 9;
        int reminder = sum % 9;
        string ans(nines,'9');
        if(reminder > 0) ans += char('0' + reminder);
        
        ans += string(num - ans.size(), '0');
        return ans;
    }
};