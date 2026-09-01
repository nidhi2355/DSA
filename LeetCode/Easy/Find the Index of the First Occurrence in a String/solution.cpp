class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.size(), m= needle.size();

        if(m> n) return -1;

        for(int i=0; i<n; i++){
            if(haystack[i]==needle[0]){
                bool flag= true;
                for(int j= 0; j< m; j++){
                    if(haystack[i+j]!= needle[j]) {
                        flag= false;
                        break;
                    }
                }

                if(flag) return i;
            }
        }

        return -1;
    }
};