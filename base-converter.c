/*
 *    Base Converter
 *    
 *    Author: Afaan Bilal
 *    URL: https://afaan.ml
 *    
 *    Convert numbers between bases.
 *    
 *    (c) 2016 Afaan Bilal
 *    Released under the MIT License
 *     
 */

#include <stdio.h>
#include <math.h>

long base_convert(long number, short fromBase, short toBase)
{
    long result = 0;
    int i = 0;
    
    while (number > 0)
    {
        result += (number % toBase) * pow(fromBase, i++);
        number /= toBase;
    }
    
    return result;
}

long convert(long number, short fromBase, short toBase)
{
    return base_convert(base_convert(number, fromBase, 10), 10, toBase);
}

int main()
{    
    long i = 0;
    int number, fB, tB, converted;
    printf("\n\tBASE CONVERTER\n\n");
    
    printf("BASE:    2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   10\n");
    printf("---------------------------------------------------------------------------\n");
    for (i = 0; i < 11; i++)
    {
        printf("     |%4ld   |%4ld   |%4ld   |%4ld   |%4ld   |%4ld   |%4ld   |%4ld   |%4ld\n", 
                convert(i, 10, 2),
                convert(i, 10, 3),
                convert(i, 10, 4),
                convert(i, 10, 5),
                convert(i, 10, 6),
                convert(i, 10, 7),
                convert(i, 10, 8),
                convert(i, 10, 9),
                i
                );
    }
        
    printf("\nEnter a number: ");
    scanf("%d", &number);
    
    printf("From Base: ");
    scanf("%d", &fB);
    
    printf("To Base: ");
    scanf("%d", &tB);
    
    converted = convert(number, fB, tB);
    
    printf("\nConverted: %d", converted);
    
    getch();
}
