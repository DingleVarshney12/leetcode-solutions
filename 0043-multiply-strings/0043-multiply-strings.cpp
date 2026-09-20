class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> output(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int dig1 = num1[i] - '0';
                int dig2 = num2[j] - '0';

                int pos1 = i + j;
                int pos2 = pos1 + 1;

                int sum = dig1 * dig2 + output[pos2];
                output[pos2] = sum % 10;
                output[pos1] += sum / 10;
            }
        }

        string s;
        for (int digit : output) {
            if (!s.empty() || digit != 0)
                s += char('0' + digit);
        }

        return s.empty() ? "0" : s;
    }
};
