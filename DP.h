#ifndef DP_H
#define DP_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ������Ӵ���Longest Common Substring��
int LCSubstring(const string& word_a, const string& word_b);

// ����������У�Longest Common Subsequence, LCS��
int LCSubequence(const string& word_a, const string& word_b);

// ����������У�Longest Increasing Subsequence��LIS��
int LISubsequence1(const vector<int>& nums);
int LISubsequence2(const vector<int>& nums);
int LISubsequence3(const vector<int>& nums);
int BinarySearch(const vector<int>& nums, int num);

#endif // DP_H
