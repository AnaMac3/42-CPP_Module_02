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
