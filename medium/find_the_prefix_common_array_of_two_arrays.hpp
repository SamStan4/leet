#pragma once

#include "../imports.hpp"

#if 0
// can cover an infinite range of integers

class Solution {
public:
	vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
		const int n = A.size();
		vector<int> answer(n, 0);
		unordered_map<int, int> fA, fB;
		for (int i = 0; i < n; ++i) {
			if (A[i] == B[i]) {
				++answer[i];
			} else {
				++fA[A[i]];
				++fB[B[i]];
				if (fA.find(B[i]) != fA.end() && fA[B[i]] > 0) {
					++answer[i];
					--fA[B[i]];
				}
				if (fB.find(A[i]) != fB.end() && fB[A[i]] > 0) {
					++answer[i];
					--fB[A[i]];
				}
			}
			if (i > 0) {
				answer[i] += answer[i-1];
			}
		}
		return answer;
	}
};

#elif 0
// cant cover an infinite range of integers, but is way faster

class Solution {
public:
	vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        	const int n = A.size();
		vector<int> fA(n + 1, 0), fB(n + 1, 0), answer(n, 0);
		for (int i = 0; i < n; ++i) {
			if (A[i] == B[i]) {
				++answer[i];
			} else {
				++fA[A[i]];
				++fB[B[i]];
				if (fA[B[i]] > 0) {
					++answer[i];
					--fA[B[i]];
				}
				if (fB[A[i]] > 0) {
					++answer[i];
					--fB[A[i]];
				}
			}
			if (i > 0) {
				answer[i] += answer[i-1];
			}
		}
		return answer;
	}
};

#else
// uses minimal memory, and is fast af

class Solution {
public:
	vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
		const int n = A.size();
		unsigned long long af = 0, bf = 0;
		vector<int> answer(n, 0);
		for (int i = 0; i < n; ++i) {
			af |= 1ULL << A[i];
			bf |= 1ULL << B[i];
			answer[i] = __builtin_popcountll(af & bf);
		}
		return answer;
	}
};

#endif