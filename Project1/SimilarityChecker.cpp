#include <string>
#include <vector>

class SimilarityChecker {
public:
	int getScore(std::string s1, std::string s2) {
		int score = calcLengthScore(s1.length(), s2.length());
		
		return score;

	}
	int calcLengthScore(int len1, int len2)	{
		if (len1 == len2) return 60;
		if (len1 <  len2) std::swap(len1, len2);
		return (60 - 60 * (len1 - len2) / len2);
	}
};