#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  ll n; cin >> n;
  ll f = n; // se não encontrar, n é primo.
  for(int i=2; i*i<=n; i++){
    if(n % i == 0){
      f = i;
      break;
    }
  }

  ll a = n / f;
  ll b = n - a;

  cout << a << " " << b << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}