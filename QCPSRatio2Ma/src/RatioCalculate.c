/**
 * @file src\RatioCalculate.c.
 * @brief 计算动静压比值.
 * @date 2018/9/26.
 * @author 翟灿    邮箱：840202741@qq.com.
 * @version 1.0
 * @copyright Copyright © 2018 翟灿. All rights reserved.
 */
#include <stdio.h>
#include <math.h>
#include "RatioCalculate.h"

/**
 * @brief 根据马赫数计算动静压比.
 * @param Ma 马赫数，单位：无量纲.
 * @return 马赫数所对应的动静压比值，单位：无量纲.
 */
Float64 GetRatio(Float64 Ma)
{
    Float64 ratio;
    if (Ma <= 1.0)
    {
        ratio = pow(1 + (Kn - 1) / 2 * Ma * Ma, Kn / (Kn - 1)) - 1;
    }
    else
    {
        ratio = (Kn + 1) / 2 * Ma * Ma * pow((Kn + 1) * (Kn + 1) * Ma * Ma / (4 * Kn * Ma * Ma - 2 * (Kn - 1)), 1 / (Kn - 1)) - 1;
    }
    return ratio;
}

/**
 * @brief 二分法求解时所用函数，即 f(n) = f(Ma) - ratio.
 * @param Ma    马赫数，单位：无量纲.
 * @param ratio 动静压比目标值，单位：无量纲.
 * @return 动静压比计算值与目标值之差.
 */
Float64 GetFnValue(Float64 Ma, Float64 ratio)
{
    Float64 value = GetRatio(Ma) - ratio;
    return value;
}