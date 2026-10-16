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
		ll n, p;
		cin >> n >> p;
		vector<pair<ll, ll>> v(n);
		vector<ll> a(n), b(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];
      
		for (int i = 0; i < n; i++)
			cin >> b[i];
    
		for (int i = 0; i < n; i++)
			v[i] = {b[i], a[i]};

		sort(v.begin(), v.end());

		ll minimum_cost = p; 
		ll already_shared = 1;

		for (auto it : v)
		{
			ll can_be_shared = it.second; // Max number of residents this resident can share with
			ll sharing_cost = it.first; // Cost for this resident to share

			// If the sharing cost is greater than or equal to direct sharing cost, break
			if (sharing_cost >= p)
				break;

			// If sharing with all possible residents exceeds total residents, adjust
			if (already_shared + can_be_shared > n)
			{
				minimum_cost += (n - already_shared) * sharing_cost;
				already_shared = n; // All residents are informed
				break;
			}
			else
			{
				minimum_cost += can_be_shared * sharing_cost; // Add cost for sharing
				already_shared += can_be_shared; // Update the count of informed residents
			}
		}

		// Add the cost for the remaining residents to be informed directly
		minimum_cost += (n - already_shared) * p;
		cout << minimum_cost << endl; // Output the minimum cost for this test case
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}