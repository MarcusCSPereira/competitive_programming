#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = false;

void solve(){
  int n; cin >> n;
  vector<pair<int,int>> eventos;
  for(int i=0;i<n;i++){
    int saidas, entradas;
    cin >> saidas >> entradas;
    eventos.push_back({i, entradas});
    eventos.push_back({i, -saidas});
  }

  sort(eventos.begin(), eventos.end());

  int ans=0;
  int temp=0;
  for(auto e : eventos){
    temp += e.second;
    ans = max(ans, temp);
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}