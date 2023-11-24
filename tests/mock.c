#include "tester.h"

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
}
