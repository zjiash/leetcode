/*
 * =====================================================================================
 *
 *       Filename:  030_Next_Permutation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月05日 20时50分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
using namespace std;

void swap(vector<int> &num, int i, int j){
	int tmp = num[i];
	num[i] = num[j];
	num[j] = tmp;
}

void nextPermutation(vector<int> &num) {
	int size = num.size();
	int small = size - 2;
	while(small >= 0 && num[small] >= num[small+1])
	  small--;
	if(small < 0){
		for(int i = 0, j = size - 1; i < j; i++, j--)
		  swap(num, i, j);
	} else {
		int k = size - 1;
		while(k > small){
			if(num[k] > num[small]){
				swap(num, k, small);
				break;
			}
			k--;
		}
		for(int i = small + 1, j = size - 1; i < j; i++, j--)
		  swap(num, i, j);
	}
}

int main(){
}
