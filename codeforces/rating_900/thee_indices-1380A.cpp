#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  // Procura por um pico local adjacente
  for (int j = 1; j < n - 1; j++) {
    if (p[j - 1] < p[j] && p[j] > p[j + 1]) {
      cout << "YES\n";
      cout << j << " " << j + 1 << " " << j + 2 << "\n"; // +1 devido à indexação 1-based
      return;
    }
  }

  cout << "NO\n";
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}