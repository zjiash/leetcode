/*
 * =====================================================================================
 *
 *       Filename:  059_Permutation_Sequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月10日 20时15分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		vector<int> num;
		int a[9];
		a[0] = 1;
		for(int i = 1; i <= n; i++){
			a[i] = a[i-1]*i;
			num.push_back(i);
		}
		if(k > a[n])
		  return res;
		int start = n - 1;
		while(!num.empty()){
			int	first = (k + a[start] - 1) / a[start];
			res += (char)(num[first - 1]  + '0');
			num.erase(num.begin() + first - 1, num.begin() + first);
			k -= (first - 1) * a[start];
			start--;
		}

		return res;
	}
};

int main(){
	int n, k;
	Solution s;
	while(true){
		cin >> n >> k;
		if(n == 0)
		  break;
		cout << s.getPermutation(n, k) << endl; 
	}
}
