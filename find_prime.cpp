/*
* 任务描述：输出1到1000中所有的素数
* 日期：2024.7.24
*/

#include <iostream>
#include <cmath>

/* 定义一个函数isPrime，用来判断一个整数是否是素数
*      注意：将一些功能独立的代码逻辑拆分成一个函数，有利于代码结构的模块化，避免了单个函数代码过长，增强了代码可读性
*/
bool isPrime(int num) {
    // 循环遍历 从2开始到根号下num
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            // 如果i整除num，说明num不是素数，直接返回false
            return false;
        }
    }
    // 如果[2, 根号下num]都无法整除i，说明num满足了素数的性质，返回true
    return true;
}

// main函数为程序的入口，程序从main函数开始执行
int main() {
    
    // 从2遍历到1000，输出1000以下所有的素数
    for (int i = 2; i <= 1000; i++) {
        if (isPrime(i)) {
            // std::cout 为标准输出函数，作用是将变量i的内容输出到终端；std::endl为换行符，此处用来在终端中进行换行。
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}
