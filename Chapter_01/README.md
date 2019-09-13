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

    int num1 = 0;
    int num2 = 0;

    std::cin >> num1 >> num2;

    std::cout << "The product of " << num1 << " and " << num2 << " is " << (num1 * num2) << std::endl;

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

    int num1 = 0;
    int num2 = 0;

    std::cin >> num1 >> num2;

    std::cout << "The product of ";
    std::cout << num1;
    std::cout << " and ";
    std::cout << num2;
    std::cout << " is ";
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
    int min = 50;
    int max = 100;
    int current = min;
    int sum = 0;

    while (current <= max) {
        sum += current;
        ++current;
    }

    std::cout << "The sum of " << min << " to " << max << " inclusive is " << sum << std::endl;

    return 0;
}
```

## Exercise 1.10

> In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a *while* that prints the numbers from ten down to *zero*.

```cpp
#include <iostream>

int main()
{
    int min = 0;
    int max = 10;
    int current = max;

    while (current >= min) {
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
    int num1 = 0;
    int num2 = 0;

    std::cout << "Please enter the first number: ";
    std::cin >> num1;

    std::cout << "Please enter the second number: ";
    std::cin >> num2;

    // In order for program to handle printing numbers to both directions (e.g. from 1 to 5 and 5 to 1),
    // we define a variable called `increment` which value is either 1 or -1.
    int increment = num1 < num2 ? 1 : -1;
    int current = num1;
    int last = num2 + increment;

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
    int min = 50;
    int max = 100;
    int sum = 0;

    for (int i = min; i <= max; ++i) {
        sum += i;
    }

    std::cout << "The sum of " << min << " to " << max << " inclusive is " << sum << std::endl;

    return 0;
}
```

**Ex1.10** using *for* loop:

```cpp
#include <iostream>

int main()
{
    int min = 0;
    int max = 10;

    for (int i = max; i >= min; --i) {
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

### Example: Syntax error

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World" < std::endl; // Error: Missing second `<` after "Hello, World"

    return 0;
}
```

**Output (Windows)**

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

### Example: Type error

```cpp
#include <iostream>

int main()
{
    std::string age = 30; // Error: Trying to assing number to string

    return 0;
}
```

**Output (Windows)**

```
1>------ Build started: Project: Exercise_1_15, Configuration: Debug Win32 ------
1>Main.cpp
1>D:\...\Source\Main.cpp(5,25): error C2440:  'initializing': cannot convert from 'int' to 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>'
1>D:\...\Source\Main.cpp(5,25): message :  No constructor could take the source type, or constructor overload resolution was ambiguous
1>Done building project "Exercise_1_15.vcxproj" -- FAILED.
========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========
```

### Example: Declaration error

```cpp
#include <iostream>

int main()
{
    cout << "Hello, World" << std::endl; // Error: There should be namespace `std::` in front of `cout`

    return 0;
}
```

**Output (Windows)**

```
1>------ Build started: Project: Exercise_1_15, Configuration: Debug Win32 ------
1>Main.cpp
1>D:\...\Source\Main.cpp(5,5): error C2065:  'cout': undeclared identifier
1>Done building project "Exercise_1_15.vcxproj" -- FAILED.
========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========
```

## Exercise 1.16

> Write your own version of a program that prints the sum of a set of integers read from *cin*.

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    int user_input = 0;
    
    do {
        std::cout << "Enter a number: ";
        std::cin >> user_input;

        sum += user_input;
    }
    while (!std::cin.fail());

    std::cout << "The sum is: " << sum << std::endl;

    return 0;
}
```

## Exercise 1.17

> **_a)_** What happens in the program presented in this section if the input values are all equal? **_b)_** What if there are no duplicated values?

```cpp
#include <iostream>

int main()
{
    int previous = 0;

    if (std::cin >> previous) {
        int replicas = 1;
        int current = 0;

        while (std::cin >> current) {
            if (current == previous) {
                ++replicas;
            }
            else {
                std::cout << previous << " occurs " << replicas << " times" << std::endl;
                previous = current;
                replicas = 1;
            }
        }

        std::cout << previous << " occurs " << replicas << " times" << std::endl;
    }

    return 0;
}
```

**_a)_** The program prints how many times given input value occurs but only after the *cin* encounters an error.

**_b)_** The program prints occurences of all other values except the last one; The last value is printed only after the *cin* encounters an error.

## Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

Works as [already described in Exercise 1.17](#exercise-117).

## Exercise 1.19

## Exercise 1.20

## Exercise 1.21

## Exercise 1.22

## Exercise 1.23

## Exercise 1.24

## Exercise 1.25
