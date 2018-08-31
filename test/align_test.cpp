#include "align.h"
#include "common_unittest.h"

namespace common {

class AlignTest : public testing::Test {
  public:
   virtual void SetUp()
   {}

   virtual void TearDown()
   {}
};

TEST_F(AlignTest, alignUpTest) {
    ASSERT_EQ(align_up(513, 512), 1024);
    ASSERT_EQ(align_up(511, 512), 512);
    ASSERT_EQ(align_up(0, 512), 0);
    ASSERT_EQ(align_up(512, 512), 512);
}

TEST_F(AlignTest, alignDownTest) {
    ASSERT_EQ(align_down(513, 512), 512);
    ASSERT_EQ(align_down(511, 512), 0);
    ASSERT_EQ(align_down(0, 512), 0);
    ASSERT_EQ(align_down(512, 512), 512);
}

TEST_F(AlignTest, alignTest) {
    ASSERT_EQ(align(512, 512), 0);
    ASSERT_EQ(align(523, 512), 11);
    ASSERT_EQ(align(511, 512), 511);
    ASSERT_EQ(align(0, 512), 0);
}

} // namespace common
