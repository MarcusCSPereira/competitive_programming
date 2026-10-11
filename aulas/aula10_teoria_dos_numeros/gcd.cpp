#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;

int gcd(int a, int b){
  return b == 0 ? a : gcd(b,a%b);
}

void solve(){
  int a, b, c; cin >> a >> b >> c;
  cout << gcd(a,gcd(b,c));
}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}