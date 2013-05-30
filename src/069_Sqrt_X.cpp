/*
 * =====================================================================================
 *
 *       Filename:  069_Sqrt_X.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月12日 23时38分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
	int sqrt(int x) {
		long long l = 0, r = 200000;
		while(l < r){
			long long mid = (l + r) / 2;
			printf("%lld %lld %lld\n", l, r, mid);
			if(l == mid)
			  return (int) l;
			long long squ = mid * mid;
			if(squ > x)
			  r = mid;
			else if(squ < x)
			  l = mid;
			else 
			  return (int) mid; 
		}
		return (int) l;
	}
};

int main(){
	int x;
	Solution s;
	while(true){
		cin >> x;
		if(x < 0)
		  break;
		cout << s.sqrt(x) << endl;
	}
}
