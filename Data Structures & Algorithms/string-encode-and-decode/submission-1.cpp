#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;

        for (const string& word : strs) {
            encoded += to_string(word.size());
            encoded += '#';
            encoded += word;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        size_t i = 0;

        while (i < s.size()) {
            size_t length = 0;

            // Đọc số đứng trước dấu '#'
            while (s[i] != '#') {
                length = length * 10 + (s[i] - '0');
                i++;
            }

            i++; // Bỏ qua dấu '#', tới đầu nội dung

            // Lấy đúng length ký tự
            result.push_back(s.substr(i, length));

            i += length; // Di chuyển tới phần độ dài tiếp theo
        }

        return result;
    }
};