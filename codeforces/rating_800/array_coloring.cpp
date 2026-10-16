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
  int n; cin >> n;
  int imp = 0;
  for(int i=0;i<n;i++){
    ll x; cin >> x;
    if(x%2!=0){
      imp++;
    }
  }

  if(imp%2==0){
    COUT("YES");
  }else{
    COUT("NO");
  }

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}