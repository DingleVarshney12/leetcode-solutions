class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0 , right = letters.size()-1;
        if(letters[right]<=target) return letters[0];
        while(left<=right){
            int mid = left + (right -left) /2;
            if(target < letters[mid]){
                right = mid - 1;
            }else{
                left= mid +1;
            }
        }
        return letters[left];
    }
};