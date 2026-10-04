class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int first = 0;
        int second = 1;
        int third = 1;
        for (int i = 3; i < n; i++) {
            int temp = third;
            int temp2 = second;
            third += first + second;
            second = temp;
            first = temp2;
        }
        return first + second + third;
    }
};