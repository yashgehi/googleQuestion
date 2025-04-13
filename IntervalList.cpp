#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ranges = {{3, 9}, {2, 8}, {5, 10}};

// Structure to hold sorted intervals along with their original indices
vector<pair<int, pair<int, int>>> sorted_with_indices;

void prepare() {
    sorted_with_indices.clear();
    for (int i = 0; i < ranges.size(); i++) {
        sorted_with_indices.push_back({ranges[i].first, {ranges[i].second, i}});
    }
    sort(sorted_with_indices.begin(), sorted_with_indices.end());
}

vector<int> f(int x) {
    set<int> result_set;
    
    // Binary search to find the first interval where start <= x
    auto it = lower_bound(sorted_with_indices.begin(), sorted_with_indices.end(), make_pair(x, make_pair(0, 0)));
    
    // Check intervals from the found position backwards
    for (auto pos = it; pos != sorted_with_indices.begin(); ) {
        pos--;
        if (pos->first <= x && pos->second.first >= x) {
            result_set.insert(pos->second.second);
        }
    }
    
    // Check intervals from the found position forwards
    for (auto pos = it; pos != sorted_with_indices.end(); pos++) {
        if (pos->first <= x && pos->second.first >= x) {
            result_set.insert(pos->second.second);
        }
    }
    
    // Convert the set to a vector
    vector<int> result(result_set.begin(), result_set.end());
    return result;
}

int main() {
    prepare();
    vector<int> res3 = f(3);
    vector<int> res9 = f(9);
    
    // Output the results for demonstration
    return 0;
}
