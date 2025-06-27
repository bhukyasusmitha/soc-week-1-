class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maxnum;

        for (int i = 0; i <= nums.size() - k; i++) {
            int maxval = nums[i];
            for (int j = 1; j < k; j++) {
             maxval = max(maxval, nums[i + j]);
            }
            maxnum.push_back(maxval);
        }

        return maxnum;
    }
};
