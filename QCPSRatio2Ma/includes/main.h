/**
 * @file includes\main.h.
 * @brief 对main.c中使用的函数进行声明.
 * @date 2018/9/26.
 * @author 翟灿    邮箱：840202741@@qq.com.
 * @version 1.0
 * @copyright Copyright © 2018 翟灿. All rights reserved.
 */
#ifndef MAIN_H
#define MAIN_H
#include "TypeAndConsts.h"
extern Float64 GetMa(Float64 ratio, Float64 precision);
extern Float64 GetRatio(Float64 Ma);

Int32 main(void);
#endif
