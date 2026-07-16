#include <stdio.h>

int Length(char str[])
{
    int i = 0;

    while(str[i] != '\0')
        i++;

    return i;
}

void Display(char str[])
{
    printf("%s\n", str);
}

void Copy(char source[], char destination[])
{
    int i = 0;

    while(source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}

void Concatenate(char str1[], char str2[])
{
    int i = 0, j = 0;

    while(str1[i] != '\0')
        i++;

    while(str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';
}

int Compare(char str1[], char str2[])
{
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            return 0;

        i++;
    }

    return str1[i] == str2[i];
}

void Reverse(char str[])
{
    int i = 0, j, temp;

    while(str[i] != '\0')
        i++;

    j = i - 1;

    for(i = 0; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void ToUpper(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;

        i++;
    }
}

void ToLower(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;

        i++;
    }
}

int IsPalindrome(char str[])
{
    int i = 0, j;

    while(str[i] != '\0')
        i++;

    j = i - 1;

    for(i = 0; i < j; i++, j--)
    {
        if(str[i] != str[j])
            return 0;
    }

    return 1;
}

int main()
{
    char str1[100] = "Hello";
    char str2[100] = " World";
    char copy[100];

    printf("String 1: ");
    Display(str1);

    printf("Length = %d\n\n", Length(str1));

    Copy(str1, copy);
    printf("Copied String: ");
    Display(copy);

    Concatenate(str1, str2);
    printf("After Concatenation: ");
    Display(str1);

    printf("\nComparison: ");

    if(Compare(str1, copy))
        printf("Equal\n");
    else
        printf("Not Equal\n");

    Reverse(copy);
    printf("\nReverse: ");
    Display(copy);

    ToUpper(copy);
    printf("Uppercase: ");
    Display(copy);

    ToLower(copy);
    printf("Lowercase: ");
    Display(copy);

    char p[] = "madam";

    if(IsPalindrome(p))
        printf("\n\"%s\" is Palindrome\n", p);
    else
        printf("\n\"%s\" is Not Palindrome\n", p);

    return 0;
}