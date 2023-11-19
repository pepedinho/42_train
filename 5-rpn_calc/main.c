#include "rpn_calc.h"
#include <stdio.h>

int main(void)
{
    char test[] = "2 7 * 3 * 2 /";

    int result = rpn_cal(test);

    printf("%d", result);

    return 0;
}
