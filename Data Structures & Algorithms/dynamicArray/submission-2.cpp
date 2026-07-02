class DynamicArray {
public:
    
    int capacity = 0;
    int* arr;

    DynamicArray(int capacity5) {
        capacity = capacity5;
        arr = new int[capacity](0);
    }

    int curr_index = 0;

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (curr_index < capacity) {
            arr[curr_index] = n;
            curr_index++;
        } else {
            // This is when the array is full, so we need to resize
            resize();
            arr[curr_index] = n;
            curr_index++;
        }
    }

    int popback() {
        int n = arr[curr_index-1];
        curr_index--;
        return n;
    }

    void resize() {
        capacity = capacity*2;
        int *newArr = new int[capacity](0);
        for (int i = 0; i < capacity/2; i++) {
            newArr[i] = arr[i];
        }
        arr = newArr;
    }

    int getSize() {
        return curr_index;
    }

    int getCapacity() {
        return capacity;
    }
};
