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

	vector<string> digits {"one", "two", "three",
				"four", "five", "six",
				"seven", "eight", "nine"};

	auto getFirst = [&](string& s) -> pair<int,int>{
		int first_spell_digit_index = s.size();;
		int first_spell_digit = 0;

		for(int i=0; i<digits.size(); i++){
			auto j = s.find(digits[i]);

			if(j != string::npos && j < first_spell_digit_index){
				first_spell_digit = i + 1;
				first_spell_digit_index = j;
			}
		}

		int first_digit_index = s.size();
		int first_digit = 0;

		for(int i=0; i<s.size(); i++){
			if(isdigit(s[i])){
				first_digit_index = i;
				first_digit = s[i] - '0';
				break;
			}
				
		}

		int last_spell_digit_index = 0;;
		int last_spell_digit = -1;
		int last_digit_index = 0;
		int last_digit = -1;

		for(int i=0; i<digits.size(); i++){
			auto j = s.rfind(digits[i]);

			if(j != string::npos && j > last_spell_digit_index){
				last_spell_digit = i + 1;
				last_spell_digit_index= j;
			}
		}

		for(int i=s.size()-1; i>=0; i--){
			if(isdigit(s[i])){
				last_digit_index = i;
				last_digit = s[i] - '0';
				break;
			}
		}

		int d1 = first_spell_digit_index < first_digit_index ? first_spell_digit : first_digit;
		int d2 = last_spell_digit_index > last_digit_index ? last_spell_digit : last_digit;


		return {d1, d2};
	};

	while(getline(file, text)){
		auto [d1, d2] = getFirst(text);
		
		res += 1LL * d1 * 10 + d2;
	}

	cout << res << "\n";

	return 0;
}
