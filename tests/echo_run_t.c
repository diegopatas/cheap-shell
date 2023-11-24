#include "Unity/src/unity.h"
#include "tester.h"

static  t_cmd *cmd;
TEST_GROUP(echo_run_t);

TEST_SETUP(echo_run_t) {
	cmd = NULL;
	cmd = ds_create(cmd);
}

TEST_TEAR_DOWN(echo_run_t) {
}

static void	match(char *expected, char *given, int line) {

	cmd->arg = given;
	// expected = fn_wrapper(cmd, &fn_execv);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(fn_wrapper(cmd, &fn_execv), fn_wrapper(cmd, &echo_run), ft_itoa(line));
	return;
}

TEST(echo_run_t, ctxt) {
	match("", "test", __LINE__);
}

TEST_GROUP_RUNNER(echo_run_t) {
	RUN_TEST_CASE(echo_run_t, ctxt);
}

/* EXAMPLE
#include "tests.h"

int	*esp;
int	output;
TEST_GROUP(mock);
TEST_SETUP(mock) {
	esp = NULL;
	output = 0;
}
TEST_TEAR_DOWN(mock) {}
int	expect(int value){
	*esp = value;
}
int	given(int given){
	output = given;
	TEST_ASSERT_EQUAL_INT(esp, output);
}
TEST(mock, check_int) {
	expect(42);
	given(42);
}
TEST(mock, check_fail) {
	TEST_FAIL();
}
TEST(mock, check_fail_msg) {
	TEST_FAIL_MESSAGE("Fails here!");
}
TEST_GROUP_RUNNER(mock) {
	RUN_TEST_CASE(mock, check_fail);
	RUN_TEST_CASE(mock, check_fail_msg);
} */

