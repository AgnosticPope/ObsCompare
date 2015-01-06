#include <QCoreApplication>

#include "obsstabilitytest.h"
#include "boostobjects.h"

QTEST_MAIN(ObserverUnitTest);

#if 0
#include <gtest/gtest.h>

TEST(MyTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ObsStabilityTest* test=new ObsStabilityTestOne();
    ObsStabilityTest* test2=new ObsStabilityTestDeleteRec();

    //test->suite()->run(NULL);
    test->doTest();
    test2->doTest();
    std::cout <<"Done tests!"<<std::endl;
    return a.exec();
}
#endif
