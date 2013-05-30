/*
 * =====================================================================================
 *
 *       Filename:  011_Water_Container.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 16时29分34秒
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
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxArea(vector<int> &height){
	/* naive method
	int maxSize = 0;
	for(int i = 0; i < height.size(); i++){
		for(int j = i + 1; j < height.size(); j++){
			int sum = (j - i) * MIN(height[i], height[j]);
			if(sum > maxSize)
			  maxSize = sum;
		}
	}
	*/
	int maxSize = 0;
	int len = height.size();
	int l = 0, r = len - 1;
	while(l < r){
		int sum = (r - l) * MIN(height[l], height[r]);
		if(sum > maxSize)
		  maxSize = sum;
		if(height[l] < height[r]){
			int k = l;
			while(k < r && height[k] <= height[l])
			  k++;
			l = k;
		} else {
			int k = r;
			while(k > l && height[k] <= height[r])
			  k--;
			r = k;
		}
	}
	return maxSize;
}

int main(){
	vector<int> a;
	int b;
	while(true){
		cin >> b;
		a.push_back(b);
		if(b == 0)
		  break;
	}
	cout << maxArea(a) << endl;
}
