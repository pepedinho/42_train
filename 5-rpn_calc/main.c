#include "rpn_calc.h"
#include <stdio.h>

int main(void)
{
    char test[] = "1 2 * 3 * 4 +";

    int result = rpn_cal(test);

    printf("%d", result);

    return 0;
}
