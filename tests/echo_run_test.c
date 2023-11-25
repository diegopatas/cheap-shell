#include "tester.h"
#include <math.h>
#include <stdlib.h>

static  t_cmd *cmd;

static char	*expect(char *expected) {
	cmd->vec[0] = "echo";
	cmd->vec[1] = expected;
	return fn_wrapper(cmd, &fn_execv);
}

static char	*given(char *given) {
	cmd->arg = given;
	return fn_wrapper(cmd, &echo_run);
}

TEST_GROUP(echo_run_test);

TEST_SETUP(echo_run_test) {
	cmd = NULL;
	cmd = ds_create();
	cmd->vec = vec_create(3);
}

TEST_TEAR_DOWN(echo_run_test) {
}

static void	match(char *expected, char *given, int line) {
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, given, ft_itoa(line));
	return;
}

TEST(echo_run_test, check_equal) {
	match(expect(""), given(""), __LINE__);
	match(expect("\t "), given("\t "), __LINE__);
	match(expect("4"), given("4"), __LINE__);
	match(expect("42"), given("42"), __LINE__);
}

TEST(echo_run_test, check_null) {
	match(expect(""), given(""), __LINE__);
}

TEST_GROUP_RUNNER(echo_run_test) {
	RUN_TEST_CASE(echo_run_test, check_equal);
	RUN_TEST_CASE(echo_run_test, check_null);
}
