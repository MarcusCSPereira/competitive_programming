#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = false;

void solve(){
  ll n;
  ll x;
  cin >> n >> x;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll l = 0;
  ll sum = 0;
  ll ans = 0;

  for (ll r = 0; r < n; r++) {
      sum += a[r];

      while (sum > x) {
          sum -= a[l];
          l++;
      }

      if (sum == x) {
          ans++;
      }
  }

  cout << ans << '\n';

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t =1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}