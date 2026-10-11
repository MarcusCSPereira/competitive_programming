#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x
typedef long long ll;

bool many_cases = false;

void solve(){
  ll n, k; cin >> n >> k;
  vector<pair<ll,ll>> v(n);
  for(ll i=0;i<n;i++){
    cin >> v[i].first;
    v[i].second = i+1;
  }

  sort(v.begin(), v.end());

  ll l =0;
  ll r= n-1;

  while(l<r){
    if(v[l].first + v[r].first == k) break;
    else if(v[l].first + v[r].first < k) l++;
    else r--;
  }

  if(r==l){
    cout << "IMPOSSIBLE";
  }else{
    cout << min(v[l].second,v[r].second) << " " << max(v[l].second,v[r].second);  
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t =1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}