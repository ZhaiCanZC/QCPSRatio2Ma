/**
 * @file src\MaCalculate.c.
 * @brief 根据动静压比计算马赫数.
 * @date 2018/9/26.
 * @author 翟灿    邮箱：840202741@@qq.com.
 * @version 1.0
 * @copyright Copyright © 2018 翟灿. All rights reserved.
 */
#include <stdio.h>
#include <math.h>
#include "MaCalculate.h"

/**
 * @brief 二分法求解马赫数近似值.
 * @param ratio     动静压比，单位：无量纲.
 * @param precision 精确度，推荐值:0.00001.
 * @return 对应的马赫数，单位：无量纲.
 */
Float64 GetMa(Float64 ratio, Float64 precision)
{
    Float64 Ma;/*马赫数，作为返回值*/
    
    Interval interval = GetInterval(ratio);/*记录根值所在的区间*/

    Float64 start = interval.start;/*区间左端点*/
    Float64 end = interval.end;/*区间右端点*/
    Float64 half;/*区间中点*/
    Float64 StartValue;/*左端点对应的函数值*/
    Float64 EndValue;/*右端点对应的函数值*/
    Float64 HalfValue;/*中点对应的函数值*/

    /*二分法求解过程*/
    while (fabs(end - start) > precision)
    {
        half = (start + end) / 2;
        StartValue = GetFnValue(start, ratio);
        EndValue = GetFnValue(end, ratio);
        HalfValue = GetFnValue(half, ratio);

        /*temp用于判断左端点、右端点和中点所对应的函数值中是否存在为0的点
        若temp等于0，则说明没有等于0的点
        若temp不等于零，则temp的值为等于0时所对应的点，即所求的解*/
        Float64 temp = start * (StartValue == 0.0) + end * (EndValue == 0.0) + half * (HalfValue == 0.0);
        if (temp != 0.0)
        {
            Ma = temp;
            return Ma;
        }
        else
        {
            /*判断解是否在左端点与中点之间。如果在，则以左端点与中点作为新的区间；
            否则以中点与右端点作为新区间*/
            if (!IfSameSymbol(StartValue, HalfValue))
            {
                end = half;
            }
            else
            {
                start = half;
            }
        }
    }
    Ma = (start + end) / 2;/*取最终区间的中点作为近似解*/
    return Ma;
}

/**
 * @brief 寻找根值所在区间.
 * @param ratio 动静压比，单位：无量纲.
 * @return 根值所在区间.
 */
static Interval GetInterval(Float64 ratio)
{
    Interval interval;/*记录区间的结构体，作为返回值*/

    Float64 start = 0.0;/*区间左端点*/
    Float64 end = 0.0;/*区间右端点*/
    Float64 step = 0.01;/*寻找根植区间的的步长*/
    Float64 StartValue = -ratio;/*左端点对应的函数值*/
    Float64 EndValue = -ratio;/*右端点对应的函数值*/

    /*判断左右端点函数值是否异号。若异号，则该区间为所求区间；
    否则继续判断下一个步长的区间，直到异号为止*/
    do
    {
        start = end;
        end += step;
        StartValue = EndValue;
        EndValue = GetFnValue(end, ratio);
    } while (IfSameSymbol(StartValue, EndValue));

    interval.start = start;
    interval.end = end;
    return interval;
}

/**
 * @brief 判断两个数同号还是异号.
 * @param NumA 数字A.
 * @param NumB 数字B.
 * @retval 1 两个数同号.
 * @retval 0 两个数异号(此处0和0看作异号).
 */
static Int32 IfSameSymbol(Float64 NumA, Float64 NumB)
{
    if (NumA == 0.0 || NumB == 0.0)
    {
        return 0;
    }
    else
    {
        Float64 temp = (NumA / fabs(NumA)) * (NumB / fabs(NumB));
        return temp > 0.0 ? 1 : 0;
    }
}
