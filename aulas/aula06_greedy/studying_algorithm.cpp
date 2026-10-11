#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  ll n, x; cin >> n >> x;
  vector<int> v(n); for(auto &x : v) cin >> x;
  ll ans = 0;
  sort(v.begin(), v.end());
  for(int i = 0;i<n;i++){
    if(x>=v[i]){
      x = x - v[i];
      ans ++;
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