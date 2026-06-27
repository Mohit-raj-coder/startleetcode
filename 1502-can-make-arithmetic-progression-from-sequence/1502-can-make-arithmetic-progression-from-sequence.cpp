class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // Step 1: Sort the array to order the elements properly
        sort(arr.begin(), arr.end());
        
        // Step 2: Find the absolute distance between the first two elements
        int diff = abs(arr[1] - arr[0]);
        
        // Step 3: Verify the absolute distance remains constant throughout
        for (int i = 2; i < arr.size(); i++) {
            // Compare the absolute difference of current elements to our target
            if (abs(arr[i] - arr[i-1]) != diff) {
                return false; 
            }
        }
        
        return true;
    }
};
