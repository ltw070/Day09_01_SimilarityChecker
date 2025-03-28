#include"gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(SimilarityChecker, length) {
	SimilarityChecker app;
	EXPECT_EQ(60, app.getScore("AAA", "AAA"));
	EXPECT_EQ(60, app.getScore("ASD", "DSA"));
	EXPECT_EQ((int)(60 - (60 * (5 - 3) / 3)), app.getScore("AAABB", "BAA"));
	EXPECT_EQ(30, app.getScore("AA", "AAE"));
	EXPECT_EQ(60, app.getScore("AAA", "AAA"));
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