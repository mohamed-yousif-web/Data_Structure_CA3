#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // Stores indices, maintaining decreasing values at those indices

        // Traverse twice (2 * n) using modulo to simulate a circular array
        for (int i = 0; i < 2 * n; ++i) {
            int idx = i % n;

            while (!st.empty() && nums[st.top()] < nums[idx]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            // Only push indices from the first pass to avoid duplicate work
            if (i < n) {
                st.push(idx);
            }
        }

        return ans;
    }
};