/*
 * =====================================================================================
 *
 *       Filename:  084_Largest_Rectangle_Histogram.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月15日 15时00分23秒
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

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int nSize = height.size();
		int l[nSize + 1];//left bar position
		int h[nSize + 1];//height of the left bar
		l[0] = h[0] = 0;
		int cur_h = 0;
		int max = 0;
		int top = 0;
		for(int i = 0 ; i<= nSize; ++i){
			cur_h = i==nSize? 0: height[i];
			int j = i;

			for(; h[top] > cur_h; j = l[top--]){
				int temp = (i - l[top]) * h[top];
				if(temp > max){
					max = temp;
				}
			}
			if(cur_h > h[top]){
				h[++top] = cur_h;
				l[top] = j;
			}
		}
		return max;
	}
};

int main(){
	int a[6] = {2, 1, 5, 6, 2, 3};
	vector<int> b(a, a + sizeof(a)/sizeof(int));
	Solution s;
	cout << s.largestRectangleArea(b) << endl;
}
