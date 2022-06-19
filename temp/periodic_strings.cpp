#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum number 
// of changes to make the string K- 
// periodic and palindrome 
int findMinimumChanges(int N, int K, 
					string S) 
{ 

	// Initialize ans with 0 
	int ans = 0; 

	// Iterate from 0 to (K+1) / 2 
	for (int i = 0; i < (K + 1) / 2; i++) { 

		// Store frequency of character 
		map<char, int> mp; 

		// Iterate through all indices, 
		// i, i+K, i+2k.... and store 
		// the frequency of character 
		for (int j = i; j < N; j += K) { 

			// Increase the frequency 
			// of current character 
			mp[S[j]]++; 
		} 

		// Iterate through all indices 
		// K-i, 2K-i, 3K-i.... and store 
		// the frequency of character 
		for (int j = N - i - 1; 
			j >= 0; j -= K) { 

			// If K is odd & i is samw 
			// as K/2, break the loop 
			if (K & 1 and i == K / 2) 
				break; 

			// Increase the frequency 
			// of current character 
			mp[S[j]]++; 
		} 

		// Find the maximum frequency 
		// of a character among all 
		// visited characters 
		int curr_max = INT_MIN; 
		for (auto p : mp) 
			curr_max = max(curr_max, 
						p.second); 

		// If K is odd and i is same 
		// as K/2 then, only N/K 
		// characters is visited 
		if (K & 1 and i == K / 2) 
			ans += (N / K - curr_max); 

		// Otherwise N/K * 2 characters 
		// has visited 
		else
			ans += (N / K * 2 - curr_max); 
	} 

	// Return the result 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	string S = "aabbcbbcb"; 
	int N = S.length(); 
	int K = 3; 

	// Function Call 
	cout << findMinimumChanges(N, K, S); 

	return 0; 
} 