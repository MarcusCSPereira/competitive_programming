#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll n;cin >> n;
  ll m; cin >> m;

  vector<ll> v(n);
  for(auto &x : v) cin >> x;

  sort(v.rbegin(), v.rend());
  ll ans =0;
  for(auto &x: v){
    if (m<=0){
      break;
    }else{
      m = m-x;
      ans++;
    }
  }

  cout << ans;

  return 0;
}