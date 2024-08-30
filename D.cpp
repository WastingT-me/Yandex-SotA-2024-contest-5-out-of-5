#include <iostream>
#include <vector>

using namespace std;

long long ways(int n, int m) {
    vector<long long> path(2 * n + 1, 0);
    path[n] = 1;

    for (int i = 1; i <= n; ++i) {
        vector<long long> update_path(2 * n + 1, 0);
        for (int j = 1; j < 2 * n; ++j) {
            update_path[j] = (path[j-1] + path[j] + path[j+1]) % m; //
        }
        path = update_path;
    }

    return path[n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    cout << ways(n, m) << endl;
    return 0;
}