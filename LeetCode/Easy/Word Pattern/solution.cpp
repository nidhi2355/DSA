class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        vector<string> words;
        string temp;
        stringstream ss(s);
        while (ss >> temp) words.push_back(temp);
        if (words.size() != pattern.size()) return false;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            if (charToWord.count(c) && charToWord[c] != w) return false;
            if (wordToChar.count(w) && wordToChar[w] != c) return false;
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        return true;
    }
};