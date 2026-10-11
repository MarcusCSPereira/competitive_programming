#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x
#define endl "\n"
typedef long long ll;

void solve(){
  ll n, q; cin >> n >> q;
  vector<ll> v(n); for (auto &x : v) cin >> x;
  sort(v.begin(),v.end());

  while(q--){
    ll n1, n2; cin >> n1 >> n2;

    auto value_1 = lower_bound(v.begin(), v.end(), n1);
    auto value_2 = upper_bound(v.begin(), v.end(), n2);

    cout << value_2 - value_1 << endl;
  }
}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);


  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}