#include <string>
#include <vector>
#include <set>
#include <cctype>  // isalpha

class SimilarityChecker {
public:
	int getLengthScore(std::string s1, std::string s2) {
		int score = calcLengthScore(s1.length(), s2.length());
		return score;
	}

	int getAlphaScore(std::string s1, std::string s2) {
        int totalCount = countUniqueAlphabets(s1 + s2);
        int sameCount = countCommonAlphabets(s1, s2);
		int score = 40 * sameCount / totalCount;
		return score;
	}

private:
	int calcLengthScore(int len1, int len2) {
		if (len1 < len2) std::swap(len1, len2);
		if (len1 == len2) return 60;
		return 60 * (1 - (len1 - len2) / len2);
	}

	int countUniqueAlphabets(const std::string& str) {
		std::set<char> uniqueAlphabets;

		for (char c : str) {
			if (std::isalpha(c)) {
				// 대소문자 구분 없이 알파벳을 추가 (소문자로 변환)
				uniqueAlphabets.insert(std::tolower(c));
			}
		}

		return uniqueAlphabets.size();  // 고유한 알파벳의 개수 반환
	}

    int countCommonAlphabets(const std::string& str1, const std::string& str2) {
        std::set<char> alphabets1;
        std::set<char> alphabets2;

        // 첫 번째 문자열에서 알파벳 추출
        for (char c : str1) {
            if (std::isalpha(c)) {
                alphabets1.insert(std::tolower(c));  // 소문자로 변환하여 삽입
            }
        }

        // 두 번째 문자열에서 알파벳 추출
        for (char c : str2) {
            if (std::isalpha(c)) {
                alphabets2.insert(std::tolower(c));  // 소문자로 변환하여 삽입
            }
        }

        // 두 set에서 공통된 알파벳 찾기
        int commonCount = 0;
        for (char c : alphabets1) {
            if (alphabets2.find(c) != alphabets2.end()) {
                commonCount++;  // 공통된 알파벳이 있으면 카운트
            }
        }

        return commonCount;
    }

};