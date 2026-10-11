#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  ll n; cin >> n;
  vector<ll> v(n);
  for(auto &x : v){
    cin >> x;
  }

  sort(v.begin(),v.end());

  ll m = v[0 + (n-0)/2];
  ll ans = 0;
  for(int i=0; i<n; i++){
    ans += abs(m-v[i]);
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