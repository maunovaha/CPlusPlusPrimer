# Chapter 1

> This chapter introduces most of the basic elements of C++: types, variables, expressions, statements, and functions.

## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

* [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/index.php?diapo=extensions)
* [File Types Creates for Visual C++ Projects](https://msdn.microsoft.com/en-us/library/3awe4781.aspx)

## Exercise 1.2

> Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

```cpp
int main()
{
    return -1;
}
```

**Output (Windows)**

```
The thread 0x27a0 has exited with code -1 (0xffffffff).
The program '[11140] Exercise_1_2.exe' has exited with code -1 (0xffffffff).
```

## Exercise 1.3

> Write a program to print *Hello World* on the standard output.

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World" << std::endl;

    return 0;
}
```

## Exercise 1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.


```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;

    int num1 = 0;
    int num2 = 0;

    std::cin >> num1 >> num2;

    std::cout << "The product of " << num1 << " and " << num2 << " is: " << (num1 * num2) 
        << std::endl;

    return 0;
}
```

## Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each method.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;

    int num1 = 0;
    int num2 = 0;

    std::cin >> num1 >> num2;

    std::cout << "The product of ";
    std::cout << num1;
    std::cout << " and ";
    std::cout << num2;
    std::cout << " is: ";
    std::cout << (num1 * num2);
    std::cout << std::endl;

    return 0;
}
```

## Exercise 1.6

> Explain whether the following program fragment is legal.

```cpp
std::cout << "The sum of " << v1;
	  << " and " << v2;
	  << " is " << v1 + v2 << std::endl;
```

The program is illegal because a semicolon at the end of *v1;* and *v2;* stops the chaining of more values to the *ostream* object, named as *std::cout*. The fixed version of the code would look like the following.

```cpp
std::cout << "The sum of " << v1
	  << " and " << v2 
	  << " is " << v1 + v2 << std::endl;
```

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

```cpp
/*
 * Comment pairs /* */ cannot nest.
 * "cannot nest" is considered source code, 
 * as is the rest of the program
 */
int main()
{
    return 0;
}
```

**Output (Windows)**

```
1>------ Build started: Project: Exercise_1_7, Configuration: Debug Win32 ------
1>Main.cpp
1>D:\...\Exercise_1_7\Source\Main.cpp(2,35): error C4430:  missing type specifier - int assumed. Note: C++ does not support default-int
1>D:\...\Exercise_1_7\Source\Main.cpp(2,31): error C2146:  syntax error: missing ';' before identifier 'nest'
1>D:\...\Exercise_1_7\Source\Main.cpp(5,2): warning C4138:  '*/' found outside of comment
1>D:\...\Exercise_1_7\Source\Main.cpp(7,1): error C2143:  syntax error: missing ';' before '{'
1>D:\...\Exercise_1_7\Source\Main.cpp(7,1): error C2447:  '{': missing function header (old-style formal list?)
1>Done building project "Exercise_1_7.vcxproj" -- FAILED.
========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========

```

## Exercise 1.8

> Indicate which, if any, of the following output statements are legal:

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /*  "*/" /*  "/*"  */;
```

All the other lines except the third one is syntactically correct. The problem with the third line is that the used string ```" */;``` is missing a second quotation mark before the semicolon; Therefore, fixing the problem is rather easy.

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /*  "*/" /*  "/*"  */;
```

**Output (Windows)**

```
/**/ */ /*  
```

## Exercise 1.9

## Exercise 1.10

## Exercise 1.11

## Exercise 1.12

## Exercise 1.13

## Exercise 1.14

## Exercise 1.15

## Exercise 1.16

## Exercise 1.17

## Exercise 1.18

## Exercise 1.19

## Exercise 1.20

## Exercise 1.21

## Exercise 1.22

## Exercise 1.23

## Exercise 1.24

## Exercise 1.25