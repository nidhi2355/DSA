class Solution {
public:
    int calculate(string s) {
        long long result = 0;
        long long current_number = 0;
        int sign = 1; 
        stack<int> st;
        
        for (char c : s) {
            if (isdigit(c)) {
                current_number = current_number * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * current_number;
                current_number = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * current_number;
                current_number = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * current_number;
                current_number = 0;
                
                result *= st.top(); 
                st.pop();
                
                result += st.top(); 
                st.pop();
            }
        }
        
        result += sign * current_number;
        return result;
    }
};