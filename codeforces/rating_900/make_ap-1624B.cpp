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
  long long a, b, c;
  cin >> a >> b >> c;

  bool answer = false;

  // Check if multiplying 'a' by some positive integer can make the sequence an AP
  long long new_a = 2 * b - c; // Calculate the potential new value for 'a'
  if (new_a / a > 0 && new_a % a == 0) // Check if new_a is a positive multiple of 'a'
    answer = true;

  // Check if multiplying 'b' by some positive integer can make the sequence an AP
  long long new_b = (a + c) / 2; // Calculate the potential new value for 'b'
  if (new_b / b > 0 && new_b % b == 0 && (c - a) % 2 == 0) // Check if new_b is a positive multiple of 'b' and (c-a) is even
    answer = true;

  // Check if multiplying 'c' by some positive integer can make the sequence an AP
  long long new_c = 2 * b - a; // Calculate the potential new value for 'c'
  if (new_c / c > 0 && new_c % c == 0) // Check if new_c is a positive multiple of 'c'
    answer = true;

  if (answer)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}
