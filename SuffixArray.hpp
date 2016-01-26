#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

typedef unsigned long int ul;
typedef pair<ul, string> pairuls;

class SuffixArray {
public:
	SuffixArray(const string& str) {
		for (int i = 0; i < str.size(); i++)
			substrings.push_back(make_pair(i, &str[i]));

		sort(substrings.begin(), 
			 substrings.end(), 
			 [](pairuls a, pairuls b) { return a.second < b.second; });
	}

	long lowerBoundSubstring(const string& subs) {
		auto lower_b = lower_bound(substrings.begin(), substrings.end(), subs, Comp());
		if (lower_b == substrings.end()) return -1;
		return lower_b->first;
	}

	long searchSubstring(const string& subs) {
		auto lower_b = lower_bound(substrings.begin(), substrings.end(), subs, Comp());
		if (lower_b == substrings.end()) return -1;
		return lower_b->second.substr(0, subs.size()) == subs ? lower_b->first : -1;
	}

	string getLongestCommonSubstring() {
		string lcs = "";
		for (int i = 0; i < substrings.size() - 1; i++) {
			auto suffix = getIdenticalStart(substrings[i].second, substrings[i + 1].second);
			if (suffix.size() > lcs.size()) lcs = suffix;
		}

		return lcs;
	}

	void printAll() {
		for (auto t : substrings) cout << t.first << " " << t.second << endl;
	}

	~SuffixArray() {
		substrings.clear();
	}

private:
	vector<pair<ul, string>> substrings;

	struct Comp {
		// Two overloads because comparison needs to be done 
		// both ways to check for equality
		bool operator()(const pairuls& lhs, const string& rhs) const {
			return lhs.second < rhs;
		}

		bool operator()(const string& lhs, const pairuls& rhs) const {
			return lhs < rhs.second;
		}
	};

	string getIdenticalStart(const string& str1, const string& str2) {
		auto bigger = str1.size() > str2.size() ? str1 : str2;
		auto smaller = str1.size() > str2.size() ? str2 : str1;
		stringstream ss;

		for (int i = 0; i < smaller.size(); i++) {
			if (bigger[i] == smaller[i]) 
				ss << bigger[i];
			else
				break;
			
		}

		return ss.str();
	}

};
