#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        int n = nums.size();
        // Allocate a vector of double the size
        std::vector<int> ans(2 * n); 
        
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];       // Fill first half
            ans[i + n] = nums[i];   // Fill second half
            
            // Alternative shortcut: ans.push_back() inside a duplicated loop, 
            // but pre-allocating size and indexing is much faster.
        }
        
        return ans;
    }
};
