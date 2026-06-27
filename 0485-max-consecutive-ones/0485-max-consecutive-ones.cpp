#include <vector>
#include <algorithm> // For std::max

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int max_count = 0;
        int count = 0;
        int n = nums.size(); // Declare n so the loop knows when to stop

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count += 1;
                if (count > max_count) {
                    max_count = count;
                }
            } else {
                // ONLY reset the streak when we encounter a 0
                count = 0; 
            }
        }
        
        return max_count; // Return the historical maximum record
    }
};
