#include <stdio.h>
#include <stdlib.h>

#define SEED 35791246
#define MAX_SIZE 100

/* Euclidean Algorithm for Greatest Common Divisor (GCD) */
int
gcd (int a, int b)
{
  int m = a, n = b, r;
  while (n > 0)
    {
      int r = m % n;
      m = n;
      n = r;
    }
  return m;
}

/* This function calculates square root of n */
double
do_sqrt (double n)
{
  double start, end, mid;
  start = 0, end = n;

  while ((end - start) >= 0.000001)
    {

      mid = (start + end) / 2;

      if (mid * mid < n)
	start = mid;
      if (mid * mid >= n)
	end = mid;

    }

  return mid;
}

/* Estimation of Pi value */
double
get_probability (int sum, int total)
{

  double Pi, p;
  p = 6 * total / sum;
  /* Calculate the square root of value */
  Pi = do_sqrt (p);
  return Pi;
}


int
main ()
{
  /* initialize random numbers */
  srand (SEED);
  int i, niter, a[MAX_SIZE];

  printf ("Enter the number of iterations( <= %d) used to estimate pi: ",
	  MAX_SIZE);
  scanf ("%d", &niter);

  if (niter > MAX_SIZE)
    {
      printf ("the number of iterations are greater than %d, Exiting\n",
	      MAX_SIZE);
      exit - 1;
    }

  for (i = 0; i < niter; i++)
    a[i] = rand () % niter + 1;
  printf ("The generated random numbers with seed (%d) are: \n", SEED);

  int m, j;
  int sum = 0;

  for (j = 0; j < niter; j += 2)
    {
      m = gcd (a[j], a[j + 1]);
      if (m == 1)
	sum = sum + 1;
      printf ("sum:%d, GCD(%d,%d) = %d \n", sum, a[j], a[j + 1], m);
    }

  double Pi = get_probability (sum, niter / 2);
  printf ("\nThe estimate value of Pi is:%f\n ", Pi);

}
