#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = false;

bool bs(ll m, ll n, ll k){
  ll total = 0;
  while(m > 0){
    total += m;
    m /= k;
  }
  return total >= n;
}

void solve(){
  ll n, k; cin >> n >> k;

  ll l=1;
  ll r = n;
  ll ans;
  while(l<=r){
    ll m = l + (r-l)/2;
    if(bs(m,n,k)){
      ans = m;
      r = m-1;
    }else{
      l = m+1;
    }
  }

  cout << ans;

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}