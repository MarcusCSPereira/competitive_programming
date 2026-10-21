#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        vector<vector<int>> bucket(n + 1);

        for (const auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        vector<int> result;

        for (int i = n; i > 0; i--) {
            for (int x : bucket[i]) {
                result.push_back(x);

                if (result.size() == k)
                    return result;
            }
        }

        return result;
    }
};
