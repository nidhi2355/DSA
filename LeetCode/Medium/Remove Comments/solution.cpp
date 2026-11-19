class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string currentLine = "";
        bool inBlock = false;
        
        for (const string& line : source) {
            int n = line.size();
            for (int i = 0; i < n; i++) {
                if (inBlock) {
                    if (line[i] == '*' && i + 1 < n && line[i + 1] == '/') {
                        inBlock = false;
                        i++;
                    }
                } else {
                    if (line[i] == '/' && i + 1 < n && line[i + 1] == '/') {
                        break;
                    }
                    else if (line[i] == '/' && i + 1 < n && line[i + 1] == '*') {
                        inBlock = true;
                        i++;
                    }
                    else {
                        currentLine += line[i];
                    }
                }
            }
            
            if (!inBlock && !currentLine.empty()) {
                res.push_back(currentLine);
                currentLine = "";
            }
        }
        
        return res;
    }
};