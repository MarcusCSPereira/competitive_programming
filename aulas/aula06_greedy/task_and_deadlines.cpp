#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  ll n; cin >> n;
  vector<pair<ll,ll>> v;
  for(int i =0;i<n;i++){
    ll t, d; cin >> t >> d;
    v.push_back({t,d});
  }

  sort(v.begin(),v.end());

  ll ans=0;
  ll at = 0;
  for(int i=0; i<n; i++){
    at += v[i].first;
    ans += v[i].second - at;
  }

  cout << ans;

}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}