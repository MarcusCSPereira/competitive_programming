#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;

bool many_cases = false;

bool bs(ll mid, vector<ll> &v, ll k){
  vector<ll> cv = v;

  ll idx = -1;

  for(ll i=0;i<(ll)cv.size();i++){
    if(cv[i] < mid){
      idx = i;
    }
  }

  if(idx == -1){
    return true;
  }

  for(ll i=idx;i>=0 && k>0;i--,k--){
    cv[i] += k;
  }

  for(ll i=0;i<(ll)cv.size();i++){
    if(cv[i] < mid){
      return false;
    }
  }

  return true;
}

void solve(){
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  for(int i =0;i<n; i++){
    cin >> v[i];
  }

  ll l = 0;
  ll r = *max_element(v.begin(), v.end()) + k;
  ll ans = 0;

  while(l<=r){
    ll m = l + (r-l)/2LL;

    if(bs(m, v, k)){
      ans = m;
      l = m + 1;
    }else{
      r = m - 1;
    }
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}