#include"gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(SimilarityChecker, length) {
	SimilarityChecker app;
	EXPECT_EQ(60, app.getLengthScore("AAA", "AAA"));
	EXPECT_EQ(60, app.getLengthScore("ASD", "DSA"));
	EXPECT_EQ(0, app.getLengthScore("A", "BB"));
	EXPECT_EQ(60 * (int)(1 - (int)((5 - 3) / 3)), app.getLengthScore("AAABB", "BAA"));
	EXPECT_EQ(60 * (int)(1 - (int)((3 - 2) / 2)), app.getLengthScore("AA", "AAE"));
}

TEST(SimilarityChecker, alpha) {
	SimilarityChecker app;
	EXPECT_EQ(40, app.getAlphaScore("AAA", "AAA"));
	EXPECT_EQ(40, app.getAlphaScore("ASD", "DSA"));
	EXPECT_EQ(0, app.getAlphaScore("A", "BB"));
	EXPECT_EQ(40, app.getAlphaScore("AAABB", "BAA"));
	EXPECT_EQ(20, app.getAlphaScore("AA", "AAE"));
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}