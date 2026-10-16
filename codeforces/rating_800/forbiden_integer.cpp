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
  ll n, k, x;
  cin >> n >> k >> x;

  if (x != 1){
    cout << "YES" << endl;
    cout << n << endl;
    for (ll i = 0; i < n; i++) cout << 1 << " ";
    COUT("");
  }

  if (k == 1 || (k == 2 && n % 2 == 1)){
    COUT("NO");
  }

  cout << "YES" << endl;
  if (n % 2 == 0){
    cout << n / 2 << endl;
    for (ll i = 0; i < n / 2; i++) cout << 2 << " ";
    cout << endl;
  } else {
    cout << (n - 3) / 2 + 1 << endl;
    for (ll i = 0; i < (n - 3) / 2; i++) cout << 2 << " ";
    cout << 3 << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}