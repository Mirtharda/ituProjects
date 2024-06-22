#include <iostream>

//MAP implementation from scratch

using namespace std;

template <typename K, typename V>
struct Entry {
    public:
        Entry(K& k = K(), V& v = V()) : _key(k), _value(v) {};
        K& key() { return _key; }
        V& value() { return _value; }
        void setKey(K& k) { _key = k; }
        void setValue(V& v) { _value = v; }
    private:
        K _key;
        V _value;
        friend struct Iterator<K,V>;
};

template <typename K, typename V>
struct Iterator {
    private:
        Entry<K,V>* currentEntry = NULL;
    public: 
        Iterator(Entry<K,V>* start = NULL) : currentEntry(start) {};
        Entry<K,V>* getNextEntry(Entry<K,V>* entry);
};

template <typename K, typename V>
struct Map {
private:
    Entry<K,V>* entries;
    int _size;
public:
    Map() : entries(nullptr), _size(0) {}
    ~Map() {
        delete[] entries;
    }
    int size() {
        return _size;
    }
    bool empty() {
        return _size == 0;
    }
    Iterator<K,V> find(const K& k) {
        // Implementation of find
    }
    Iterator<K,V> put(const K& k, const V& v) {
        // Implementation of put
    }
    void erase(const K& k) {
        // Implementation of erase
    }
    void erase(const Iterator<K,V>& p) {
        // Implementation of erase
    }
    Iterator<K,V> begin() {
        return Iterator<K,V>(entries);
    }
    Iterator<K,V> end() {
        return Iterator<K,V>(nullptr);
    }
};


int main() {
    // Your code here

    return 0;
}
