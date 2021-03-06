// LeetCode3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.length();
		//Length of input.
		int longest[1000000];
		//Length of the longest substring ending with s[i].
		int status[128];
		//Assume there are only ASCII characters, status[i] means the index in the input string, where the i is a ASCII value.
		int maxl;
		//Final answer.
		fill_n(status, 128, -1);
		//Fill the status array with -1. -1 means the char of i ASCII value hasn't appeared yet.
		if (s != "") {
			//If the input string is not null, work out the answer.
			maxl = 1;
			status[int(s[0])] = 0;
			longest[0] = 1;
			//Deal with the border, the first letter in the input string.
			for (int i = 1; i < len; i++) {
				//Go through the input string.
				if (status[int(s[i])] == -1) {
					//If current letter hasn't appeared, excute this branch.
					longest[i] = longest[i - 1] + 1;
					//Connect this letter to the previous substirng.
				}
				else {
					//If current letter has appeared, excute this branch.
					longest[i] = i - status[int(s[i])];
					//We can get a new longest substring, countring from the position where the appeared letter last appears.
					//Therefore, there won't be any repeated letters in the new substring.
					for (int j = i - longest[i - 1]; j < status[int(s[i])]; j++) {
						status[int(s[j])] = -1;
						//Modify status for those letters not in the new substring to no appeared.
					}
				}
				status[int(s[i])] = i;
				//Modify the current letter's status (position) in the new substring.
				if (longest[i] > maxl) {
					maxl = longest[i];
					//If get larger answer, renew the final answer.
				}
			}
		}
		else {
			//If the input string is null, just return 0.
			maxl = 0;
		}
		return maxl;
		//Done.
	}
};

int main()
{
    return 0;
}

