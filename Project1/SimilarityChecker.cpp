#include <string>
#include <vector>

class SimilarityChecker {
public:
	int getScore(std::string s1, std::string s2) {
		int len1 = s1.length(), len2 = s2.length();
		if (len1 > len2) std::swap(len1, len2);

		if(len1==len2) return 60;

		return (1 - (len1 - len2) / len2);

	}
};