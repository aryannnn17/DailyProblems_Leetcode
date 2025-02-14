class ProductOfNumbers {
public:
    vector<int> n;
    ProductOfNumbers() {}

    void add(int num) { n.push_back(num); }

    int getProduct(int k) {
        int p = 1;
        for (int i = n.size() - k; i < n.size(); ++i)
            p *= n[i];
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
