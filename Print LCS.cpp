/*A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F}, obtained after removal of elements C, E and F.

Given two strings A and B of size n and m respectively, you have to print the Longest Common Subsequence(LCS) of strings A and B, where LCS is the longest sequence present in both A and B.

Note: It is gauranteed that there is only one unique longest common subsequence

Input Format
Two strings A and B.

Constraints
1 <= n,m <= 10^3

Output Format
Output the LCS of A and B.

Sample Input
abc
acd
Sample Output
ac*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b; int n = a.size(); int m = b.size();
	   int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 ||j==0)
			dp[i][j]=0;
			else if(a[i-1]==b[j-1])
			{dp[i][j]=1+dp[i-1][j-1];}
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}


	}
	int index = dp[n][m];
	vector<char>lcs(index);
	int i=n; int j=m;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
        {
			lcs[index-1]=a[i-1];
			i--;j--;index--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		i--;
		else 
		j--;
	}

	for(int i=0;i<lcs.size();i++)
	cout<<lcs[i];


}
