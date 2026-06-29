#include <algorithm>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        
        // FIX 1: Change loop variable 'i' to long long to prevent overflow
        for (long long i = 1; i <= n; i *= 10) {
            
            // FIX 2: Change 'divider' to long long because it multiplies 'i' by 10
            long long divider = i * 10;
            
            // These can remain regular 'int' because they divide 'n'
            int high = n / divider;
            int curr = (n / i) % 10;
            int low = n % i;
            
            // 1. Count '1's contributed by the higher digits cycling
            count += (long long)high * i;
            
            // 2. Count '1's contributed by the current digit itself
            if (curr == 1) {
                count += low + 1;
            } else if (curr > 1) {
                count += i;
            }
        }
        
        return count;
    }
};
