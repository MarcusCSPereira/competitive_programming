#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x
typedef long long ll;

bool many_cases = false;

void solve(){
  ll le, d, n; cin >> le >> d >> n;
  vector<ll> b(n);
  for(ll i=0;i<n;i++){
    cin >> b[i];
  }

  sort(b.begin(), b.end());

  ll ans=0;

  ll l= 6;
  ll r;

  for(int i =0; i < b.size(); i++){
    r = b[i];
    ans += ((r-l)/d) + 1;
    l = r;
  }
  
  r = le - 6;
  ans += ((r-l)/d) + 1;
  ans -= n*2;
  cout << ans;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t =1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}