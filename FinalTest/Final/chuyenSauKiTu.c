#include <stdio.h>
#include <string.h>

void to_lower(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
}

char *to_lower(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
    return s;
}
void to_upper(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
}

void to_title(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if (str[i - 1] == ' ' || i == 0)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }
}
void TachMotChuoi(char str[])
{
    // Returns first token
    char *token = strtok(str, "-");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }
}
int main()
{
    char s[100];
    int i;

    printf("\nEnter a string : ");
    gets(s);
    to_lower(s);
    printf("\nString in Lowercase = %s", s);
    to_upper(s);
    printf("\nString in Uppercase = %s", s);
    to_title(s);
    printf("\nString in Titlecase = %s", s);
    char str[] = "Geeks-for-Geeks";
    TachMotChuoi(str);
}
/*
Enter a string : nGUYEN van HIEU
 
String in Lowercase = nguyen van hieu
String in Uppercase = NGUYEN VAN HIEU
String in Titlecase = Nguyen Van Hieu
 */