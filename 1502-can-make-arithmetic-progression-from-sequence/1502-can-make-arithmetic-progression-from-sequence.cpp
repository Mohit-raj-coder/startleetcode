class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        
        // Step 1: Find the minimum and maximum values
        for (int num : arr) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }
        
        // Edge Case: If max and min are equal, difference is 0 (e.g., {5, 5, 5})
        if (max_val == min_val) return true;
        
        // Step 2: Calculate the absolute common difference
        // We use abs() to guarantee a positive number/magnitude
        int total_span = abs(max_val - min_val);
        
        if (total_span % (n - 1) != 0) return false;
        int diff = total_span / (n - 1);
        
        unordered_set<int> seen;
        
        // Step 3: Validate that every number maps to a valid index gap
        for (int num : arr) {
            // Find absolute distance from the minimum starting point
            int distance = abs(num - min_val);
            
            if (distance % diff != 0) return false;
            
            // Duplicate check to prevent tracking the same step twice
            if (seen.count(num)) return false;
            
            seen.insert(num);
        }
        
        return true;
    }
};
