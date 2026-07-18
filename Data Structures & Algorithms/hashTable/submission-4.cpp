class HashTable {
public:
    vector<pair<int, int>> table;
    int capacity;
    int size = 0;

    HashTable(int capacity) {
        this->table = vector<pair<int, int>>(capacity, {-1, -1});
        this->capacity = capacity;
    }

    void insert(int key, int value) {
        int real_key = key;
        if (key >= capacity) key = key % capacity;
        if (table[key].first == -1 && table[key].second == -1) {
            table[key].first = real_key; table[key].second = value;
            size++;
        } else if (table[key].first == real_key) {
            table[key].second = value;
        } else {
            //collision; solution is open addressing
            int i = key;
            while (table[i].first != -1 && table[i].second != -1) {
                i++;
                if (i >= capacity) i = i % capacity;
            }
            table[i].first = real_key; table[i].second = value;
            size++;
            //note that we don't have a danger of running into the same key value,
            //because that would've triggered the same hashing
            //which would have been caught by an earlier conditional
        }
        
        if (size >= capacity/2) {
            resize();
        }


        cout << endl;
        for (int i = 0; i < table.size(); i++) {
            cout << table[i].first << " " << table[i].second << endl;
        }
        cout << endl;
    }

    int get(int key) {
        int real_key = key;
        if (key >= capacity) key = key % capacity;
        if (table[key].first != real_key) {
            int i = key;
            while (table[i].first != real_key) {
                i++;
                if (i >= capacity) i = i % capacity;
                if (i == key) return -1;
            }
            return table[i].second;
        } else {
            return table[key].second; //value
        }
    }

    bool remove(int key) {
        int real_key = key;
        if (key >= capacity) key = key % capacity;
        if (table[key].first != real_key) {
            int i = key;
            while (table[i].first != real_key) {
                i++;
                if (i >= capacity) i = i % capacity;
                if (i == key) return false;
            }
            table[i].first = -1; table[i].second = -1;
            size--;
            return true;
            // return table[i].second;
        } else {
            table[key].first = -1; table[key].second = -1;
            size--;
            return true;
            // return table[key].second; //value
        }

    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void resize() {
        capacity*=2;
        vector<pair<int, int>> new_table(capacity, {-1, -1});
        for (int i = 0; i < table.size(); i++) {
            pair<int, int> p = table[i];
            if (p.first != -1 && p.second != -1) {
                int new_index = p.first % capacity;
                while (new_table[new_index].first != -1 && new_table[new_index].second != -1) {
                    new_index++;
                    new_index = new_index % capacity;
                }
                new_table[new_index].first = p.first; new_table[new_index].second = p.second;
            }
        }
        table = new_table;


        cout << endl;
        for (int i = 0; i < table.size(); i++) {
            cout << table[i].first << " " << table[i].second << endl;
        }
        cout << endl;
    }
};