# 42-CPP_Module_02
42 Common Core CPP Module 02

### Orthodox Canonical Form
4 funciones miembro requeridas:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

**Copy Constructor**: se llama cuando quieres inicializar un objeto nuevo copiando otro existente.  
- Firma: MyClass(const MyClass& other);
    - MyClass: nombre de la clase
    - const: el objeto que se recibe como argumento no será modificado
    - MyClass&: se recibe el objeto como referencia, porque si se recibiera por valor entraíamos en un bucle infinito: para copiarlo habría que volver a llamar a copy constructor
    - other: objeto ya existente que se quiere copiar
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

Exactitud vs Precisión -> 
- Exactitud: cómo de cerca está una medida al valor real
- Precisión: cuánta información se tiene sobre una cantidad, con qué precisión la tienes determinada.
La aritmética de integer tiene exactitud total: si tenemos un entero '2', su valor exacto es '2'. Cualquier operación que se haga con enteros obtiene un número que corresponde el valor correcto bit-for-bit. Pero a los integers les falta precisión: dividir 5 o 4 entre 2, en ambos casos se obtiene 2. Los integers no registran la parte fraccional.
Los números de punto flotante son lo contrario a los enteros con respecto a exactitud y precisión. Tienen buena precisión, ya que no descartan deliberadamente la información que representan sus números; si tienes suficientes bits, puedes revertir cualquier cálculo hasta su número original, o puedes representar cualquier entero grande arbitrario. Pero tienen poca exactitud.

**¿Cómo se representa un int en bits?**
En C++ que tenemos ahora: int -> 32 bits (4 bytes)  
- b31 es el bit más significativo
- b0 es el bit menos significativo
- La posición de los bits se calcula de derecha a izquierda
- Cada bit tiene un peso que es una potencia de 2: bi = bi * 2^i
  - b0 -> 2^0 = 1
  - b1 -> 2^1 = 2
  - ...
- Ejemplo (con 8 bits): 00001101 -> los bits 3, 2 y 0 valen 1:
  - 2^3 = 8
  - 2^2 = 4
  - 2^0 = 1
  - 8+4+1 = 13
- Enteros con signo: funciona como hemos dicho hasta ahora, sumando el valor de todos los bits, del 0 al 31. El máximo unsigned int de 32 bits es con todos los bits a 1: 4,294,967,295
- Enteros con signo:
  - Si b31 = 0: el número es positivo y se calcula igual que el unsigned (suma de bi*2^i)
  - Si b31 = 1: el número es negativo. Hay dos formas equivalentes de obtener su valor decimal:
      - Método directo: valor = -2^31 + (suma de bi*2^i para i de 0 a 30)
      - Método unsigned-the-substract: calcula el valor como si fuera unsigned, luego resta 2^32.
    Rango de signed 32-bit: mínimo de -2^31 (−2,147,483,648) y máximo de 2^31 - 1 (2,147,483,647)

**¿Cómo se representa un floating point number?**  
IEEE-754 standard: float (4 bytes) o double (8 bytes). Tiene 3 componentes: 
- Un bit para el signo, que indica si es positivo o negativo
- Un exponente que da el orden de magnitud (?)
- Una mantisa (?) que especifica los dígitos reales del número
Disposición de los bit en un float de single-precision:
- El bit 31 es el signo
- Los bits del 30 al 23 son el exponente
- El resto son los dígitos reales
El valor del número es las veces de la mantissa (?) 2^x, siendo x el exponente. Aquí trabajamos con fracciones binarias, osea que el bit de mantisa de más a la izquierda es 1/2??

?????  

**Fixed-point numbers**  
Los floating point numbers no son la única manera de trabajar y representar números con parte fraccional. Los números de tipo fixed point se usan el procesamiento de señal digital y aplicaciones de juegos, donde el performance a veces es más importante que la precisión. 

La clave para representar números fraccionales es el concepto de binary point: es como el punto decimal en el sistema decimal. Actúa como divisor entre el entero y la parte fraccional del número. 

------------------


Understanding and Using Floating Point Numbers: https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html  
Floating point number representation: https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html  
Printing floating point numbers: https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html  



**Fixed-point numbers**: EXPLICARRR QUÉ SON, POR QUÉ SON MEJORES EN CUANTO A PERFORMANCE, ACCURACY, RANGO, PRECISIÓN...

Artículo de Berkely sobre Fixed-Point Numbers: https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
