/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: C++
@Datetime: 16-03-07 03:23
*/

#define MAX_INT  2147483647
typedef enum  {
	k_Valid,
	k_Invalid
} status;

status g_Status = k_Valid;

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
	int atoi(string s){
		if (s.empty()){
			g_Status = k_Invalid;
			return 0;
		}
		long long result = 0;
		bool minus = false;

		int i = 0;
		const string ss = s;
		while (ss[i] == ' '){
			i++;
		}
		if (ss[i] == '+'){
			i++;
		} else if (ss[i] == '-'){
			minus = true;
			i++;
		}
		while (ss[i] != '\0')
		{
			if (ss[i] <'0' || ss[i] >'9'){
				break;
			}
			else{
				result = result * 10 + static_cast<int>(ss[i] - '0');
				if (result > MAX_INT){
					if (!minus){
						result = MAX_INT;
					}
					else {
						result = 0 - MAX_INT - 1;
					}
					return static_cast<int>(result);
				}
				i++;
			}
		}
		if (minus){
			result = 0 - result;
		}
		return static_cast<int>(result);
	}
};