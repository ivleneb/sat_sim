#include <gtest/gtest.h>
extern "C"
{
#include "../lib/task/task.h"
}

TEST(test_sat, getName)
{
	Task t("task1");
	EXPECT_STREQ("task1", "task1");
}
