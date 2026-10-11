#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  ll n; cin >> n;
  vector<pair<ll,ll>> p(n);
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    p[i].first = b;
    p[i].second = a;
  }

  sort(p.begin(),p.end());
  ll ans = 1;
  ll current = p[0].first;
  for(int i = 1;i<n;i++){
    if(p[i].second >= current){
      ans++;
      current = p[i].first;
    }
  }

  cout << ans << endl;
}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}