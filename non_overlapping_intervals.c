#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
  int *intervalA = *(int **)a;
  int *intervalB = *(int **)b;
  return intervalA[1] - intervalB[1];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
  if (intervalsSize == 0)
    return 0;

  qsort(intervals, intervalsSize, sizeof(int *), comp);

  int ans = -1;
  int *prev = intervals[0];

  for (int i = 0; i < intervalsSize; i++)
  {
    if (prev[1] > intervals[i][0])
    {
      ans++;
    }
    else
    {
      prev = intervals[i];
    }
  }

  return ans;
}