/*
 * =====================================================================================
 *
 *       Filename:  016_Three_Sum_Close.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 15时08分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <algorithm>
using namespace std;

#define ABS(x) ((x)<0?-(x):(x))

int threeSumClosest(vector<int> &num, int target) {
	sort(num.begin(), num.end());
	int size = num.size();

	bool first = true;
	int sum = 0;
	for(int i = 0; i < size; i++){
		int l = i+1, r = size - 1;
		while(l < r){
			int tmp = num[i] + num[l] + num[r];
			if(first){
				sum = tmp;
				first = false;
			}
			if(ABS(tmp - target) < ABS(sum - target)){
				sum = tmp;
			}
			if(tmp < target)
			  l++;
			else if(tmp > target)
			  r--;
			else 
			  return tmp;
		}
	}
	return sum;
}

int main(){
}
