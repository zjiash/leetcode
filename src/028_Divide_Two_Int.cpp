/*
 * =====================================================================================
 *
 *       Filename:  028_Divide_Two_Int.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月04日 12时47分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int divide(int dividend, int divisor) {
	long long result = 0;
	long long a = dividend, b = divisor;
	int sign = 1;
	if((a < 0 && b > 0) || (a > 0 && b < 0)){
		sign = -1;
	}

	a = a<0?-a:a;
	b = b<0?-b:b;

	vector<long long> mul;
	long long tmp = b;
	while(tmp <= a){
		mul.push_back(tmp);
		tmp = tmp << 1;
	}
	mul.push_back(tmp);

	vector<long long >::iterator idx;
	while(a >= b){
		idx = upper_bound(mul.begin(), mul.end(), a);
		result += 1 << (idx - 1 - mul.begin());
		a -= *(idx - 1);
	}

	if(sign == -1)
	  return (int)(-result);
	return (int)result;
}

int main(){
	int a, b;
	while(true){
		cin >> a >> b;
		if(b == 0)
		  break;
		cout << divide(a, b) << endl;
	}
}
