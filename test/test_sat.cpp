#include <gtest/gtest.h>
extern "C"
{
#include "../lib/task/task.h"
}
#include "../lib/satelite/satelite.h"
#include "../lib/estacionterrena/estacionterrena.h"
#include <string>
#include <vector>

TEST(test_sat, getName)
{
	Task t("task1");
	EXPECT_STREQ("task1", t.getName().c_str());
}

TEST(test_sat, getPort)
{
	std::string str("sat_1");
	Satelite s(str, 6500);	
	ASSERT_EQ(6500, s.getPort());
}

TEST(test_sat, OrderTasks)
{
	Task t1("fotos", 10, {1, 5});
	Task t2("mantenimiento", 1, {1, 2});
	Task t3("pruebas", 1, {5, 6});
	Task t4("fsck", 0.1, {1, 6});
	std::string n1="Satelite_1";
	std::string n2="Satelite_2";
	Satelite sat1(n1, 5000);
	Satelite sat2(n2, 5001);
	EstacionTerrena et("myEst", {&t2, &t4, &t3, &t1}, {&sat1, &sat2});
	et.assignTasks();
	const std::vector<Task*> &ts=et.getTasks();
	ASSERT_STREQ(t1.getName().c_str(), ts[0]->getName().c_str());
	ASSERT_STREQ(t2.getName().c_str(), ts[1]->getName().c_str());
	ASSERT_STREQ(t3.getName().c_str(), ts[2]->getName().c_str());
	ASSERT_STREQ(t4.getName().c_str(), ts[3]->getName().c_str());
}
