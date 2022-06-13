#include<bits/stdc++.h>
using namespace std;

bool isValidShuffle(string s1, string s2, string s3) {
	string s12 = s1 + s2;

	if(s12.size() != s3.size()) {
		return false;
	}

	sort(s12.begin(), s12.end());
	sort(s3.begin(), s3.end());

	if(s12 == s3) {
		return true;
	}

	return false;
}

int main()
{
	string s1, s2, s3;
	cin>>s1>>s2>>s3;

	cout<<isValidShuffle(s1, s2, s3);

	return 0;
}