class MedianFinder {
public:
    priority_queue<int> leftheap;
    priority_queue<int, vector<int>, greater<int>> rightheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!leftheap.empty() and num> leftheap.top()){
            rightheap.push(num);
        }
        else{
            leftheap.push(num);
        }

        if(rightheap.size()> leftheap.size()){
            leftheap.push(rightheap.top());
            rightheap.pop();
        }

        if(leftheap.size()- rightheap.size() > 1){
            rightheap.push(leftheap.top());
            leftheap.pop();
        }
    }
    
    double findMedian() {
        if(leftheap.size()==rightheap.size()){
            return ((double)(leftheap.top()+ rightheap.top()))/2.0;
        }

        return (double) leftheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */