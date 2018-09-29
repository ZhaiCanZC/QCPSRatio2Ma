/**
 * @file includes\MaCalculate.h.
 * @brief 对MaCalculate.c中使用的函数及结构体进行声明.
 * @date 2018/9/26.
 * @author 翟灿    邮箱：840202741@@qq.com.
 * @version 1.0
 * @copyright Copyright © 2018 翟灿. All rights reserved.
 */
#ifndef MACALCULATE_H
#define MACALCULATE_H
#include "TypeAndConsts.h"

/** @brief 表示一个区间. */
typedef struct Interval
{
    Float64 start;/**< @brief 区间左端点 */
    Float64 end;/**< @brief 区间右端点 */
}Interval;

Float64 GetMa(Float64 ratio, Float64 precision);

extern Float64 GetFnValue(Float64 Ma, Float64 ratio);

static Interval GetInterval(Float64 ratio);

static Int32 IfSameSymbol(Float64 NumA, Float64 NumB);

#endif