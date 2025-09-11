# 42-CPP_Module_02
42 Common Core CPP Module 02

### Orthodox Canonical Form
4 funciones miembro requeridas:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

**Copy Constructor**: se llama cuando creas un objeto nuevo copiando otro existente.  
- Firma: MyClass(const MyClass& other);
- Uso:
  
        MyClass obj1;  
        MyClass obj2 = obj1;
 
**Copy assignment operator**: se usa cuando ya existe un objeto, para asignarle el valor de otro objeto ya existente también.
- Firma: MyClass& operator=(const MyClass& other);
- Uso:
  
        MyClass obj1;  
        MyClass obj2;  
        obj1 = obj2;  

### Fixed-point numbers

**Integers and floating-point numbers**
Understanding and Using Floating Point Numbers: https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html  
Floating point number representation: https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html  
rinting floating point numbers: https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html  

**Fixed-point numbers**: EXPLICARRR QUÉ SON, POR QUÉ SON MEJORES EN CUANTO A PERFORMANCE, ACCURACY, RANGO, PRECISIÓN...

Artículo de Berkely sobre Fixed-Point Numbers: https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
