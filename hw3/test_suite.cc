/*
 * Copyright ©2018 Justin Hsia.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Spring Quarter 2018 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

#include <iostream>
#include "gtest/gtest.h"

using std::cout;
using std::endl;

unsigned int hw3_maxpoints = 180;
unsigned int hw3_points = 0;

void HW3Addpoints(unsigned int points) {
  hw3_points += points;
  cout << " (" << hw3_points << "/" << hw3_maxpoints << ")" << endl;
}

class HW3Environment : public ::testing::Environment {
 public:

  virtual void SetUp() {
    // Code here is run once for the entire test suite.
    cout << "HW3: there are " << hw3_maxpoints << " available." << endl;
  }
  virtual void TearDown() {
    // Code here is run once for the entire test suite.
    cout << endl;
    cout << "You earned " << hw3_points << " out of ";
    cout << hw3_maxpoints << " available (";
    cout << (100.0*hw3_points) / hw3_maxpoints << "%)" << endl;
    cout << endl;
  }
};

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::AddGlobalTestEnvironment(new HW3Environment);
  return RUN_ALL_TESTS();
}