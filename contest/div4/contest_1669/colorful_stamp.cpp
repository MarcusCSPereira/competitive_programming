#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = true;

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  int i = 0;

  while (i < n) {
      if (s[i] == 'W') {
          i++;
          continue;
      }

      bool hasR = false;
      bool hasB = false;

      while (i < n && s[i] != 'W') {
          if (s[i] == 'R') hasR = true;
          if (s[i] == 'B') hasB = true;
          i++;
      }

      if (!hasR || !hasB) {
        cout << "NO" << endl;
        return;
      }
  }

  cout << "YES" << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}