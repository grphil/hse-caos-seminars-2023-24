#include <immintrin.h>
#include <bits/stdc++.h>

#pragma GCC target("avx2") // -mavx compile flag

void example() {
	__m256i a, b;

	//_mm<bits>_<func>_<type>
	/*
	Types:
	ps - float
	pd - double
	epi8, epi16, epi32 ... signed
	epu8, epu16 ... unsigned
	si128, si256 bits


	*/
}

int maxx(int* a, int n) {
	__m256i mx = _mm256_set1_epi32(INT_MIN);

	int i = 0;
	for (; i + 8 <= n; i += 8) {
		__m256i curr = _mm256_lddqu_si256(reinterpret_cast<__m256i*>(a + i));
		mx = _mm256_max_epi32(mx, curr);
	}

	int res = INT_MIN;
	for (; i < n; i++) {
		res = std::max(res, a[i]);
	}


	int max_arr[8];
	_mm256_storeu_si256(reinterpret_cast<__m256i*>(max_arr), mx);

	for (int i = 0; i < 8; i++) {
		res = std::max(res, max_arr[i]);
	}

	return res;
}