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
  ll n;
  cin >> n;
  char color;
  cin >> color;
  string s;
  cin >> s;
  s += s;
  n *= 2;

  ll last_green_index = -1;
  ll max_seconds = INT_MIN;

  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == 'g')
      last_green_index = i;

    if (s[i] == color)
    {
      ll difference = last_green_index - i;
      max_seconds = max(max_seconds, difference);
    }
  }
  cout << max_seconds << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}