/*
 * =====================================================================================
 *
 *       Filename:  017_Four_Sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月03日 15时24分02秒
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

vector<vector<int> > fourSum(vector<int> &num, int target) {
	sort(num.begin(), num.end());

	vector<vector<int> > res;
	vector<int> tmp(4);
	int size = num.size();
	for(int i = 0; i + 3 < size; i++){
		if(i > 0 && num[i] == num[i-1])
		  continue;
		for(int j = i + 1; j + 2 < size; j++){
			if(j > i + 1 && num[j] == num[j-1])
			  continue;
			int l = j + 1, r = size - 1;
			while(l < r){
				int sum = num[i] + num[j] + num[l] + num[r];
				if(sum < target)
				  l++;
				else if(sum > target)
				  r--;
				else{
					if(l > j + 1 && num[l] == num[l-1]){
						//duplicated
					} else {
						tmp[0] = num[i];
						tmp[1] = num[j];
						tmp[2] = num[l];
						tmp[3] = num[r];
						res.push_back(tmp);
					}
					l++;
					r--;
				}
			}

		}
	}

	return res;
}

int main(){
}
