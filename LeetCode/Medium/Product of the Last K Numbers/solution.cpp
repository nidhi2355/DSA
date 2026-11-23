class ProductOfNumbers {
public:
vector<int> res;
int n;
    ProductOfNumbers() {
       n=0; 
    }
    
    void add(int num) {
        res.push_back(num);
        n++;
    }
    
    int getProduct(int k) {
        int temp=1;
        for(int i= n-1; i>=n-k; i--){
            temp*= res[i]; 
        }

        return temp;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */