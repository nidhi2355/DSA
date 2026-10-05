class Solution {
public:
    string addBinary(string a, string b) {
        int n= a.size(), m= b.size();

        string res= "";

        int carry=0, x= n-1, y= m-1;

        while(x>=0 or y>=0 or carry){
            int na= 0, nb=0;
            if(x>=0){
                na= a[x--]-'0';
            }
            if(y>=0){
                nb= b[y--]-'0';
            }

            int sum= na+ nb+ carry;
            res+= '0'+ (sum%2);
            carry= sum/2;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};