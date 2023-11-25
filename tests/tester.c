#include "tester.h"

void	run_all_tests(void)
{
	RUN_TEST_GROUP(builtin_check_test); //cut-paste this at tests.c
	RUN_TEST_GROUP(echo_run_test); //cut-paste this at tests.c
	RUN_TEST_GROUP(pwd_run_test); //cut-paste this at tests.c
	RUN_TEST_GROUP(cd_run_test); //cut-paste this at tests.c
	RUN_TEST_GROUP(unset_run_test); //cut-paste this at tests.c
	RUN_TEST_GROUP(env_run_test); //cut-paste this at tests.c
	RUN_TEST_GROUP(exit_run_test); //cut-paste this at tests.c
	RUN_TEST_GROUP(export_run_test); //cut-paste this at tests.c
}

int	main(int argc, const char *argv[])
{
	return UnityMain(argc, argv, run_all_tests);
}
