#include "DP.h"

int LCSubstring(const string& word_a, const string& word_b)
{
	int ceil[word_a.size() + 1][word_b.size() + 1];
	for(int i = 0; i <= word_a.size(); ++i){
		ceil[i][0] = 0;
	}
	for(int j = 0; j <= word_b.size(); ++j){
		ceil[0][j] = 0;
	}

	int ret = 0;

	for(int i = 1; i <= word_a.size(); ++i){
		for(int j = 1; j <= word_b.size(); ++j){
			if(word_a[i - 1] == word_b[j - 1]){   // take care of the index
				ceil[i][j] = ceil[i - 1][j - 1] + 1;
				ret = max(ret, ceil[i][j]);  // update the result
			}
			else{
				ceil[i][j] = 0;
			}
		}
	}

	return ret;
}

int LCSubequence(const string& word_a, const string& word_b)
{
	int ceil[word_a.size() + 1][word_b.size() + 1];
	for(int i = 0; i <= word_a.size(); ++i){
		ceil[i][0] = 0;
	}
	for(int j = 0; j <= word_b.size(); ++j){
		ceil[0][j] = 0;
	}

	for(int i = 1; i <= word_a.size(); ++i){
		for(int j = 1; j <= word_b.size(); ++j){
			if(word_a[i - 1] == word_b[j - 1]){  // take care of the index
				ceil[i][j] = ceil[i - 1][j - 1] + 1;
			}
			else{
				ceil[i][j] = max(ceil[i - 1][j], ceil[i][j - 1]);
			}
		}
	}

	return ceil[word_a.size()][word_b.size()];
}

int LISubsequence1(const vector<int>& nums)
{
	vector<int> lis(nums.size(), 1);
	vector<int>::size_type i, j;
	for(i = 1; i < nums.size(); ++i){
		for(j = 0; j < i; ++j){
			if(nums[i] > nums[j]){
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}
	return *max_element(lis.begin(), lis.end());
}

int LISubsequence2(const vector<int>& nums)
{
	vector<int> lis(nums.size(), 1);
	vector<int>::size_type i, j;
	for(i = 0; i < nums.size(); ++i){
		for(j = i + 1; j < nums.size(); ++j){
			if(nums[j] > nums[i]){
				lis[j] = max(lis[j], lis[i] + 1);
			}
		}
	}
	return *max_element(lis.begin(), lis.end());
}

int LISubsequence3(const vector<int>& nums)
{
    vector<int> help;
    help.push_back(nums[0]);
    int len = 1, index = 0;
    vector<int>::size_type i;
    for(i = 1; i < nums.size(); ++i){
        if(nums[i] > help[len - 1]){
            help.push_back(nums[i]);
            ++len;
        }
        else{
            index = BinarySearch(help, nums[i]);
            help[index] = nums[i];
        }
    }
    return len;
}

int BinarySearch(const vector<int>& nums, int num)
{
    int left = 0, right = nums.size() - 1;
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(num < nums[mid]){
            right = mid - 1;
        }
        else if(num > nums[mid]){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }
    return left; // 若没有找到元素num，则返回该元素应该插入的位置
}
