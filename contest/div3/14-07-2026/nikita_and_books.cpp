#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;
const int tam_limit = 1e5 + 1;

bool many_cases = true;

void solve(){
  READVEC(n, v, ll, ll);
  for(int i=0;i<n;i++){
    ll need = i+1;
    if(v[i] < need){
      COUT("NO");
    }

    if(i+1 <n){
      ll sobra = v[i] - need;
      v[i] = need;
      v[i+1] += sobra;
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