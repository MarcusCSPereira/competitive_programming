#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x
typedef long long ll;

bool many_cases = false;

void solve(){
  ll a, b , k; cin >> a >> b >> k;
  vector<ll> v1(a);
  vector<ll> v2(b);
  for (int i = 0; i < a; i++) cin >> v1[i];
  for (int i = 0; i < b; i++) cin >> v2[i];

  vector<ll> p1(a+1,0);
  vector<ll> p2(b+1,0);

  for(int i =1; i<=max(a,b); i++){
    if (i < a+1) p1[i] = p1[i-1] + v1[i-1];
    if (i < b+1) p2[i] = p2[i-1] + v2[i-1];
  }

  ll ans = 0;
  for(int i=0; i<=a; i++){
    ll resto = k - p1[i];
    
    ll j = 0;
    if(resto >= 0){
      auto it = upper_bound(p2.begin(), p2.end(), resto);
      if (it == p2.end()){
        j = b;
      }else{
        j = it - p2.begin() - 1;
      }
      ans = max(ans,i+j);
    }
  }


  cout << ans;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t =1;
  if(many_cases) cin >> t;
  while(t--) solve();
}