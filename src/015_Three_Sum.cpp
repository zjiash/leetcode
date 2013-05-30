/*
 * =====================================================================================
 *
 *       Filename:  015_Three_Sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 21时45分02秒
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

vector<vector<int> > threeSum(vector<int> &num) {
	sort(num.begin(), num.end());

	vector<vector<int> > result;
	vector<int> res(3);
	int size = num.size();
	int a, b, c;
	bool first = true;
	vector<int>::iterator id;
	int pre;
	bool tag = true;
	for(int i = 0; i + 2 < size; i++){
		if(!tag && num[i] == pre)
		  continue;
		pre = num[i];
		tag = false;
		for(int j = i + 1; j + 1 < size; j++){
			int remain = 0 - num[i] - num[j];
			id = lower_bound(num.begin() + j + 1, num.end(), remain);
			if(id >= num.begin() + j + 1 && id < num.end() &&  (*id == remain)){
				if(first || a != num[i] || b != num[j] || c != *id){
					first = false;
					a = num[i];
					b = num[j];
					c = *id;
					res[0] = a;
					res[1] = b;
					res[2] = c;
					result.push_back(res);
				}
			}
		}
	}
	return result;
}


int main(){
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(-4);
	nums.push_back(2);
	vector<vector<int> > result = threeSum(nums);
	for(int i = 0; i < result.size(); i++){
		vector<int> res = result[i];
		for(int j = 0; j < res.size(); j++)
		  cout << res[j] << " ";
		cout << endl;
	}
	/*
	sort(nums.begin(), nums.end());
	cout << "Before nums is: ";
	for( unsigned int i = 0; i < nums.size(); i++ ) {
		cout << nums[i] << " ";
	}
	cout << endl;
	
	vector<int>::iterator result;
	int new_val = 2;
	result = lower_bound(nums.begin(), nums.end(), new_val );
	cout << result - nums.begin() << endl;
	new_val = 4;
	result = upper_bound(nums.begin(), nums.end(), new_val );
	cout << result - nums.begin() << endl;	
	*/
}
