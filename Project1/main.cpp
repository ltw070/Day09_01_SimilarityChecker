#include"gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(SimilarityChecker, length) {
	SimilarityChecker app;
	EXPECT_EQ(60, app.getScore("AAA", "AAA"));
	EXPECT_EQ(60, app.getScore("ASD", "DSA"));
	EXPECT_EQ( (int)(1-(int)((5-3)/3)) , app.getScore("AAABB", "BAA"));
	EXPECT_EQ((int)(1 - (int)((3 - 2) / 2)), app.getScore("AA", "AAE"));
	EXPECT_EQ(60, app.getScore("AAA", "AAA"));
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}