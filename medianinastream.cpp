#include <bits/stdc++.h>
using namespace std;
void balance(priority_queue<int> &maxhp, priority_queue<int, vector<int>, greater<int>> &minhp)
{
	if (maxhp.size() > minhp.size() + 1)
	{
		int z = maxhp.top();
		minhp.push(z);
		maxhp.pop();
	}

	else if (minhp.size() > maxhp.size())
	{
		int z = minhp.top();
		minhp.pop();
		maxhp.push(z);
	}
}
vector<int> findMedian(vector<int> &arr, int n)
{

	// Write your code here
	priority_queue<int> maxhp;
	priority_queue<int, vector<int>, greater<int>> minhp;
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		if (maxhp.size() == 0 || maxhp.top() > arr[i])
			maxhp.push(arr[i]);
		else
			minhp.push(arr[i]);
		balance(maxhp, minhp);
		if (i % 2 == 0)
			ans.push_back(maxhp.top());
		else
			ans.push_back((maxhp.top() + minhp.top()) / 2);
	}
	return ans;
}
