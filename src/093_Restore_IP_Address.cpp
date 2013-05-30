/*
 * =====================================================================================
 *
 *       Filename:  093_Restore_IP_Address.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月16日 17时13分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
public:
	bool solve(string &tmp, int len){
		if(len == 1)
		  return true;
		if(tmp[0] == '0')
		  return false;
		int num = atoi(tmp.c_str());
		if(num > 255)
		  return false;
		return true;
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		int size = s.size();
		if(size < 4 || size > 12)
		  return res;
		int num;
		string tmp[4];
		for(int i = 1; i < size - 2; i++){
			tmp[0] = s.substr(0, i);
			if(!solve(tmp[0], i))
			  continue;
			for(int j = i + 1; j < size - 1; j++){
				tmp[1] = s.substr(i, j-i);
				if(!solve(tmp[1], j-i))
				  continue;
				for(int k = j + 1; k < size; k++){
					tmp[2] = s.substr(j, k-j);
					if(!solve(tmp[2], k-j))
					  continue;
					tmp[3] = s.substr(k, size-k);
					if(!solve(tmp[3], size-k))
					  continue;
					res.push_back(string(tmp[0] + "." + tmp[1] + "." + tmp[2] + "." + tmp[3]));
				}
			}
		}
		return res;
	}
};
