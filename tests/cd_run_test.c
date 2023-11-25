#include "tester.h"

// static ;
// static char *expect() {
// }
// static char *given() {
// }
static void match(char *expected, char *given, int line) {
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, given, ft_itoa(line));
	return;
}

TEST_GROUP(cd_run_test);

TEST_SETUP(cd_run_test) {
}

TEST_TEAR_DOWN(cd_run_test) {
}

TEST(cd_run_test, check_equal) {
	match("", "" , __LINE__);
}

TEST_GROUP_RUNNER(cd_run_test) {
	RUN_TEST_CASE(cd_run_test, check_equal);
}

