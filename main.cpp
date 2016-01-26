#include <iostream>
#include "SuffixArray.hpp"

using namespace std;

int main(void) {
	SuffixArray sa(std::string("abcdefghijklmnopqrstuvwxyz"));
	sa.printAll();
	cout << sa.searchSubstring("was") << endl;
	cout << sa.searchSubstring("johnny") << endl;
	cout << sa.lowerBoundSubstring("bestitlala") << endl;
	cout << sa.getLongestCommonSubstring() << endl;
	return 0;
}