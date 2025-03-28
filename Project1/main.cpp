#include"gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(SimilarityChecker, length) {
	SimilarityChecker app;
	EXPECT_EQ(100, app.getScore("AAA", "AAA"));
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}