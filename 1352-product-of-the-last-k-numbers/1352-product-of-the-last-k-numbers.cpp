class ProductOfNumbers {
    vector<int> prefixProd; 
public:
    ProductOfNumbers() {
        prefixProd.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            prefixProd.clear();
            prefixProd.push_back(1);
        }else{
            prefixProd.push_back(prefixProd.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProd.size();
        if(k >= n) return 0;
        return prefixProd[n - 1] / prefixProd[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */