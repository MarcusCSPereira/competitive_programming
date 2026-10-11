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
  READVEC(n,v,ll,ll);
  sort(v.begin(), v.end());
  ll min_v = v[0];
  ll max_v = v[n-1];
  if(min_v == max_v){
    cout << "NO" << endl; return;
  }else{
    cout << "YES" << endl;
    cout << max_v << " ";
    for(int i=0;i<n-1;i++){
      cout << v[i] << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}