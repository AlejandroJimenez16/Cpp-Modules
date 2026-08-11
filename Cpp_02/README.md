# CPP Module 02 - Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form

## Objective

The goal of `CPP Module 02` is to practice the Orthodox Canonical Form in C++, explore **ad-hoc polymorphism** through **function and operator overloading**, understand the concept of a **fixed-point value**, and practice working with it.

## Project structure

```
CPP_Module_02/
├── ex00/          # My First Class in Orthodox Canonical Form - Introduction to canonical form
├── ex01/          # Towards a more useful fixed-point number class - Convert to fixed value
├── ex02/          # Now we’re talking - Operator overloading
├── ex03/          # BSP - Use operator overloading to determine if a point is inside or outside a triangle
└── README.md      # This file 
```

## Exercises

### ex00: My First Class in Orthodox Canonical Form

**Description:**
This exercise consists of creating a `Fixed` class in Orthodox Canonical Form that represents a fixed-point number.

**What you will learn:**
- How to implement a class following the **Orthodox Canonical Form** in C++
- How to properly use constructors, destructors, and assignment operators
- The concept of fixed-point numbers and storing fractional values with controlled precision

**Program functionality:**
- Create `Fixed` objects
- Copy one object into another using the copy constructor
- Assign one object to another using the copy assignment operator
- Display messages showing the order of constructor, assignment, and destructor calls

**Class design:**

**Fixed**

*Private attributes:*
- `int _fixedPointValue`
- `static const int _fractionalBits = 8`

*Public methods:*
- `int getRawBits(void) const`
- `void setRawBits(int const raw)`

*Operators:*
- `Fixed& operator=(const Fixed& object)`

**Example usage:**

```bash
$ ./fixed
# Output
Default constructor called
Copy constructor called
Copy assignment operator called
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
```

---

### ex01: Towards a more useful fixed-point number class

**Description:**
This exercise consists of creating a `Fixed` class that converts floating-point numbers to fixed-point values and allows displaying them using the overloaded (`<<`) operator.

**What you will learn:**
- How to convert a integer to a fixed-point value
- How to convert a floating-point number to a fixed-point value
- How to overload the output operator (`<<`) for custom classes

**Program functionality:**
- Create `Fixed` objects using the default, integer, and floating-point constructors
- Copy one object into another using the copy constructor
- Assign one object to another using the copy assignment operator
- Convert `Fixed` objects to integers using toInt() and display the results.
- Print `Fixed` objects using the overloaded (`<<`) operator.
- Display messages showing the order of constructor, assignment, and destructor calls

**Class design:**

**Fixed**

*Private attributes:*
- `int _fixedPointValue`
- `static const int _fractionalBits = 8`

*Public methods:*
- `int getRawBits(void) const`
- `void setRawBits(int const raw)`
- `float toFloat(void) const`
- `int toInt( void ) const`

*Operators:*
- `Fixed& operator=(const Fixed& object)`

*External operators:*
- `std::ostream &operator<<(std::ostream &out, const Fixed& object)`

**Example usage:**

```bash
$ ./fixedUseful
# Output
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
```

---

### ex02: Now we’re talking

**Description:**
This exercise consists of implementing operator overloading in the `Fixed` class by adding **comparison operators**, **arithmetic operators**, and **increment/decrement operators**, allowing `Fixed` objects to be used in expressions naturally.

**What you will learn:**
- How to overload **comparison operators** (`>`, `<`, `>=`, `<=`, `==`, `!=`) for custom classes
- How to overload **arithmetic operators** (`+`, `-`, `*`, `/`) for custom classes
- How to overload **increment and decrement operators** (`++`, `--`) in both prefix and postfix forms

**Program functionality:**
- Creates `Fixed` objects using the default constructor and arithmetic expressions
- Demonstrates arithmetic operations by multiplying `Fixed` objects
- Uses prefix (`++a`) and postfix (`a++`) increment operators and prints the results
- Displays `Fixed` objects using the overloaded (`<<`) operator

**Class design:**

**Fixed**

*Private attributes:*
- `int _fixedPointValue`
- `static const int _fractionalBits = 8`

*Public methods:*
- `int getRawBits(void) const`
- `void setRawBits(int const raw)`
- `float toFloat(void) const`
- `int toInt( void ) const`

