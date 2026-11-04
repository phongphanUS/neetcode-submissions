#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string encode(const vector<string>& strs) {
        size_t total = 0;

        // Tính chính xác dung lượng cần dùng
        for (const string& word : strs) {
            size_t length = word.size();

            total += length + 1; // Nội dung + dấu '#'

            do {
                total++;        // Một chữ số của độ dài
                length /= 10;
            } while (length > 0);
        }

        string encoded;
        encoded.reserve(total);

        for (const string& word : strs) {
            encoded += to_string(word.size());
            encoded += '#';
            encoded += word;
        }

        return encoded;
    }

    vector<string> decode(const string& s) {
        vector<string> result;
        size_t i = 0;

        while (i < s.size()) {
            size_t length = 0;

            while (s[i] != '#') {
                length = length * 10 + (s[i] - '0');
                i++;
            }

            i++; // Bỏ qua '#'

            // Tạo chuỗi trực tiếp trong vector
            result.emplace_back(s, i, length);
            i += length;
        }

        return result;
    }
};