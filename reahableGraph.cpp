pair<bool,int> solve(const int n, const vector<tuple<int,int,int,int>>& flights, const int origin, const int dest) {
    vector<vector<tuple<int,int,int>>> adj(n);
    for (const auto& [from, to, dep, arr] : flights)
        adj[from].emplace_back(dep, arr, to);
    vector dist(n, INT_MAX);
    dist[origin] = 0;
    vector<bool> visited(n);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, origin);
    while (!pq.empty()) {
        const auto [_, curr] = pq.top();
        pq.pop();
        if (visited[curr])
            continue;
        visited[curr] = true;
        const int now = dist[curr];
        if (curr == dest) {
            return {true, now};
        }
        for (const auto& [dep, arr, to] : adj[curr])
            if (dep >= now && dist[to] > arr) {
                dist[to] = arr;
                pq.emplace(-arr, to);
            }
    }
    return {false, -1};
}

int main() {
    solve(3, {{0,1,0,4},{1,2,5,7}}, 0, 2); // true, 7
    solve(3, {{0,1,0,4},{1,2,3,5}}, 0, 2); // false, -1
}
