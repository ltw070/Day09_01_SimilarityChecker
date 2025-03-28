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
		if (len1 == len2) return 60;
		if (len1 <  len2) std::swap(len1, len2);
		return (60 - 60 * (len1 - len2) / len2);
	}

	int countUniqueAlphabets(const std::string& str) {
		std::set<char> uniqueAlphabets;

		for (char c : str) {
			if (std::isalpha(c)) {
				// ��ҹ��� ���� ���� ���ĺ��� �߰� (�ҹ��ڷ� ��ȯ)
				uniqueAlphabets.insert(std::tolower(c));
			}
		}

		return uniqueAlphabets.size();  // ������ ���ĺ��� ���� ��ȯ
	}

    int countCommonAlphabets(const std::string& str1, const std::string& str2) {
        std::set<char> alphabets1;
        std::set<char> alphabets2;

        // ù ��° ���ڿ����� ���ĺ� ����
        for (char c : str1) {
            if (std::isalpha(c)) {
                alphabets1.insert(std::tolower(c));  // �ҹ��ڷ� ��ȯ�Ͽ� ����
            }
        }

        // �� ��° ���ڿ����� ���ĺ� ����
        for (char c : str2) {
            if (std::isalpha(c)) {
                alphabets2.insert(std::tolower(c));  // �ҹ��ڷ� ��ȯ�Ͽ� ����
            }
        }

        // �� set���� ����� ���ĺ� ã��
        int commonCount = 0;
        for (char c : alphabets1) {
            if (alphabets2.find(c) != alphabets2.end()) {
                commonCount++;  // ����� ���ĺ��� ������ ī��Ʈ
            }
        }

        return commonCount;
    }

};