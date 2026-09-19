class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right= 0,underScore =0;
        for(int i = 0;i < moves.length();i++){
            if(moves[i] == 'L') left++;
            else if(moves[i] == 'R') right++;
            else underScore++;
        }
        return abs(right - left) + underScore;
    }
};