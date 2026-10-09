class Solution {
    const string PUSH = "Push", POP = "Pop";
public:
    vector<string> buildArray(vector<int>& target, int n,vector<string> out = {}) {
        int i = 0, size = target.size();
        int curr = 1;
        while(i < size ){
            if(target[i] == curr){
                out.push_back(PUSH);
                i++;
            }else{
                out.push_back(PUSH);
                out.push_back(POP);
            }
            curr++;
        }
        return out;
    }
};