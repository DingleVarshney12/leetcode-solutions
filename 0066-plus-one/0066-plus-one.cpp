class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // hum traversal right se start karenge kyuki addition last digit pe hoga
        for(int i = n - 1; i >= 0; i--) {

            // agr current digit 9 nahi hai toh increment kardo 
            // aagr carry nhi aayi toh return kardo array
            if(digits[i] != 9){
                digits[i] += 1;
                return digits;
            }

            // aagr digit 9 aayi toh digit ko 0 karke carry ko left mein move kardo 
            digits[i] = 0;

            // aagr hum first digit pe aa gye toh mtlb sari digits 9 thi isliye hum aage 1 insert kar denge
            if(i == 0){
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }

        return digits;
    }
};
