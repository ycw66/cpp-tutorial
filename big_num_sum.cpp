/*
* 任务描述：将两个正整数相加，数字可能很大，无法用整数数据类型表示
* 日期：2024.7.24
* 前置知识：
*   1. c++字符串数据类型string的用法
*   2. ASCII码，掌握计算机中字符集的字符整数映射，每个字符(比如'1', '2', 'a', 'b')都映射成一个整数，了解如何将'1'字符转换成实际整数的方法。
*/

#include <iostream>
#include <string>
#include <algorithm>

/* 定义函数bigIntAdd，用来进行大数字加法(这里数字位数比较大，用字符串数据类型表示)
*  参数：
*   num1: 参与相加的第一个正整数
*   num2: 参与相加的第二个正整数
*  返回值:
*   返回一个字符串格式的整数
*/
std::string bigIntAdd(std::string num1, std::string num2) {
    std::string res;
    
    // 首先将两个字符进行翻转，便于从低位开始进行数字相加
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    // size()函数用来返回数字长度
    if (num1.size() > num2.size()) {
        // 保证num1的数位长度小于等于num2，否则将num1和num2互换
        std::string tmp = num1;
        std::string num1 = num2;
        std::string num2 = tmp;
    }

    // 定义一个变量r用来保存进位
    int r = 0;

    int i = 0;

    while (i < num1.size()) {
        // 分别获取num1和num2两个数字当前位的数值
        int a = num1[i] - '0';
        int b = num2[i] - '0';
        
        int c = a + b + r;
        if (c > 10) {
            c = c - 10;
            r = 1;
        }
        res.push_back(c + '0');
        i++;
    }

    while (i < num2.size()) {
        int b = num2[i] - '0';
        int c = b + r;
        if (c > 10) {
            c = c - 10;
            r = 1;
        }
        res.push_back(c + '0');
    }

    if (r > 0) {
        res.push_back(r + '0');
    }

    // 当前计算出来的res，从低位到高位的表示的，我们需要返回一个从高位到低位的表示，需要进行一次反转
    std::reverse(res.begin(), res.end());

    return res;
}



// main函数为程序的入口，程序从main函数开始执行
int main() {
    
    // 进行一系列测试
    std::cout << bigIntAdd("123", "123") << std::endl;
    std::cout << bigIntAdd("11111111111111111111", "22222222222222222222") << std::endl;
    std::cout << bigIntAdd("22", "99") << std::endl;

    return 0;
}