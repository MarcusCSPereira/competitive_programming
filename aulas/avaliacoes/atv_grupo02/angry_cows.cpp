#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(vector<ll> &h, int meio, int k) {
    int nV = 0;
    int rV = 0;
    for(int i = 0; i < h.size(); i++) {
        if(h[i] > rV) {
            nV++;
            rV = h[i] + (2 * meio);
        }
    }

    return nV <= k;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n, k;

    cin >> n;
    cin >> k;

    vector<ll> h(n);

    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    int l = 0;
    int r = h[n - 1];
    int ans = -1;

    while(l <= r) {
        int meio = l + (r - l) / 2;

        if(f(h, meio, k)) {
            ans = meio;
            r = meio - 1;
        } else {
            l = meio + 1;
        }
    }

    cout << ans << endl;

    return 0;
}