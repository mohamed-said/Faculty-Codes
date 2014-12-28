#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class PrefixCode {
public:

	string toStr(int x) {
		stringstream ss;
		string s;
		ss << x;
		ss >> s;
		return s;
	}

	string isOne(vector<string> words) {
		if (words.size() == 1)
			return "Yes";

		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words.size(); j++) {
				if (words[i] == words[j])
					continue;
				if (words[j].find(words[i]) == 0) {
					return "No, " + toStr(i);
				}
			}

		}
		return "Yes";
	}
};
