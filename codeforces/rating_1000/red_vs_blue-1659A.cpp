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
  int n, r, b; cin >> n >> r >> b;
  int tam_red = r/(b+1);
  int extra_red = r%(b+1);
  string s = "";
  for(int i = 1; i <= b+1 ;i++){ // b+1
    for(int j =0; j<tam_red;j++){ // r/b+1
      s+= 'R';
    }
    if(extra_red >0){
      s+= 'R';
      extra_red--;
    }
    if(i != b+1){
      s+= 'B';
    }
  }

  cout << s << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}