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

	long long res = 0, cur = 0;

	vector<long long> A;

	while(getline(file, text)){
		if(text == ""){
			A.push_back(cur);
			cur = 0;
		}else{
			cur += stol(text);
		}
	}

	sort(A.rbegin(), A.rend());

	for(int i=0; i<min((int)A.size(), 3); i++){
		res += A[i];
	}

	cout << res << "\n";

	return 0;
}
