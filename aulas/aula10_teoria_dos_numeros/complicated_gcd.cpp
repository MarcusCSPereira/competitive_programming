#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;

int gcd(ll a, ll b){
  return b == 0 ? a : gcd(b,a%b);
}

void solve(){
  string a, b; cin >> a >> b;

  if (a == b) cout << a;
  if (a!=b) cout << 1;
  
}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}