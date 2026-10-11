#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){
  ll n; cin >> n;
  multiset<ll> v;
  for (int i = 0; i< n;i++){
    ll x; cin >> x;

    auto it = v.upper_bound(x);
    if(it == v.end()){
      v.insert(x);
    }else{
      v.erase(it);
      v.insert(x);
    }
  }

  cout << v.size();

}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}