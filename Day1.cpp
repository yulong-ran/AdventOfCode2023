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

	while(getline(file, text)){
		int first = 0, last = 0;

		for(char c: text){
			if(isdigit(c)){
				first = c - '0';
				break;
			}
		}
		
		reverse(text.begin(), text.end());

		for(char c: text){
			if(isdigit(c)){
				last = c - '0';
				break;
			}
		}

		res += first * 10 + last;
	}

	cout << res << "\n";

	return 0;
}
