class Solution {
public:
    int compress(vector<char> &chars)
{
    int firstCharIdx = 0;
    int n = chars.size();
    for (int i = 0; i < n;)
    {   
        char ch = chars[i];
        int count = 0;
        while(i < n && chars[i] == ch){
            count++;
            i++;
        }
        chars[firstCharIdx++] = ch;
        if(count > 1){
            string str = to_string(count);
            for(char digit:str){
                chars[firstCharIdx++] = digit;
            }
        }
    }
    return firstCharIdx;
}
};