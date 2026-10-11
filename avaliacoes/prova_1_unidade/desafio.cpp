#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = true;

void solve(){
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> mat(m, vector<ll>(n));

  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      cin >> mat[j][i];
    }
  }

  ll ans = 0;
  for(ll i = 0; i < m; i++){
    sort(mat[i].begin(), mat[i].end());

    ll prefix = 0;
    for(ll j = 0; j < n; j++){
      ans += mat[i][j] * j - prefix;
      prefix += mat[i][j];
    }
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}