#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

ll next_prime(ll x){
  for(int i = x;;i++){
    bool is_prime = true;
    for(int j=2; j*j<=i; j++){
      if(i % j == 0){
        is_prime = false;
        break;
      }
    }
    if(is_prime) return i;
  }

}

void solve(){
  ll d; cin >> d;
  ll p = next_prime(d+1);
  ll q = next_prime(d+p);
  cout << min(p*p*p,p*q) << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}