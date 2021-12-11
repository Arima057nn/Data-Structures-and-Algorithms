#include <stdio.h>

int main()
{
  FILE *ptr1, *ptr2;
  ptr1 = fopen("ex4a.txt", "w");
  ptr2 = fopen("ex4b.txt", "w");
  fputs("hoc C khong he kho", ptr1);
  char c;
  if (ptr1 == NULL || ptr2 == NULL)
  {
    printf("cannot find file txt");
  }
  else
  {
    while ((c = fgetc(ptr1)) != EOF)
    {
      fputc(c, ptr2);
    }
    fclose(ptr1);
    fclose(ptr2);
  }

  return 0;
}
