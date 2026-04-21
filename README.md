# CPP Module 04 - Subtype Polymorphism, Abstract Classes, and Interfaces

## Objective

The goal of `CPP Module 04` is to learn and apply **polymorphism**, understand what an **abstract class** is and how to define it, and explore the design and usage of **interfaces**.

## Project structure

```
CPP_Module_04/
├── ex00/          # Polymorphism - Animals and WrongAnimals
├── ex01/          # I don’t want to set the world on fire - Brain, deep copies
├── ex02/          # Abstract class - Making Animal abstract
├── ex03/          # Interface & recap - AMateria system and MateriaSource
└── README.md      # This file 
```

## Exercises

### ex00: Polymorphism

**Description:**
This exercise consists of creating `Dog` and `Cat` classes that inherit from the `Animal` class and implement the appropriate sound behavior

**What you will learn:**
- How polymorphism works in C++
- How derived classes override base class behavior
- How to implement virtual functions
- The importance of the `virtual` keyword in methods
- Why virtual destructors are necessary in inheritance

**Program functionality:**
- Create `Dog` and `Cat` objects using polymorphism
- Verify that they produce the correct sounds via virtual functions 
- Create a `WrongCat` object (without virtual functions) to demonstrate incorrect behavior
- Delete all allocated objects to avoid memory leaks

**Class design:**

**Animal**

*Protected attributes:*
- `std::string _type`

*Public methods:*
- `std::string getType() const`
- `virtual void makeSound() const`

*Operators:*
- `Animal& operator=(const Animal& object)`

**Dog**

*Inherited attributes:*
- `std::string _type` from `Animal`

*Inherited methods:*
- `void makeSound() const`

*Operators:*
- `Dog& operator=(const Dog& object)`

**Cat**

*Inherited attributes:*
- `std::string _type` from `Animal`

*Inherited methods:*
- `void makeSound() const`

*Operators:*
- `Cat& operator=(const Cat& object)`

**WrongAnimal**

*Protected attributes:*
- `std::string _type`

*Public methods:*
- `std::string getType() const`
- `void makeSound() const`

*Operators:*
- `WrongAnimal& operator=(const WrongAnimal& object)`

**WrongCat**

*Inherited attributes:*
- `std::string _type` from `WrongAnimal`

*Inherited methods:*
- `void makeSound() const`

*Operators:*
- `WrongCat& operator=(const WrongCat& object)`

**Example usage:**

```bash
$ ./animal
# Output

============== Normal ==============

Animal: Default constructor called
Animal: Default constructor called
Dog: Default constructor called
Animal: Default constructor called
Cat: Default constructor called

Dog 
Cat 
Miau Miau!
Guau Guau!
Animal sound

============== Wrong ==============

WrongAnimal: Default constructor called
WrongCat: Default constructor called

WrongCat 
WrongAnimal sound

============== Destructors ==============

Animal: Destructor called
Dog: Destructor called
Animal: Destructor called
Cat: Destructor called
Animal: Destructor called
WrongCat: Destructor called
WrongAnimal: Destructor called
```

---

### ex01: I don’t want to set the world on fire

**Description:**
This exercise consists of implementing a `Brain` class and creating an `Animal*` array filled half with `Dog` objects and half with `Cat` objects. Each `Dog` and `Cat` will have a `Brain` object that must be properly deep copied.

**What you will learn:**
- The concept of ownership in C++
- The difference between shallow copy and deep copy
- How to implement deep copies in classes that manage dynamic resources

**Program functionality:**
- Create an `Animal*` array filled half with `Dog` objects and half with `Cat` objects
- Verify that deep copies work correctly
- Delete all allocated objects to avoid memory leaks

**Class design:**

**Animal**

*Protected attributes:*
- `std::string _type`

*Public methods:*
- `std::string getType() const`
- `virtual void makeSound() const`

*Operators:*
- `Animal& operator=(const Animal& object)`

**Dog**

*Inherited attributes:*
- `std::string _type` from `Animal`

*Inherited methods:*
- `void makeSound() const`

*Operators:*
- `Dog& operator=(const Dog& object)`

**Cat**

*Inherited attributes:*
- `std::string _type` from `Animal`

*Inherited methods:*
- `void makeSound() const`

*Operators:*
- `Cat& operator=(const Cat& object)`

**Brain**

*Private attributes:*
- `std::string _ideas[100]`

*Public methods:*
- `std::string getIdea(int index) const`
- `void setIdea(int index, std::string idea)`

*Operators:*
- `Brain& operator=(const Brain& object)`

**Example usage:**

```bash
$ ./brain
# Output

============== Creation ==============

Dog: 1
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Dog: 2
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Dog: 3
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Dog: 4
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Dog: 5
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Cat: 1
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called
Cat: 2
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called
Cat: 3
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called
Cat: 4
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called
Cat: 5
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called

============== Test ==============

Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Animal: Copy constructor called
Dog: Copy constructor called
Brain: Copy constructor called

Original idea 0: 42
Copy idea 0: 21

============== Destructors ==============

Object: 1
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 2
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 3
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 4
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 5
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 6
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 7
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 8
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 9
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 10
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called

Original Dog:
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Copy Dog:
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
```

---

