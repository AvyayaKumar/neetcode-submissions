class MinHeap {
public:
    vector<int> v = {0};

    MinHeap() {}

    void push(int val) {
        v.push_back(val);
        if(v.size()==2) return;
        int i = v.size()-1;
        while (v[i/2] > v[i]) {
            if (i==1) break;
            //swap
            int temp=v[i];
            v[i]=v[i/2];
            v[i/2]=temp;
            i/=2;
        }
        for(int i=0; i<v.size(); i++) {
            cout<<v[i]<< " ";
        }
        cout << endl;
    }

    int pop() {
        if(v.size()==1) return -1;
        if(v.size()==2) {
            int temp = v[1]; v.pop_back(); return temp;
        }
        int res = v[1];
        v[1] = v[v.size()-1];
        int i = 1;
        //percolate downward
        while (2*i < v.size()) { //while there's a left child
            if (2*i+1 < v.size()) { // if there's a right child as well
                if (v[i] > v[2*i+1] && v[2*i+1] < v[2*i]) {
                    cout << "case1" << endl;
                    int temp=v[i];
                    v[i]=v[2*i+1];
                    v[2*i+1]=temp;
                    i=2*i+1;
                } else if (v[i] > v[2*i]) {
                    cout << "case2" << endl;
                    int temp=v[i];
                    v[i] = v[2*i];
                    v[2*i] = temp;
                    i=2*i;
                } else {
                    cout << "case3" << endl;
                    break;
                }
            } else if (v[i] > 2*i) { //only a left child

                cout << "case4" << endl;
                int temp=v[i];
                v[i] = v[2*i];
                v[2*i] = temp;
                i=2*i;
            } else {
                cout << "case5" << endl;
                break;
            }
        }
        v.pop_back();
        for(int i=0; i<v.size(); i++) {
            cout<<v[i]<< " ";
        }
        cout << endl;

        return res;
    }

    int top() {
        if(v.size()==1) return -1;
        return v[1];
    }

    void heapify(const vector<int>& arr) {
        // recall the only condition to the order is that each child must be larger than the parent
        v = arr;
        if(v.size()==0) {
            v.push_back(0);
            return;
        }
        v.push_back(v[0]); v[0] = 0;
        if(v.size()==2) return;
        int i = v.size()-1; i/=2;
        while (i >= 1) {
            while (2*i < v.size()) { //while there's a left child
                if (2*i+1 < v.size()) { // if there's a right child as well
                    if (v[i] > v[2*i+1] && v[2*i+1] < v[2*i]) {
                        cout << "case1" << endl;
                        int temp=v[i];
                        v[i]=v[2*i+1];
                        v[2*i+1]=temp;
                        i=2*i+1;
                    } else if (v[i] > v[2*i]) {
                        cout << "case2" << endl;
                        int temp=v[i];
                        v[i] = v[2*i];
                        v[2*i] = temp;
                        i=2*i;
                    } else {
                        cout << "case3" << endl;
                        break;
                    }
                } else if (v[i] > 2*i) { //only a left child
                    cout << "case4" << endl;
                    int temp=v[i];
                    v[i] = v[2*i];
                    v[2*i] = temp;
                    i=2*i;
                } else {
                    cout << "case5" << endl;
                    break;
                }
            }
            i--;
        }
    }

    void printall() {
        for (int i:v) cout << i << " ";
        cout<<endl;
    }
};