/*
 * =====================================================================================
 *
 *       Filename:  072_Edit_Distance.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月13日 14时01分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define N 501

class Solution {
	int a[N][N];
public:
	int getMin(int a, int b, int c){
		int min = a < b ? a : b;
		return min < c ? min : c;
	}
	
	int minDistance(string word1, string word2) {
		memset(a, 0, sizeof(a));
		int s1 = word1.size();
		int s2 = word2.size();
		for(int i = 0; i <= s2; i++)
		  a[0][i] = i;
		for(int i = 0; i <= s1; i++)
		  a[i][0] = i;
		for(int i = 1; i <= s1; i++){
			for(int j = 1; j <= s2; j++){
				int x = a[i - 1][j] + 1;
				int y = a[i][j - 1] + 1;
				int z = a[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
				a[i][j] = getMin(x, y, z);
			}
		}
		return a[s1][s2];
	}
};
