class Solution {
    int countSetBit(string s){
        int count = 0;
        for(int i = 0; i < 17; i++){
            if(s[i] == '1') count++;
        }
        return count;
    }
public:
    int calculateScore(int a, int b) {
        string bits_a = bitset<16>(a).to_string();
        string bits_b = bitset<16>(b).to_string();
        int s1 = countSetBit(bits_a);
        int s2 =  countSetBit(bits_b);
        return s1 >= s2 ? s1 * s2 : s2 / s1;
    }
};