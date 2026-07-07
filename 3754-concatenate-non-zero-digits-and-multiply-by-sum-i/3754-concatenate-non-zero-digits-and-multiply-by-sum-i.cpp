class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        
        int rev = 0;
        int temp = n;
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        
        while (rev > 0) {
            int dig = rev % 10;
            rev /= 10;

            if (dig != 0) {
                sum += dig;
                x = x * 10 + dig;
            }
        }

        return x * sum;
    }
};