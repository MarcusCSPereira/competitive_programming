#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,op,b,c) for (int i =a; i op b; i += c)
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
typedef long long ll;
typedef __int128 i128;

bool many_cases = true;

void solve(){
  ll n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> paridade(k,0);
  for(int i=0;i<=n;i++){
    if (s[i] == '1'){
      paridade[i%k] ^=1;
    }
  }

  for(int i=0;i<k;i++){
    if(paridade[i] == 1){
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}