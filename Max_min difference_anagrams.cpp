  // C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the lexicographically
// smallest anagram of string
// which contains another string
pair<string, int> lexico_smallest(string s1,
								string s2)
{

	// Initializing the map and set
	map<char, int> M;
	set<char> S;
	pair<string, int> pr;

	// Iterating over s1
	for (int i = 0; i <= s1.size() - 1; ++i) {

		// Storing the frequency of
		// characters present in s1
		M[s1[i]]++;

		// Storing the distinct
		// characters present in s1
		S.insert(s1[i]);
	}

	// Decreasing the frequency of
	// characters from M that
	// are already present in s2
	for (int i = 0; i <= s2.size() - 1; ++i) {
		M[s2[i]]--;
	}

	char c = s2[0];
	int index = 0;
	string res = "";

	// Traversing alphabets
	// in sorted order
	for (auto x : S) {

		// If current character of set
		// is not equal to current
		// character of s2
		if (x != c) {
			for (int i = 1; i <= M[x]; ++i) {
				res += x;
			}
		}
		else {

			// If element is equal to
			// current character of s2
			int j = 0;
			index = res.size();

			// Checking for second
			// distinct character in s2
			while (s2[j] == x) {
				j++;
			}

			// s2[j] will store
			// second distinct character
			if (s2[j] < c) {
				res += s2;
				for (int i = 1; i <= M[x]; ++i) {
					res += x;
				}
			}
			else {
				for (int i = 1; i <= M[x]; ++i) {
					res += x;
				}
				index += M[x];
				res += s2;
			}
		}
	}

	pr.first = res;
	pr.second = index;

	// Return the answer
	return pr;
}

// Function to find the lexicographically
// largest anagram of string
// which contains another string
string lexico_largest(string s1, string s2)
{

	// Getting the lexicographically
	// smallest anagram
	pair<string, int> pr = lexico_smallest(s1, s2);

	// d1 stores the prefix
	string d1 = "";
	for (int i = pr.second - 1; i >= 0; i--) {
		d1 += pr.first[i];
	}

	// d2 stores the suffix
	string d2 = "";
	for (int i = pr.first.size() - 1;
		i >= pr.second + s2.size(); --i) {
		d2 += pr.first[i];
	}

	string res = d2 + s2 + d1;

	// Return the result
	return res;
}

// Driver Code
int main()
{
	// Given two strings
	string s1 = "ethgakagmenpgs";
	string s2 = "geeks";

	// Function Calls
	cout << lexico_smallest(s1, s2).first
		<< "\n" ;
	cout << lexico_largest(s1, s2);

	return (0);
}
