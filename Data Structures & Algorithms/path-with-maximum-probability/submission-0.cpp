class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<double, vector<pair<double, double>>> adj_list;
        unordered_map<double, double> best_prob;
        for (double i = 0; i < n; i++) {
            best_prob[i] = -1.0;
            adj_list[i] = {};
        }
        for (int i = 0; i < edges.size(); i++) {
            double a = (double)edges[i][0];
            double b = (double)edges[i][1];
            double prob = succProb[i];
            adj_list[a].push_back({b, prob});
            adj_list[b].push_back({a, prob});
        }
        double start = (double)start_node;
        double end = (double)end_node;
        priority_queue<pair<double, double>> heap; //<probability, node>
        heap.push({1, start});
        while (!heap.empty()) {
            pair<double, double> val = heap.top();
            double curr_prob = val.first;
            double node = val.second;
            heap.pop();
            // cout << node << " " << curr_prob << endl;
            if (best_prob[node] == -1.0) {
                best_prob[node] = curr_prob;
                if (node == end) return curr_prob;
                vector<pair<double, double>> neighbors = adj_list[node];
                for (pair<double, double> p : neighbors) {
                    double next_node = p.first;
                    double next_prob = p.second;
                    heap.push({next_prob*curr_prob, next_node});
                }
            }
        }
        return 0;
    }
};