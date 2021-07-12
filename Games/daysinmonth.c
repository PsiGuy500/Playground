#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int func(int m)
{
    if (m == 1 || m == 3 || m == 5 ||m == 7 || m == 8 || m == 10 || m == 12)
    {
        printf("31 days");    
    }
    
    else if (m == 2)
    {
        printf("28 days");
    } 
    
    else
    {
        printf("30 days");   
    }
}

int main()
{
    int month;
    printf("enter a month: ");
    scanf("%i", &month);
    func(month);
}

