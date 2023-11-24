#include "Unity/extras/fixture/src/unity_fixture.h"
#include "Unity/src/unity.h"
#include "tester.h"

TEST_GROUP(builtin_check);

TEST_SETUP(builtin_check) {
}

TEST_TEAR_DOWN(builtin_check) {
}

void	valid(const char *given) {
	TEST_ASSERT_TRUE(builtin_check(given));
	return;
}

TEST(builtin_check, check_true) {
	valid("echo");
	valid("cd");
	valid("pwd");
	valid("export");
	valid("exit");
	valid("unset");
	valid("env");
}

TEST_GROUP_RUNNER(builtin_check) {
	RUN_TEST_CASE(builtin_check, check_true);
}
