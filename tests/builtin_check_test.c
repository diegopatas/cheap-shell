#include "Unity/extras/fixture/src/unity_fixture.h"
#include "Unity/src/unity.h"
#include "tester.h"

TEST_GROUP(builtin_check_test);

TEST_SETUP(builtin_check_test) {
}

TEST_TEAR_DOWN(builtin_check_test) {
}

void	valid(const char *given) {
	TEST_ASSERT_TRUE(builtin_check(given));
	return;
}

TEST(builtin_check_test, check_true) {
	valid("echo");
	valid("cd");
	valid("pwd");
	valid("export");
	valid("exit");
	valid("unset");
	valid("env");
}

TEST_GROUP_RUNNER(builtin_check_test) {
	RUN_TEST_CASE(builtin_check_test, check_true);
}
