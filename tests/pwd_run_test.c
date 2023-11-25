#include "tester.h"

static  t_cmd *cmd;

static char	*expect(void) {
	cmd->vec[0] = "pwd";
	return fn_wrapper(cmd, &fn_execv);
}

static char	*given(void) {
	return fn_wrapper(cmd, &pwd_run);
}

static void	match(char *expected, char *given, int line) {
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, given, ft_itoa(line));
	return;
}

TEST_GROUP(pwd_run_test);

TEST_SETUP(pwd_run_test) {
	cmd = NULL;
	cmd = ds_create();
	cmd->vec = vec_create(2);
}

TEST_TEAR_DOWN(pwd_run_test) {
}


TEST(pwd_run_test, check_equal) {
	match(expect(), given(), __LINE__);
}

TEST_GROUP_RUNNER(pwd_run_test) {
	RUN_TEST_CASE(pwd_run_test, check_equal);
}
