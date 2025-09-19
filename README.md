# 42-CPP_Module_02
42 Common Core CPP Module 02.  
Object-Oriented Programming in C++.  

## Table of Contents
- [Orthodox Canonical Form](#orthodox-canonical-form)
- [Fixed-point numbers](#fixed-point-numbers)
- [How to use](#how-to-use)
- [More info](#more-info)

----------------------------------------

### Orthodox Canonical Form
The Orthodox Canonical Form requires four member functions: Default constructor, Copy constructor, Copy assignment operator, and Destructor.
- **Default constructor**: a special method automatically invoked when creating an object (an instance of a class).
  - Signature: MyClass().
  - It can include initialization list, which initializes attributes before the body of the constructor.
    
        MyClass() : x(value)
    
- **Copy constructor**: it is called when initializing a new object as a copy of an existing one.
    - Signature: MyClass(const MyClass& other)
      - const: because the object that is received as an argument won't be modified
      - MyClass&: the object is received as reference, because if it were passed value, it would recursively call the copy constructor, leading to infinite recursion.
      - other: existent object we want to copy
  - Usage: two ways
    
        MyClass obj1;
        MyClass obj2 = obj1
        MyClass obj3(obj1);

- **Copy assignment operator**: used when an already existing object is assigned the value of another one.
    - Signature: MyClass& operator=(const MyClass& other);
    - This operator must check the self-assignment before copying (if (this != &other))
    - Usage:
      
          MyClass obj1;
          MyClass obj2;
          obj2 = obj1;
    
- **Destructor**: a special method automatically called when an objectis destroyed. It is used to free resources, close files, free dynamic memory, etc.

Simple class example in Orthodox Canonical Form:

    class   Fixed
    {
    	private:
    		int _value;
    		
    	public:
    		Fixed(void) : _value(0) {} //default constructor
    		Fixed(const Fixed& other) //Copy constructor
            {
                *this = other;
                //this->_value = other._value;
            }
    		Fixed& operator=(const Fixed& other) //Asignment operator
            {
                if (this != &other)
                    this->_value = other._value;
                return (*this);
            }
            ~Fixed(void) {} //destructor
      };



### Fixed-point numbers

**Integers vs Floating-point numbers**
- **Accuracy vs Precision**
  - Accuracy: how close a value is to the true value.
  - Precision: how finely a value can be represented or distinguished.

- **Integers**
  - Integers are perfectly accurate: if you store the integer 2, it is exactly 2.
  - But integers lack precision: they cannot represent fractional values. For example, both 5/2 and 4/2 would result in the integer 2, losing fractional part.

- **Floating-point numbers**
  - Floating-point values do the opposite trade-off: they can represent fractions and very large/small numbers, so they have precision.
  - But they are not always accurate: many decimal fractions cannot be represented exactly in binary. Example: adding 0.1f ten times may not give exactly 1.0f due to rounding errors.

**How integers are represented**
- A standar int is usually 32 bits (4 bytes)
- b31 is the most significant bit (MSB)
- b0 is the least significant bit (LSB)
- The position of the bits is calculated from right to left
- Each bit represents a power of two 2: bi = bi * 2^i
- Example (with 8 bits): 00001101 -> the bits in the positions 0, 2, and 3 have the value of 1, so:

      00001101 = 2^0 + 2^2 + 2^3 = 13

- Signed integers use two's complement representation:
  - If b31 (most significant bit - MSB) = 0, the number is positive.
  - If b31 = 1, the number is negative. 
- Range of signed int for 32-bit: from -2^31 (−2,147,483,648) to de 2^31 - 1 (2,147,483,647)

**How floating-point numbers are represented (IEEE-754)**  
IEEE-754 standard: float (4 bytes) o double (8 bytes). 
- A float (single precision, 4 bytes) is split into: 
  - 1 sign bit (b31)
  - 8 exponent bits (from b30 to b23)
  - 23 fraction bits (mantissa)
- Value = (-1)^sign * 1.mantissa * 2^(exponent-bias)
  - This allows representation of very small and very large numbers
  - But many decimal numbers are only approximated

**Fixed-point numbers**  
- Floating-point is not the only way to represent fractional numbers.
- Fixed-point arithmetic trades flexibility for speed: it uses only integer operations, which are typically faster on limited hardware.
- Precision is fixed (e.g., 8 fractional bits -> resolution of 1/256), unlike floats where precision varies with magnitude.
- Fixed-point numbers are widely used in digital signal processing, embeddeed systems, and video games, where performance is more importan than extreme precision.
- The idea:
  - Concept of binary point: is like the decimal point in the decimal system, acts as the division between the integer and the fractional part of the number.
  - Instead of being free to "float" like in floats, here it is fixed at a certain position.
  - Example: if we decide that the last 8 bits of an integer represent the fractional part, then:
    
        1.0 is stored as 1 << 8 = 256
        5.0 is stored as 5 << 8 = 1280
        5.5 is stored as 5.5 * 256 = 1408

⚠️ DON'T PANIC! Continue reading 👇

**Conversions**
- **From int to fixed-point**
  - << operator: shift left of bits. x << n (where n are the fractional bits): shifts left the bits of x n positions, and fills with 0's by the right. Is the same that doing x * 2^n
  - Example with 8 bits:
  
          x = 5 -> 00000101
          x << 1 -> 00001010 = 10 (5 * 2^1)
          x << 2 -> 00010100 = 20 (5 * 2^2)
    
  - With 32 bits: if we decide that the last 8 bits will represent the fractional part (n = 8), then:

           1 << 8 = 1 * 2^8 = 256
           5 << 8 = 5 * 2^8 = 1280

This means that we store the value in a variable of int type, but with its last 8 digits interpreted as fractional part. The unity is 1 << 8 = 256

- **From fixed-point to int**
  - Divide by 2^n (shift right)

- **From float to fixed-point**
  - Multiply the float by 2^n and round to the nearest integer

- **From fixed-point to float**
  - Divide by 2^n

------------------

### How to use

For each exercise (each subdirectory):
- Compile:
  
      make

- Run the executable:

      ./fixed
  


### More info

Understanding and Using Floating Point Numbers &rarr; [HERE](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)  
Floating point number representation &rarr; [HERE](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html)  
Printing floating point numbers &rarr; [HERE](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)  
Berkeley's papper about Fixed-Point Numbers &rarr; [HERE](https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html)
