/*
Authors: 
+ Giovanni Rasera : c++ code
+ Lorenzo Mancini : database and specifications

Links:
+ https://github.com/GiovanniRaseraF
+ https://github.com/MancioLollo
*/

#include "../src/castorodb.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

/*
TODO: add good testing @MancioLollo
*/
TEST(castorodb_list_bros_test, just_read_bros_from_database) {
    castorodb::list_bros();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}