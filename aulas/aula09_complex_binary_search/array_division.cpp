#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug (x) cout << #x << " = " << x << endl
typedef long long ll;

bool many_cases = false;

bool bs2(ll m, vector<ll> &v, ll k){
  ll splits = 1;
  ll sum = 0;
  for(int i=0;i<v.size();i++){
    if (v[i] > m){
      return false;
    }
    if(v[i] + sum > m){
      splits++;
      sum = v[i];
    }else{
      sum += v[i];
    }
  }

  return splits <=k;
}

void solve(){
  ll n,k; cin >> n >> k;
  vector<ll> v(n);
  ll max = 0;
  for (int i=0;i<n;i++){
    ll x;cin >> x;v[i] = x;
    max += v[i];
  }

  ll l = 0;
  ll r= max;
  ll ans = -1;

  while(l<=r){
    ll m;
    m = l + (r-l)/2;
    if(bs2(m, v, k)){
      ans = m;
      r = m -1;
    }else{
      l = m + 1;
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