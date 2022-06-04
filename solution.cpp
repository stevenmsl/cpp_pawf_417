#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol417;
using namespace std;

/*takeaways
  - Start from the borders, which are next to the Pacific or Atlantic
    waters, and record which nodes can be reached on two different set
  - Intersect the set. The intersection represents the nodes that
    can be reached by both Pacific and Atlantic waters
  - one key point to remember is that instead of going from a node to
    see if we can reach the water from that node, we do it the opposite
    and deduce the path from the water back to the node. So the
    criteria are different: you can think of this as water is flowing
    form the lower to a higher place
  - why we are doing this? So we can reduce the time complexity to O(mn)

*/

vector<pair<int, int>> Solution::pa(vector<vector<int>> &matrix)
{
  int n = matrix.size(), m = matrix[0].size();
  auto result = vector<pair<int, int>>();
  auto pa = vector<vector<int>>(n, vector<int>(m));
  auto at = vector<vector<int>>(n, vector<int>(m));

  for (auto i = 0; i < m; i++)
  {
    /* top row; adjacent to the Pacific */
    _visit(i, 0, 0, pa, matrix);
    /* bottom row; adjacent to the Atlantic */
    _visit(i, n - 1, 0, at, matrix);
  }

  for (auto i = 0; i < n; i++)
  {
    /* first col; adjacent to the Pacific */
    _visit(0, i, 0, pa, matrix);
    /* last col; adjacent to the Atlantic */
    _visit(m - 1, i, 0, at, matrix);
  }

  /* intersection */
  for (auto i = 0; i < n; i++)
    for (auto j = 0; j < m; j++)
      if (pa[i][j] && at[i][j])
        result.push_back({i, j});

  return result;
}

void Solution::_visit(
    int x, int y, int prevH, vector<vector<int>> &visited, vector<vector<int>> &matrix)
{
  /* x is the col, and y is the row */
  /* check if everything is within bound */
  int n = matrix.size(), m = matrix[0].size();
  if (x < 0 || y < 0 || x >= m || y >= n)
    return;
  auto h = matrix[y][x];

  /* we want to flow from lower to higher place */
  if (visited[y][x] || h < prevH)
    return;

  visited[y][x] = 1;

  /* visit neighbors in four directions */
  _visit(x, y - 1, h, visited, matrix);
  _visit(x, y + 1, h, visited, matrix);
  _visit(x - 1, y, h, visited, matrix);
  _visit(x + 1, y, h, visited, matrix);
}
