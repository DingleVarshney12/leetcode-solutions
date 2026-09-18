class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumOfS=0;
        int sumOfT=0;
        for(int i=0;i<s.length();i++){
            sumOfS += s[i] - 'a';
        }
        for(int i=0;i<t.length();i++){
            sumOfT += t[i] - 'a';
        }
        int diff = sumOfT - sumOfS;
        return (char)(diff + 'a');
    }
};