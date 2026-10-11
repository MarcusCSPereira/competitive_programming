#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve(){
  string a, b ,c; cin >> a; cin >> b; cin >> c;

  for(int i = 0 ; i < a.size() ; i++){
    if (c[i] != a[i] && c[i] != b[i]){
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n; while(n--) solve();
  return 0;
}