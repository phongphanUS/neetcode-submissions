#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        // Đếm tần suất của mỗi số
        for (int x : nums) {
            count[x]++;
        }

        // Một số có thể xuất hiện tối đa nums.size() lần
        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& entry : count) {
            int value = entry.first;
            int frequency = entry.second;

            buckets[frequency].push_back(value);
        }

        vector<int> result;
        result.reserve(k);

        // Lấy từ nhóm có tần suất cao nhất xuống
        for (int frequency = static_cast<int>(nums.size());
             frequency >= 1;
             frequency--) {

            for (int value : buckets[frequency]) {
                result.push_back(value);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};