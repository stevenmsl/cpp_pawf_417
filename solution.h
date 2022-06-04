
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol417
{

  class Solution
  {
  private:
    void _visit(int x, int y, int prevH, vector<vector<int>> &visited, vector<vector<int>> &matrix);

  public:
    vector<pair<int, int>> pa(vector<vector<int>> &matrix);
  };
}
#endif