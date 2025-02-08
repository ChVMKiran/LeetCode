class NumberContainers {
private:
    unordered_map<int,set<int>>ump;
    unordered_map<int,int>ind;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ind.find(index)!=ind.end()){
            ump[ind[index]].erase(index);
            if(ump[ind[index]].size()==0)ump.erase(ind[index]);
        }
        ump[number].insert(index);
        ind[index]=number;
    }
    
    int find(int number) {
        if(ump.find(number)!=ump.end())return *ump[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */