#include <string>
#include <vector>

class SimilarityChecker {
public:
	int getScore(std::string s1, std::string s2) {
		if(s1.length()==s2.length()) return 60;
	}
};