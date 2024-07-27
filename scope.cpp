/*
* 变量的作用域
*/

#include <iostream>

int a = 1;
int func() {
    int a = 2;

    std::cout << "1:" << a << std::endl;
    
    return 0;
}

/*
    
   scope of func: {a}
   
   scope of main: {a}
    scope2: 
*/
    
int main(){
    int a = 3;
    
    // 
    {// scope2
        // int a = 4;
        std::cout << "3" << '+'  << a << std::endl;
    }

     func();

    std::cout << "2:" << a << std::endl;

    return 0;
} 