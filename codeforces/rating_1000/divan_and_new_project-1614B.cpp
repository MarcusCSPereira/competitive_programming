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
		vector<ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];

		vector<pair<ll, ll>> building_map;
		for (int i = 0; i < n; i++)
			building_map.push_back({a[i], i});

		sort(building_map.rbegin(), building_map.rend());

		vector<ll> ans(n + 1, 0);

		ans[0] = 0;

		ll minutes = 0;
		ll coordinate = 1;
		for (int i = 0; i < n; i++)
		{
			ans[building_map[i].second + 1] = coordinate;
			minutes += (2 * abs(coordinate) * building_map[i].first);
			if (coordinate < 0)
				coordinate = abs(coordinate) + 1;
			else
				coordinate = -coordinate;
		}

		cout << minutes << endl;
		for (auto it : ans)
			cout << it << " ";
		cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}