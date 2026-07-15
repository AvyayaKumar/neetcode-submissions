class KthLargest {
public:
    int k; vector<int> nums;
    vector<int> prior_queue = {0};
    void insert(int num) {
        if (prior_queue.size() == 1) {
            // only the dummy value, pass the root
            prior_queue.push_back(num);
            return;
        } else {
            //insert value at the end
            prior_queue.push_back(num);
            //percolate upwards
            int index = prior_queue.size()-1; //index of last added element
            while (prior_queue[index] < prior_queue[index/2]) {
                int temp = prior_queue[index];
                prior_queue[index] = prior_queue[index/2];
                prior_queue[index/2] = temp;
                index /= 2;
                if (index == 1) break;
            }
        }
    }

    int pop() {
        if (prior_queue.size() == 1) {
            return 0;
        }
        int res = prior_queue[1];
        prior_queue[1] = prior_queue[prior_queue.size()-1];
        prior_queue.pop_back();
        int i = 1;
        while (i*2 < prior_queue.size()) {
            if ((2*i)+1 < prior_queue.size()) {
                if (prior_queue[i] > prior_queue[2*i+1] && prior_queue[2*i+1] < prior_queue[2*i]) {
                    //swap with right child
                    int temp = prior_queue[i];
                    prior_queue[i] = prior_queue[2*i+1];
                    prior_queue[2*i+1] = temp;
                    i = 2*i+1;
                } else if (prior_queue[i] > prior_queue[2*i]) {
                    //swap with left child
                    int temp = prior_queue[i];
                    prior_queue[i] = prior_queue[2*i];
                    prior_queue[2*i] = temp;
                    i = 2*i;
                } else {
                    break;
                }
            } else if (prior_queue[i] > prior_queue[2*i]) {
                //swap with left child
                int temp = prior_queue[i];
                prior_queue[i] = prior_queue[2*i];
                prior_queue[2*i] = temp;
                i = 2*i;
            } else {
                break;
            }
        }
        return res;
    }

    KthLargest(int k_inp, vector<int>& nums_inp) {
        // cout << "hi" << endl;
        k = k_inp; nums = nums_inp; sort(nums.begin(), nums.end(), greater<int>());
        if (nums.size() > 0) {
            for (int i = 0; i < k; i++) {
                if (i < nums.size()) {
                    insert(nums[i]);
                }
            }
        }
        // for (int i : prior_queue) cout << i << " ";
        // cout << endl;
        // int x = pop(); cout << x;
        // for (int i : prior_queue) cout << i << " ";
        // cout << endl;
    }

    int add(int val) {
        if (prior_queue.size() == 1) {
            prior_queue.push_back(val); return val;
        }
        if (prior_queue.size() < k+1) {
            insert(val); return prior_queue[1];
        }
        if (val > prior_queue[1]) {
            int tmp = pop(); insert(val);
        }
        for (int i : prior_queue) cout << i << " ";
        cout << endl;
        return prior_queue[1];
    }
};

