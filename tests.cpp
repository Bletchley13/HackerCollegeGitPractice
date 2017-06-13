#include "NextDate.h"
#include <gtest/gtest.h>

void testNextDate(int preYear, int preMonth, int preDay, int nextYear, int nextMonth, int nextDay){
	Date* a= NewDateInstance( preYear, preMonth, preDay);
	Date* b= NextDate(a);
	//bool ret = checkDate(b, nextYear, nextMonth, nextDay);
	//free(a);
	//free(b);
	EXPECT_EQ(nextYear, b->year);
	EXPECT_EQ(nextMonth, b->month);
	EXPECT_EQ(nextDay, b->day);
	//free(a);
        //free(b);
}

void testInvalid(int preYear, int preMonth, int preDay){
	Date* a= NewDateInstance( preYear, preMonth, preDay);
	Date* b= NextDate(a);
	free(a);
	free(b);
	EXPECT_TRUE(b==NULL);
}

TEST(BoundaryTest, Year) { 
	testNextDate( 1812, 1, 1 , 1812, 1, 2);
	testNextDate( 1813, 7, 9 , 1813, 7, 10);
	testNextDate( 2012, 6, 10 , 2012, 6, 11);	
	testNextDate( 2011, 10, 20 , 2011, 10, 21);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
