class ProductOfNumbers {
private:
    int size=0;
    vector<int>pref;
public:
    ProductOfNumbers() {
        size=0;
        pref={1};
    }
    
    void add(int num) {
        if(num){
            pref.push_back(pref[size]*num);
            size++;
        }
        else{
            pref={1};
            size=0;
        }
    }
    
    int getProduct(int k) {
        if(k>size)return 0;
        return pref[size]/pref[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */