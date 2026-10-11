#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<vector<double>> g(n, vector<double>(n, 0.0));

    g[0][0] = t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (g[i][j] > 1.0) {
                double over = g[i][j] - 1.0;
                g[i][j] = 1.0;

                if (i + 1 < n) {
                    g[i + 1][j] += over / 2.0;
                    g[i + 1][j + 1] += over / 2.0;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (g[i][j] >= 1.0) {
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}