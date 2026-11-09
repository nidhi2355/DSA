class NestedIterator {
private:
    stack<NestedInteger> st;

    void prepare() {
        while (!st.empty() && !st.top().isInteger()) {
            auto list = st.top().getList();
            st.pop();
            for (auto it = list.rbegin(); it != list.rend(); ++it) {
                st.push(*it);
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            st.push(*it);
        }
    }
    
    int next() {
        prepare();
        int res = st.top().getInteger();
        st.pop();
        return res;
    }
    
    bool hasNext() {
        prepare();
        return !st.empty();
    }
};