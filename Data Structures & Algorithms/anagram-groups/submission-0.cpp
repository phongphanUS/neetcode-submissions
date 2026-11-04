#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            int count[26] = {};

            // Đếm số lần xuất hiện của từng chữ cái
            for (char c : word) {
                count[c - 'a']++;
            }

            // Chuyển mảng số đếm thành key
            string key;
            for (int frequency : count) {
                key += "#" + to_string(frequency);
            }

            // Các từ cùng key được thêm vào cùng nhóm
            groups[key].push_back(word);
        }

        vector<vector<string>> result;

        for (const auto& entry : groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};