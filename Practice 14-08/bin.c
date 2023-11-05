/* QUESTION 0: Write an algorithm to test whether a binary relation is (i) reflexive (ii) symmetric (iii) transitive*/
#include<stdio.h>
int ref (int n, int a[n][n])
{
  for (int i = 0; i < n; i++)
    if (a[i][i] != 1)
      return 0;
  return 1;
}

int sym (int n, int a[n][n])
{
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i][j] != a[j][i])
	return 0;
  return 1;
}

int tra (int n, int a[n][n])
{
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (a[i][j])
	    {
	      for (int k = 0; k < n; k++)
		{
		  if (a[j][k] && !a[i][k])
		    return 0;
		}
	    }
	}
    }
  return 1;
}

void main ()
{
  int n;
  scanf ("%d", &n);
  int i, j, a[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf ("%d", &a[i][j]);
  if (ref (n, a) == 0)
    printf ("not reflexive\n");
  else
    printf ("reflexive\n");
  if (sym (n, a) == 0)
    printf ("not symmetric\n");
  else
    printf ("symmetric\n");
  if (tra (n, a) == 0)
    printf ("not transitive");
  else
    printf ("transitive");
}
