#include <stdio.h>

int cond()
{
    return 0; // Your Code Here.
}

int true_func()
{
    printf(", world");
    return 0; // Your Code Here.
}

int false_func()
{
    printf("hello");
    return 0; // Your Code Here.
}

int if_function(int condition, int true_result, int false_result)
{
    if (condition)
        return true_result;
    else
        return false_result;
}

int with_if_function()
{
    return if_function(cond(), true_func(), false_func());
}

int with_if_statement()
{
    if (cond())
        return true_func();
    else
        return false_func();
}

int main()
{
    printf("\n%d\n", with_if_statement());
    printf("\n%d\n", with_if_function());
    return 0;
}
