#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n;
	cin >> n; // Read the number of boxes
	vector<ll> v(n); // Vector to store the weights of the boxes
	for (auto &it : v) cin >> it; // Read the weights of the boxes

	vector<ll> pre(n); // Vector to store prefix sums
	pre[0] = v[0]; // Initialize the first prefix sum
	for (ll i = 1; i < n; i++) { // Calculate prefix sums
		pre[i] = v[i] + pre[i - 1];
	}

	ll ans = 0; // Variable to store the maximum absolute difference
	for (ll k = 1; k <= n; k++) { // Iterate over all possible k values
		if (n % k) continue; // If k does not divide n, skip this k
		ll start = k - 1; // Starting index for the first truck
		ll res = 0;
		ll maxi = pre[start]; // Initialize maximum sum for the first truck
		ll mini = pre[start]; // Initialize minimum sum for the first truck
		for (ll idx = start + k; idx < n; idx += k) { // Iterate over trucks
			ll curr = pre[idx] - pre[idx - k]; // Calculate current truck's weight
			maxi = max(maxi, curr); // Update maximum weight
			mini = min(mini, curr); // Update minimum weight
		}
		ans = max(ans, maxi - mini); // Update the maximum absolute difference
	}
	cout << ans << endl; // Output the result
	// Time Complexity (TC): O(nlogn)
	// Space Complexity (SC): O(n)
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t; // Read the number of test cases
	while (t--) {
		solve(); // Solve each test case
	}
}
