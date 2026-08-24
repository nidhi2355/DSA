class CustomStack {
public:
    vector<int> arr;
    int right, n;

    CustomStack(int maxSize) {
        arr.resize(maxSize);
        n= maxSize;
        right=0;
    }
    
    void push(int x) {
        if(right<n) arr[right++]= x;
    }
    
    int pop() {
        if(right==0) return -1;
        int ele= arr[right-1];
        right--;
        return ele;
    }
    
    void increment(int k, int val) {
        int s= min(right, k);
        for(int i=0; i<s; i++) arr[i]+= val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */