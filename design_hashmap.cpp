class MyHashMap {
public:
    /** Initialize your data structure here. */
    map<int,int>m;
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        m[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(m.find(key) == m.end())
        {
            return -1;
        }
        return m[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(m.find(key) != m.end())
        {
            m.erase(key);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
