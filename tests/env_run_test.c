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

TEST_GROUP(env_run_test);

TEST_SETUP(env_run_test) {
}

TEST_TEAR_DOWN(env_run_test) {
}

TEST(env_run_test, check_equal) {
	match("", "", __LINE__);
}

TEST_GROUP_RUNNER(env_run_test) {
	RUN_TEST_CASE(env_run_test, check_equal);
}

