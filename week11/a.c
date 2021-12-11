#include <stdio.h>
#include <time.h>
#define NUM 2000000
int Check(int menu)
{
  menu = 0;
  while (menu < 1 || menu > 4)
    {
      printf("\n--------------------------------------\n");
      printf("1. Sequential search\n");
      printf("2. Sequential search using setinel\n");
      printf("3. Binary search\n");
      printf("4.Quit\n");
      printf("Enter your choice: ");
      scanf("%d", &menu);
    }
  return menu;
}

int key_insert()
{
  int key;
  printf("Enter key: ");
  scanf("%d", &key);
  return key;
}

void Sequential(int A[])
{
  int key = key_insert();
  clock_t begin = clock();
  int i = 0;
  while (A[i] != key && i < NUM)
    i++;
  if (i != NUM)
    printf("Element A[%d]\n", i);
  else
    printf("Not exist\n");
  printf("\nTime = %.6lf\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
  return;    
}

void Setinel(int A[])
{
  int key = key_insert();
  clock_t begin = clock();
  int i = 0;
  A[NUM] = key;
  while (A[i] != key)
    i++;
  if (i != NUM)
    printf("Element A[%d]\n", i);
  else
    printf("Not exist\n");
  printf("\nTime = %.6lf\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
  return;
}

void Binary(int A[])
{
  int key = key_insert();
  clock_t begin = clock();
  int low = 0, high = NUM - 1, mid;
  while (low <= high)
    {
      mid = (low + high) / 2;
      if (A[mid] == key)
	{
	  printf("Element: A[%d]\n", mid);
	  printf("\nTime = %.6lf\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
	  return;
	}
      else if (A[mid] > key)
	high = mid - 1;
      else
	low = mid + 1;
    }
  printf("Not exist\n");
  printf("\nTime = %.6lf\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
  return;
}
	  
int main()
{
  int A[NUM + 1], i, menu = Check(menu);
  for (i = 0; i < NUM; ++i)
    A[i] = 2*i+3;
  while (menu != 4)
    {
      switch (menu)
	{
	case 1:
	  {
	    Sequential(A);
	    break;
	  }
	case 2:
	  {
	    Setinel(A);
	    break;
	  }
	case 3:
	  Binary(A);
	}
      menu = Check(menu);
    }
  return 0;
}
