#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
#include <bitset>

using namespace std;

void solve(){
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ifstream file;
	string text;
	file.open("input.txt", ios::in);

	long long res = 0;
	vector<string> mat;
	
	while(getline(file, text)){
		mat.push_back(text);
	}

	int dirs[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
	
	int m = mat.size(), n = mat[0].size();
	auto check = [&](int i, int j) -> bool {
		for(auto& dir: dirs){
			int x = i + dir[0], y = j + dir[1];

			if(x >= 0 && x < m && y >= 0 && y < n
					&& mat[x][y] != '.'
					&& !isdigit(mat[x][y])){
				return true;
			}
		}

		return false;
	};
	
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[0].size(); j++){
			int val = 0;
			bool hasSymbol = false;

			while(isdigit(mat[i][j])){
				hasSymbol |= check(i, j);
				val = val * 10 + (mat[i][j] - '0');
				j += 1;
			}

			if(hasSymbol){
				res += val;
			}
		}
	}

	cout << res << "\n";

	return 0;
}
