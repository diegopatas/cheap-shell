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

TEST_GROUP(export_run_test);

TEST_SETUP(export_run_test) {
}

TEST_TEAR_DOWN(export_run_test) {
}

TEST(export_run_test, check_equal) {
	match("", "", __LINE__);
}

TEST_GROUP_RUNNER(export_run_test) {
	RUN_TEST_CASE(export_run_test, check_equal);
}

