class MovieRentingSystem {
private:
    unordered_map<int, set<pair<int, int>>> available;
    set<vector<int>> rented;
    unordered_map<long long, int> shopMovieToPrice;
    long long hash(int a, int b) {
        return ((long long)a << 14 | b); //14 enough for constraints(10^4)
    }
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry: entries) {
            available[entry[1]].insert({entry[2], entry[0]});
            shopMovieToPrice[hash(entry[0], entry[1])] = entry[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int i = 5;
        for(auto it = available[movie].begin(); it != available[movie].end() && i; it++, i--) {
            auto entry = *it;
            ans.push_back(entry.second);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shopMovieToPrice[hash(shop, movie)];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shopMovieToPrice[hash(shop, movie)];
        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i = 5;
        for(auto it = rented.begin(); it != rented.end() && i; it++, i--) {
            auto entry = *it;
            ans.push_back({entry[1], entry[2]});
        }
        return ans;
    }
};