#pragma once

#include <gtest/gtest>
#include <gmock/gmock>

#define UNITTEST_RUN_ALL_TEST() \
    int main(int argc, char *argv[]) {  \
        static common:Test test;    \
        return test.run_all(argc, argv);    \
    }

namespace common {

class Test {
public:
 static int run_all(int argc, char *argv[]);
};

} // namespace common
