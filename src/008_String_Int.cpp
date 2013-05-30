/*
 * =====================================================================================
 *
 *       Filename:  008_String_Int.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年04月30日 14时47分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

int atoi(const char *str) {
	if(str == NULL)
	  return 0;
	int res = 0;
	long long res2 = 0;
	int symbol = 0;
	int j = 0;
	while(str[j] == ' ')
	  j++;
	if(str[j] != '\0'){
		if(str[j] == '-')
		  symbol = -1;
		else symbol = 1;
	}
	for(int i = j; str[i]; i++){
		if(i == j && (str[i] == '+' || str[i] == '-'))
		  continue;
		
		if(str[i] >= '0' && str[i] <= '9'){
		  res = res * 10 + str[i] - '0'; 
		  res2 = res2 * 10 + str[i] - '0';
		  if(res2 != res)
			return symbol < 0 ? 0x80000000 : 0x7fffffff;
		}
		else break;
	}
	res *= symbol;
	if(res * symbol < 0)
	  res = symbol < 0 ? 0x80000000 : 0x7fffffff;
	return res;
}

