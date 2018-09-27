/**
 * @file src\main.c.
 * @brief 程序运行起始文件.
 * @date 2018/9/26.
 * @author 翟灿    邮箱：840202741@qq.com.
 * @version 1.0
 * @copyright Copyright © 2018 翟灿. All rights reserved.
 */
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * @brief 程序运行起始函数.
 */
Int32 main(void)
{
    Float64 Ma, ratio, precision;
    printf("输入动静压比:");
    scanf("%lf", &ratio);
    printf("输入精度(推荐0.00001):");
    scanf("%lf", &precision);

    Ma = GetMa(ratio, precision);
    ratio = GetRatio(Ma);
    printf("马赫数近似值为:%lf\n", Ma);
    printf("由近似值所得动静压比为:%lf\n", ratio);

    system("pause");
    return 0;
}
