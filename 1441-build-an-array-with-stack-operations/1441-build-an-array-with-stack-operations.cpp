class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> store; // Changed from int to string
        int current_stream_num = 1;
        
        for (int i = 0; i < target.size(); i++) {
            // Push and Pop skipped numbers
            while (current_stream_num < target[i]) {
                store.push_back("Push");
                store.push_back("Pop");
                current_stream_num++;
            }
            // Push the matching number
            store.push_back("Push");
            current_stream_num++;
        }
        
        return store;
    }
};
