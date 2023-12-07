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
	
	vector<char> scores {'A', 'K', 'Q', 'J',
		'T', '9', '8', '7', '6', '5',
		'4', '3', '2'};

	reverse(scores.begin(), scores.end());

	unordered_map<char, int> score_map;

	for(int i=0; i<scores.size(); i++){
		score_map[scores[i]] = i;
	}


	int FIVE = 7, FOUR = 6, FULL = 5, THREE = 4,
	    TWO = 3, ONE = 2, HIGH = 1;

	vector<pair<string, long long>> A;

	auto getScore = [&](string s) -> int {
		string count = "";

		unordered_map<char,int> mp;

		for(auto& c: s) mp[c] += 1;

		for(auto& [_, c]: mp) count += to_string(c);

		sort(count.rbegin(), count.rend());

		if(count == "5") return FIVE;
		if(count == "41") return FOUR;
		if(count == "32") return FULL;
		if(count == "311") return THREE;
		if(count == "221") return TWO;
		if(count == "2111") return ONE;

		return 1;
	};

	while(getline(file, text)){
		int i = text.find(" ");
		string card = text.substr(0, i);
		long long credit = stoll(text.substr(i + 1));

		A.push_back({card, credit});
	}

	sort(A.begin(), A.end(), [&](const auto& s1, const auto& s2){
			int score1 = getScore(s1.first);
			int score2 = getScore(s2.first);

			if(score1 != score2) return score1 < score2;

			for(int i=0; i<s1.first.size(); i++){
				int c1 = score_map[s1.first[i]];
				int c2 = score_map[s2.first[i]];

				if(c1 == c2) continue;

				return c1 < c2;
			}
			
			return false;
	});

	long long res = 0;

	for(int i=0; i<A.size(); i++){
		res += A[i].second * (i + 1);
	}

	cout << "Answer: " << res << endl;

	return 0;
}
