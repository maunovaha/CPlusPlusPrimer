# Chapter 1

> This chapter introduces most of the basic elements of C++: types, variables, expressions, statements, and functions.

## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

* [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/index.php?diapo=extensions)
* [File Types Creates for Visual C++ Projects](https://msdn.microsoft.com/en-us/library/3awe4781.aspx)

## Exercise 1.2

> Change the program to return *-1*. A return value of *-1* is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from *main*.

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

> Write a program to print *Hello, World* on the standard output.

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World" << std::endl;

    return 0;
}
```

## Exercise 1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.


```cpp
#include <iostream>

int main()
{
    std::cout << "Please enter two numbers: " << std::endl;

    int first_number = 0;
    int second_number = 0;

    std::cin >> first_number >> second_number;

    std::cout << "The product of " << first_number << " and " << second_number 
        << " is " << (first_number * second_number) << std::endl;

    return 0;
}
```

## Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each method.

```cpp
#include <iostream>

int main()
{
    std::cout << "Please enter two numbers: " << std::endl;

    int first_number = 0;
    int second_number = 0;

    std::cin >> first_number >> second_number;

    std::cout << "The product of ";
    std::cout << first_number;
    std::cout << " and ";
    std::cout << second_number;
    std::cout << " is ";
    std::cout << (first_number * second_number);
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
1>D:\...\Source\Main.cpp(2,35): error C4430:  missing type specifier - int assumed. Note: C++ does not support default-int
1>D:\...\Source\Main.cpp(2,31): error C2146:  syntax error: missing ';' before identifier 'nest'
1>D:\...\Source\Main.cpp(5,2): warning C4138:  '*/' found outside of comment
1>D:\...\Source\Main.cpp(7,1): error C2143:  syntax error: missing ';' before '{'
1>D:\...\Source\Main.cpp(7,1): error C2447:  '{': missing function header (old-style formal list?)
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

All the other lines except the third one is syntactically correct. The problem with the third line is that the used string ```/* "*/" */;``` is missing a second quotation mark before the semicolon; Therefore, fixing the problem is rather easy.

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /*  "*/" /*  "/*"  */;
```

**Output**

```
/**/ */ /*  
```

## Exercise 1.9

> Write a program that uses a *while* to sum the numbers from 50 to 100.

```cpp
#include <iostream>

int main()
{
    int low = 50;
    int high = 100;
    int current = low;
    int sum = 0;

    while (current <= high) {
        sum += current;
        ++current;
    }

    std::cout << "The sum of " << low << " to " << high << " inclusive is " << sum << std::endl;

    return 0;
}
```

## Exercise 1.10

> In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a *while* that prints the numbers from ten down to *zero*.

```cpp
#include <iostream>

int main()
{
    int low = 0;
    int high = 10;
    int current = high;

    while (current >= low) {
        std::cout << "Current value is " << current << std::endl;
        --current;
    }

    return 0;
}
```

## Exercise 1.11

> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

```cpp
#include <iostream>

int main()
{
    int first_number = 0;
    std::cout << "Please enter the first number: ";
    std::cin >> first_number;

    int second_number = 0;
    std::cout << "Please enter the second number: ";
    std::cin >> second_number;

    // In order for program to handle printing numbers to both directions (e.g. from 1 to 5 and 5 to 1),
    // we define a variable called `increment` which value is either 1 or -1
    int increment = first_number < second_number ? 1 : -1;
    int current = first_number;
    int last = second_number + increment;

    while (current != last) {
        std::cout << "Current number is " << current << std::endl;
        current += increment;
    }

    return 0;
}
```

## Exercise 1.12

> What does the following *for* loop do? What is the final value of *sum*?

```cpp
int sum = 0;

for (int i = -100; i <= 100; ++i)
    sum += i;
```

The *for* loop sums the numbers from *-100* to *100*. Consequently, the final *sum* is *zero*.

## Exercise 1.13

>  Rewrite the first two exercises from § 1.4.1 (p. 13) using *for* loops.

**Ex1.9** using *for* loop:

```cpp
#include <iostream>

int main()
{
    int low = 50;
    int high = 100;
    int sum = 0;

    for (int i = low; i <= high; ++i) {
        sum += i;
    }

    std::cout << "The sum of " << low << " to " << high << " inclusive is " << sum << std::endl;

    return 0;
}
```

**Ex1.10** using *for* loop:

```cpp
#include <iostream>

int main()
{
    int low = 0;
    int high = 10;

    for (int i = high; i >= low; --i) {
        std::cout << "Current value is " << i << std::endl;
    }

    return 0;
}
```

## Exercise 1.14

> Compare and contrast the loops that used a *for* with those using a *while*. Are there advantages or disadvantages to using either form?

I would use *for* loops in both of the cases because it makes it easier to use variable in a condition and increment that variable with a single line of code. Of course, this is also probably just matter of personal preference.

## Exercise 1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

**Syntax error**

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World" < std::endl; // Error: Missing second `<` after "Hello, World"

    return 0;
}
```

Output (Windows)

```
1>------ Build started: Project: Exercise_1_15, Configuration: Debug Win32 ------
1>Main.cpp
1>D:\...\Source\Main.cpp(5,44): error C2678:  binary '<': no operator found which takes a left-hand operand of type 'std::basic_ostream<char,std::char_traits<char>>' (or there is no acceptable conversion)
1>D:\...\MSVC\14.21.27702\include\system_error(259,24): message :  could be 'bool std::operator <(const std::error_code &,const std::error_code &) noexcept' [found using argument-dependent lookup]
1>D:\...\MSVC\14.21.27702\include\system_error(264,24): message :  or       'bool std::operator <(const std::error_condition &,const std::error_condition &) noexcept' [found using argument-dependent lookup]
1>D:\...\Source\Main.cpp(5,44): message :  while trying to match the argument list '(std::basic_ostream<char,std::char_traits<char>>, overloaded-function)'
1>Done building project "Exercise_1_15.vcxproj" -- FAILED.
========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========
```

**Type error**

```cpp
#include <iostream>

int main()
{
    std::string age = 30; // Error: Trying to assing number to string

    return 0;
}
```

Output (Windows)

```
1>------ Build started: Project: Exercise_1_15, Configuration: Debug Win32 ------
1>Main.cpp
1>D:\...\Source\Main.cpp(5,25): error C2440:  'initializing': cannot convert from 'int' to 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>'
1>D:\...\Source\Main.cpp(5,25): message :  No constructor could take the source type, or constructor overload resolution was ambiguous
1>Done building project "Exercise_1_15.vcxproj" -- FAILED.
========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========
```

**Declaration error**

```cpp
#include <iostream>

int main()
{
    cout << "Hello, World" << std::endl; // Error: There should be namespace `std::` in front of `cout`
}
```

Output (Windows)

```
1>------ Build started: Project: Exercise_1_15, Configuration: Debug Win32 ------
1>Main.cpp
1>D:\...\Source\Main.cpp(5,5): error C2065:  'cout': undeclared identifier
1>Done building project "Exercise_1_15.vcxproj" -- FAILED.
========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========
```

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