class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();
        int maxArea=0;
        vector<int> hist(m,0);
        for(auto &it: matrix){
            for(int i=0;i<m;i++){
                if(it[i]=='0') hist[i]=0;
                else hist[i]++;
            }
            maxArea= max(maxArea, calcArea(hist));
        }
        return maxArea;
    }

private:
    int calcArea(vector<int> &heights){
        int maxArea=0;
        heights.push_back(0);
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() and heights[i]<heights[st.top()]){
                int h= heights[st.top()];
                st.pop();
                int w= st.empty()?i:i-st.top()-1;
                int e= min(h,w);
                maxArea= max(maxArea, e*e);
            }
            st.push(i);
        }
        return maxArea;
    }
};