class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> output(m,string(n,'#'));
        for(int i = 0;i < m;i++) output[i][0] = '.';
        for(int j = 0; j< n;j++) output[m-1][j] = '.';
        return output;

    }
};