class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastSeen(32, -1);  
        vector<int> result(n, 1);

        for (int i = n - 1; i >= 0; --i) {
            
            for (int bit = 0; bit < 32; ++bit) {
                if (nums[i] & (1 << bit)) {
                    lastSeen[bit] = i;
                }
            }

            int farthest = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (lastSeen[bit] != -1) {
                    farthest = max(farthest, lastSeen[bit]);
                }
            }

            result[i] = farthest - i + 1;
        }

        return result;
    }
};
