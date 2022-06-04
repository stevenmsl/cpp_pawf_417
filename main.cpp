#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol417;

/*
Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

tuple<vector<vector<int>>, vector<pair<int, int>>>
testFixture1()
{
  auto input = vector<vector<int>>{
      {1, 2, 2, 3, 5},
      {3, 2, 3, 4, 4},
      {2, 4, 5, 3, 1},
      {6, 7, 1, 4, 5},
      {5, 1, 1, 2, 4}};
  auto output = vector<pair<int, int>>{
      {0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};

  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see : " << Util::toString(get<1>(f)) << endl;
  cout << Util::toString(sol.pa(get<0>(f))) << endl;
}

main()
{
  test1();

  return 0;
}