*Public static methods:*
- `static Fixed& min(Fixed& fp1, Fixed& fp2)`: Returns a reference to the smallest object
- `static const Fixed& min(const Fixed& fp1, const Fixed& fp2)`: Returns a constant reference to the smallest object
- `static Fixed& max(Fixed& fp1, Fixed& fp2)`: Returns a reference to the greatest object
- `static const Fixed& max(const Fixed& fp1, const Fixed& fp2)`: Returns a constant reference to the greatest object

*Operators:*
- `Fixed& operator=(const Fixed& object)`

*Comparison Operators:*
- `bool operator>(const Fixed& object) const`
- `bool operator<(const Fixed& object) const`
- `bool operator>=(const Fixed& object) const`
- `bool operator<=(const Fixed& object) const`
- `bool operator==(const Fixed& object) const`
- `bool operator!=(const Fixed& object) const`

*Arithmetic Operators:*
- `Fixed operator+(const Fixed& object)`
- `Fixed operator-(const Fixed& object)`
- `Fixed operator*(const Fixed& object)`
- `Fixed operator/(const Fixed& object)`

*Increment/Decrement Operators:*
- `Fixed& operator++()`
- `Fixed operator++(int);`
- `Fixed& operator--()`
- `Fixed operator--(int)`

*External operators:*
- `std::ostream &operator<<(std::ostream &out, const Fixed& object)`

**Example usage:**

```bash
$ ./nowWeAreTalking
# Output
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

---

### ex03: BSP

**Description:**
This exercise consists of a program that determines whether a point is inside or outside a triangle by creating a `Point` class using `Fixed` objects for the x and y coordinates.

**What you will learn:**
- How to work with constant attributes in a class
- How to initialize attributes using constructor initialization lists
- How to calculate areas to determine whether a point lies inside or outside a triangle

**Program functionality:**
- Creates `Point` objects representing the vertices of a triangle (`a`, `b`, `c`)
- Calls the `bsp()` function to determine if a point is inside or outside a triangle

**Class design:**

**Fixed**

*Private attributes:*
- `int _fixedPointValue`
- `static const int _fractionalBits = 8`

*Public methods:*
- `int getRawBits(void) const`
- `void setRawBits(int const raw)`
- `float toFloat(void) const`
- `int toInt( void ) const`

*Public static methods:*
- `static Fixed& min(Fixed& fp1, Fixed& fp2)`: Returns a reference to the smallest object
- `static const Fixed& min(const Fixed& fp1, const Fixed& fp2)`: Returns a constant reference to the smallest object
- `static Fixed& max(Fixed& fp1, Fixed& fp2)`: Returns a reference to the greatest object
- `static const Fixed& max(const Fixed& fp1, const Fixed& fp2)`: Returns a constant reference to the greatest object

*Operators:*
- `Fixed& operator=(const Fixed& object)`

*Comparison Operators:*
- `bool operator>(const Fixed& object) const`
- `bool operator<(const Fixed& object) const`
- `bool operator>=(const Fixed& object) const`
- `bool operator<=(const Fixed& object) const`
- `bool operator==(const Fixed& object) const`
- `bool operator!=(const Fixed& object) const`

*Arithmetic Operators:*
- `Fixed operator+(const Fixed& object)`
- `Fixed operator-(const Fixed& object)`
- `Fixed operator*(const Fixed& object)`
- `Fixed operator/(const Fixed& object)`

*Increment/Decrement Operators:*
- `Fixed& operator++()`
- `Fixed operator++(int);`
- `Fixed& operator--()`
- `Fixed operator--(int)`

*External operators:*
- `std::ostream &operator<<(std::ostream &out, const Fixed& object)`

**Point**

*Private attributes:*
- `const Fixed _x`
- `const Fixed _y`

*Public methods:*
- `Fixed getX() const`
- `Fixed getY() const`

*Operators:*
- `Point& operator=(const Point& object)`

*Functions:*
- `bool bsp(Point const a, Point const b, Point const c, Point const point)`: Returns `true` if the point is inside the triangle and `false` if it is outside

**Example usage:**

```bash
$ ./bsp
# Output
==============================
Vertex:
Point is a vertex or an edge

Edge:
Point is a vertex or an edge

Outside:
Point is outside the triangle

Inside:
Point is inside the triangle
==============================
```