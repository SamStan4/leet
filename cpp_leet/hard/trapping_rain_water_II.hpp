#pragma once

#include "./../imports.hpp"

class Solution {
public:
	int trapRainWater(vector<vector<int>>& g) {
		const int R = g.size(), C = g[0].size();
		vector<vector<bool>> vis(R, vector<bool>(C, false));
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, std::greater<pair<int, pair<int, int>>>> pq;

		for (int r = 0; r < R; ++r) {
			pq.push({g[r][0], {r, 0}});
			pq.push({g[r][C-1], {r, C-1}});
			vis[r][0] = true;
			vis[r][C-1] = true;
		}

		for (int c = 1; c < C - 1; ++c) {
			pq.push({g[0][c], {0, c}});
			pq.push({g[R-1][c], {R-1, c}});
			vis[0][c] = true;
			vis[R-1][c] = true;
		}

		int mbh = 0, vol = 0;

		while (!pq.empty()) {
			const int h = pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
			pq.pop();

			mbh = max(mbh, g[r][c]);
			
			if ((r - 1) >= 0 && !vis[r-1][c]) {
				pq.push({g[r-1][c], {r-1, c}});
				vis[r-1][c] = true;
				if (g[r-1][c] < mbh) {
					vol += mbh - g[r-1][c];
				}
			}

			if ((r + 1) < R && !vis[r+1][c]) {
				pq.push({g[r+1][c], {r+1, c}});
				vis[r+1][c] = true;
				if (g[r+1][c] < mbh) {
					vol += mbh - g[r+1][c];
				}
			}

			if ((c - 1) >= 0 && !vis[r][c-1]) {
				pq.push({g[r][c-1], {r, c-1}});
				vis[r][c-1] = true;
				if (g[r][c-1] < mbh) {
					vol += mbh - g[r][c-1];
				}
			}

			if ((c + 1) < C && !vis[r][c+1]) {
				pq.push({g[r][c+1], {r, c+1}});
				vis[r][c+1] = true;
				if (g[r][c+1] < mbh) {
					vol += mbh - g[r][c+1];
				}
			}
		}

		return vol;
	}
};
