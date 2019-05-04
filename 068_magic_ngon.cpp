// brute force solution... people have done this on pen and paper!
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int check(vector<int> &nums) {
	int n = nums.size();
	int commonsum = 0;
	for(int i = 1; i < n; i += 2) {
		int sum = nums[i-1] + nums[i] + nums[(i+2)%n];
		if(commonsum == 0) commonsum = sum;
		else if(commonsum != sum) return -1;
	}
	return commonsum;
}

string anstostring(vector<int> &nums) {
	int n = nums.size();
	string ans = "";
	for(int i = 1; i < n; i += 2) {
		ans += to_string(nums[i-1]);
		ans += to_string(nums[i]);
		ans += to_string(nums[(i+2)%n]);
	}
	return ans;
}

int main() {
	int n;
	cin>>n;

	vector<int> nums(2*n);
	for(int i = 1; i<=2*n; i++) nums[i-1] = i;

	
	map<int, vector<string> > ansbydigs;
	map<int, int> sumcounts;
	do {
		int sum = check(nums);
		if(sum > 0) {
			if(sumcounts.count(sum)) sumcounts[sum]++;
			else sumcounts[sum] = 1;

			string ans = anstostring(nums);
			int d = ans.length();
			if(ansbydigs.count(d)) ansbydigs[d].push_back(ans);
			else {
				ansbydigs[d] = vector<string>(); 
				ansbydigs[d].push_back(ans);
			}
		}
	} while(next_permutation(nums.begin(), nums.end()));

	map<int, int>::iterator it1 = sumcounts.begin();
	while(it1 != sumcounts.end()) {
		cout<<"sum = "<<(*it1).first<<": "<<((*it1).second)/n<<'\n';
		it1++;
	}

	map<int, vector<string> >::iterator it2 = ansbydigs.begin();
	while(it2 != ansbydigs.end()) {
		sort((*it2).second.begin(), (*it2).second.end());
		cout<<"digits = "<<(*it2).first<<'\n';
		int s = (*it2).second.size();
		for(int i = 0; i<s; i++) 
			cout<<'\t'<<(*it2).second[i]<<'\n';
		it2++;
	}
	return 0;
}
