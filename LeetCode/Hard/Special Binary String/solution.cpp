class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt=0;
        vector<string> components;

        int i=0;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='1') cnt++;
            else cnt--;

            if(cnt==0){
                components.push_back('1'+ makeLargestSpecial(s.substr(i+1, j-i-1))+ '0');
                i= j+1;
            }
        }

        sort(components.begin(), components.end(), greater<string>());

        string res= "";
        for(auto &it: components){
            res+= it;
        }

        return res;
    }
};