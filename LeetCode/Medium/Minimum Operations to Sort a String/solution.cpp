class Solution {
public:
    int minOperations(string s) {
        int n= s.size();

        if(n==1) return 0;
        if(n==2){
            if(s[0]<= s[1]) return 0;
            return -1;
        }

        char mine= 'z', maxe= 'a';
        bool sorted= true;

        for(int i=0; i<n; i++){
            mine= min(mine, s[i]);
            maxe= max(maxe, s[i]);

            if(i<n-1 and s[i]>s[i+1]) sorted= false;
        }

        if(sorted) return 0;

        if(s[0]==mine or s[n-1]==maxe) return 1;
        
        for(int i=1; i<n-1; i++){
            if(s[i]==mine or s[i]==maxe) return 2;
        }

        return 3;
    }
};