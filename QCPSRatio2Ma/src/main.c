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
    Float64 Ma = GetMa(1.23986, 0.00001);
    printf("%f\n", Ma);
    Float64 ratio = GetRatio(Ma);
    printf("%f\n", ratio);

    system("pause");
    return 0;
}
