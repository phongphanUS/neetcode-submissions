#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());

            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        result.reserve(groups.size());

        for (auto& entry : groups) {
            result.push_back(move(entry.second));
        }

        return result;
    }
};