### ex02: Abstract class

**Description:**
This exercise consists of making the `Animal` class abstract without changing its previous behavior

**What you will learn:**
- How an abstract class works
- How to convert a class into an abstract class

**Program functionality:**
- Verify that the program behaves the same with `Animal` as an abstract class

**Class design:**

**Animal**

*Protected attributes:*
- `std::string _type`

*Public methods:*
- `std::string getType() const`
- `virtual void makeSound() const = 0`

*Operators:*
- `Animal& operator=(const Animal& object)`

**Dog**

*Inherited attributes:*
- `std::string _type` from `Animal`

*Inherited methods:*
- `void makeSound() const`

*Operators:*
- `Dog& operator=(const Dog& object)`

**Cat**

*Inherited attributes:*
- `std::string _type` from `Animal`

*Inherited methods:*
- `void makeSound() const`

*Operators:*
- `Cat& operator=(const Cat& object)`

**Brain**

*Private attributes:*
- `std::string _ideas[100]`

*Public methods:*
- `std::string getIdea(int index) const`
- `void setIdea(int index, std::string idea)`

*Operators:*
- `Brain& operator=(const Brain& object)`

**Example usage:**

```bash
$ ./abstract
# Output

============== Creation ==============

Dog: 1
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Dog: 2
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Dog: 3
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Dog: 4
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Dog: 5
Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Cat: 1
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called
Cat: 2
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called
Cat: 3
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called
Cat: 4
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called
Cat: 5
Animal: Default constructor called
Cat: Default constructor called
Brain: Default constructor called

============== Test ==============

Animal: Default constructor called
Dog: Default constructor called
Brain: Default constructor called
Animal: Copy constructor called
Dog: Copy constructor called
Brain: Copy constructor called

Original idea 0: 42
Copy idea 0: 21

============== Destructors ==============

Object: 1
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 2
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 3
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 4
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 5
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 6
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 7
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 8
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 9
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called
Object: 10
Cat: Destructor called
Brain: Destructor called
Animal: Destructor called

Original Dog:
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
Copy Dog:
Dog: Destructor called
Brain: Destructor called
Animal: Destructor called
```

---

### ex03: Interface & recap

**Description:**
This exercise consists of implementing a Materia system using abstract classes and interfaces. You will create concrete Materias (`Ice` and `Cure`), a `Character` class with an inventory, and a `MateriaSource` that can learn and create Materias

**What you will learn:**
- How interfaces (pure abstract classes) work in C++
- How to design and use abstract classes in a real system
- How to manage object ownership in an inventory system
- How to implement a simple factory pattern (`MateriaSource`)

**Program functionality:**
- Learn Materias by storing them as templates in an `AMateria*` array
- Create Materias from learned types using a `MateriaSource`
- Equip and manage Materias inside a `Character` inventory
- Use Materias on a target through the `Character`
- Delete all allocated objects to avoid memory leaks

**Class design:**

**AMateria**

*Protected attributes:*
- `std::string _type`

*Public methods:*
- `std::string const & getType() const`
- `virtual AMateria* clone() const = 0`
- `virtual void use(ICharacter& target)`

*Operators:*
- `AMateria& operator=(const AMateria& object)`

**Ice**

*Inherited attributes:*
- `std::string _type` from `AMateria`

*Inherited methods:*
- `AMateria* clone() const`
- `void use(ICharacter& target)`

*Operators:*
- `Ice& operator=(const Ice& object)`

**Cure**

*Inherited attributes:*
- `std::string _type` from `AMateria`

*Inherited methods:*
- `AMateria* clone() const`
- `void use(ICharacter& target)`

*Operators:*
- `Cure& operator=(const Cure& object)`

**Character**

*Private attributes:*
- `std::string _name`
- `AMateria* _inventory[4]`
- `int _floorCount`
- `AMateria* _floor[50]`

*Implemented methods (from `ICharacter`):*
- `std::string const & getName() const`
- `void equip(AMateria* m)`
- `void unequip(int idx)`
- `void use(int idx, ICharacter& target)`

*Operators:*
- `Character& operator=(const Character& object)`

**MateriaSource**

*Private attributes:*
- `AMateria* _memory[4]`

*Implemented methods (from `IMateriaSource`):*
- `void learnMateria(AMateria*)`
- `AMateria* createMateria(std::string const & type)`

*Operators:*
- `MateriaSource& operator=(const MateriaSource& object)`

**Interfaces:**

**ICharacter**
- `virtual ~ICharacter() {}`
- `virtual std::string const & getName() const = 0`
- `virtual void equip(AMateria* m) = 0`
- `virtual void unequip(int idx) = 0`
- `virtual void use(int idx, ICharacter& target) = 0`

**IMateriaSource**
- `virtual ~IMateriaSource() {}`
- `virtual void learnMateria(AMateria*) = 0`
- `virtual AMateria* createMateria(std::string const & type) = 0`

**Example usage:**

```bash
$ ./inventory
# Output

============== Learn ==============

[ice] Materia has been learned!
[cure] Materia has been learned!

============== Equip ==============

[ice] Materia has been equipped!
[cure] Materia has been equipped!

============== Use ================

* shoots an ice bolt at bob *
* heals bob's wounds *
```