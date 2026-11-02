#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

ll xor_till(ll n){
  ll x = n % 4;
  if(x == 0){
    return n;
  }else if(x==1){
    return 1;
  }else if(x == 2){
    return n+1;
  }else{
    return 0;
  }
}

void solve(){
  ll a, b; cin >> a >> b;
  ll arr_xor = xor_till(a-1);
  if(arr_xor == b){
    COUT(a);
  }else if((arr_xor ^ b) != a){
    COUT(a+1);
  }else{
    COUT(a+2);
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}