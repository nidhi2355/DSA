#include <unordered_map>
#include <list>

using namespace std;

struct Node {
    int key;
    int value;
    int freq;
    Node(int k, int v, int f) : key(k), value(v), freq(f) {}
};

class LFUCache {
private:
    int cap;
    int minFreq;
    unordered_map<int, list<Node>::iterator> keyTable;
    unordered_map<int, list<Node>> freqTable;

    void updateFreq(list<Node>::iterator nodeIt) {
        int key = nodeIt->key;
        int value = nodeIt->value;
        int freq = nodeIt->freq;

        // Remove from current frequency list
        freqTable[freq].erase(nodeIt);
        if (freqTable[freq].empty()) {
            freqTable.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        // Insert into updated frequency list (most recently used goes to the front)
        freqTable[freq + 1].emplace_front(key, value, freq + 1);
        keyTable[key] = freqTable[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (cap == 0 || keyTable.find(key) == keyTable.end()) {
            return -1;
        }

        auto nodeIt = keyTable[key];
        int val = nodeIt->value;
        updateFreq(nodeIt);
        return val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        // If key already exists, update value and increment frequency
        if (keyTable.find(key) != keyTable.end()) {
            auto nodeIt = keyTable[key];
            nodeIt->value = value;
            updateFreq(nodeIt);
            return;
        }

        // Evict LFU (and LRU in tiebreak) if at capacity
        if (keyTable.size() == cap) {
            auto lruNode = freqTable[minFreq].back();
            keyTable.erase(lruNode.key);
            freqTable[minFreq].pop_back();
            if (freqTable[minFreq].empty()) {
                freqTable.erase(minFreq);
            }
        }

        // Insert new key with freq = 1
        minFreq = 1;
        freqTable[1].emplace_front(key, value, 1);
        keyTable[key] = freqTable[1].begin();
    }
};