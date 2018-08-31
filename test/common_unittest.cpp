#include "common_unittest.h"

namespace common {

class CommonTestEnvEnvironment : public testing::Environment {
 public:
   virtual void SetUp() {
          /* init test global env */
        }

    virtual void TearDown() {
          /* uninit test global env */
         }
};

int Test::run_all(int argc, char *argv[]) {
    testing::AddGlobalTestEnvironment(new CommonTestEnvEnvironment);
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

} // namespace common
