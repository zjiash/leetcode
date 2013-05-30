/*
 * =====================================================================================
 *
 *       Filename:  027_Str_Str.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年05月04日 10时26分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

char *strStr(char *haystack, char *needle) {
	char *cp = haystack;

	if(!*needle)
	  return cp;

	int nsize = strlen(needle), hsize = strlen(haystack);
	int *next = new int[nsize];
	next[0] = -1;
	int i = 0, k = -1;
	while(i < nsize){
		while(k >= 0 && needle[i] != needle[k])
		  k = next[k];
		i++;
		k++;
		if(i == nsize)
		  break;
		if(needle[i] == needle[k])
		  next[i] = next[k];
		else next[i] = k;
	}
	
	i = k = 0;
	while(i < nsize && k < hsize){
		if(i == -1 || needle[i] == haystack[k])
		  i++, k++;
		else i = next[i];
	}
	if(i == nsize)
	  retirn (cp + j - nsize + 1);
	return NULL;
	
}
