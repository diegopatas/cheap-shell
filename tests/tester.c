#include "tester.h"

void	run_all_tests(void)
{
	RUN_TEST_GROUP(builtin_check); //cut-paste this at tests.c
	RUN_TEST_GROUP(echo_run_t); //cut-paste this at tests.c
}

int	main(int argc, const char *argv[])
{
	return UnityMain(argc, argv, run_all_tests);
}
