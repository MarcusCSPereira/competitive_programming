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
  ll n, k;
  cin >> n >> k; 
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];

  ll ans = INT_MAX;
  ll even_count = 0; // Count of even numbers in the array
  for (ll i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0)
      even_count++; // Increment even_count if the element is even
    if (a[i] % k == 0)
      ans = 0; // If any element is divisible by k, no operations are needed
    ans = min(ans, (k - a[i] % k)); // Calculate the minimum operations needed
  }

  // Special handling for k = 4
  if (k == 4)
  {
    if (even_count >= 2)
      ans = min(ans, 0LL); // If there are at least two even numbers, no operations are needed
    else if (even_count == 1)
      ans = min(ans, 1LL); // If there is one even number, one operation is needed
    else if (even_count == 0)
      ans = min(ans, 2LL); // If there are no even numbers, two operations are needed
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}