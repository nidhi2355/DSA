class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string res = "";
        if (solve(0, "", freq, target, false, res)) {
            return res;
        }
        return "";
    }

private:
    bool solve(int idx, string current, vector<int>& freq, const string& target, bool isGreater, string& res) {
        int n = target.size();
        if (idx == n) {
            if (isGreater) {
                res = current;
                return true;
            }
            return false;
        }

        int start = isGreater ? 0 : (target[idx] - 'a');

        for (int c = start; c < 26; ++c) {
            if (freq[c] > 0) {
                freq[c]--;
                bool nextGreater = isGreater || (c > (target[idx] - 'a'));
                
                if (canComplete(freq, n - idx - 1)) {
                    if (solve(idx + 1, current + (char)('a' + c), freq, target, nextGreater, res)) {
                        return true;
                    }
                }
                freq[c]++;
            }
        }
        return false;
    }

    bool canComplete(const vector<int>& freq, int remaining) {
        int total = 0;
        for (int count : freq) total += count;
        return total >= remaining;
    }
};