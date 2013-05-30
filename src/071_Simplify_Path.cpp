/*
 * =====================================================================================
 *
 *       Filename:  071_Simplify_Path.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月13日 10时53分05秒
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
	string simplifyPath(string path) {
		string res;
		vector<string> dir_name;
		path += '/';
		size_t pre = 0;
		size_t index = path.find('/', pre + 1);
		while(index != string::npos){
			if(index > pre + 1){
				string tmp(path, pre + 1, index - pre - 1);
				if(tmp.compare("..") == 0){
					if(dir_name.size() > 0)
					  dir_name.pop_back();
				} else if(tmp.compare(".") == 0){
				} else {
					dir_name.push_back(tmp);
				}
			}
			pre = index;
			index = path.find('/', pre + 1);
		}
		for(int i = 0; i < dir_name.size(); i++){
			res += '/';
			res += dir_name[i];
		}
		if(dir_name.size() == 0)
		  res += '/';
		return res;
	}
};
