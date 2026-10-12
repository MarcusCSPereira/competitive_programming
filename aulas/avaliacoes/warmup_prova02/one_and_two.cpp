#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;


bool many_cases = true;


void solve(){
  ll n; cin >> n;
  vector<ll> v(n);
  ll twos = 0;
  for(ll i = 0; i < n; i++){
    cin >> v[i];
    if(v[i] == 2) twos++;
  }

  if(twos % 2 != 0){
    cout << -1 << endl;
    return;
  }

  ll half = twos / 2, seen = 0;
  for(ll i = 0; i < n; i++){
    if(v[i] == 2) seen++;
    if(seen == half){
      cout << i + 1 << endl;
      return;
    }
  }
}


int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}
