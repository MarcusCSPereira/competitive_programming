#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl
#define endl "\n"
typedef long long ll;

void solve(){

  ll n, m; cin >> n >> m;
  multiset<ll> ms;
  for (int i = 0; i< n; i++) {
    ll num; cin >> num;
    ms.insert(num);
  }

  vector<ll> v(m); for (auto &i : v) cin >> i;

  for(int i=0; i<m; i++){
    auto lb = ms.lower_bound(v[i]);
    //debug(*lb);
    if(lb != ms.end() && *lb == v[i]){
      cout << *lb << endl;
      ms.erase(lb);
    }else{
      if (lb != ms.begin()) {
        lb--;
        cout << *lb << endl;
        ms.erase(lb);
      }else{
        cout << -1 << endl;
      }
    }
  }
}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll t=1;
  if(many_cases) cin >> t;
  while(t--) solve();

  return 0;
}