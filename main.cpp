#include <iostream>
#include <string>
#include <sstream>
#include "DP.h"

using namespace std;

int main()
{

    string ret;

    stringstream ss;
    ss << 21;
    ret += ss.str();
    cout << ret << endl;

// 最长上升子序列（Longest Increasing Subsequence，LIS）
//    vector<int> nums = {3,1,4,1,5,9,2,6,5};//{1, 3, 2, 5, 8, 9, 7, 8, 10};
//	cout << LISubsequence1(nums) << endl;
//	cout << LISubsequence2(nums) << endl;
//	cout << LISubsequence3(nums) << endl;

// 最长公共子序列（Longest Common Subsequence, LCS）
//    string a, b;
//	while(cin >> a >> b){
//		cout << LCSubequence(a, b) << endl;;
//	}

// 最长公共子串（Longest Common Substring）
//    string a, b;
//	while(cin >> a >> b){
//		cout << LCSubstring(a, b) << endl;;
//	}

    return 0;
}
