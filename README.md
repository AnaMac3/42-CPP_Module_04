# 42-CPP_Module_04
42 Common Core CPP Module 02.  
- Object-Oriented Programming in C++
- Polymorphism
- Abstract classes
- Interfaces

- 
## Table of Contents
- [](#)
- [](#f)
- [](#f)
- [More info](#more-info)

----------------------------------------

--> Buenas prácticas:
- En los métodos miembro/funciones usar referencias para evitar copias innecesarias
- Usar const siempre que no se vaya a tener que modificar las variables de turno, por buenas prácticas tb

---> cuándo tenemos que declarar un destructor como virtual?

--> cosas nuevas; std::copy de algorithm
--> std::array<std::string, 100>
--> clases no instanciables...  

### Deep copy
--> deep copy para que cada objeto de clase hija tenga su objeto Brain independiente?¡
- Shallow copy: only copies the pointers, not the content. Two different objects point to the same memory resource. Esto provoca problemas al liberar memoria (doble delete)

            this->_brain = other._brain;
  
- Deep copy: a new independent copy of the resource is created. Each object has its own memory.

            this->brain = new Brain(*other._brain)

### Clases abstractas
--> clases abstractas: cuando tienen algún método virtual puro -> significa que la clase no implementa esa función y que son las clases derivadas las que la implementan.  
Cuándo es un método virtual puro?: cuando se declara con un = 0 al final y solo se implementa (es este el termino correcto?) en las clases derivadas.  
Qué significa que no se pueda instanciar una clase? Que no puedes instanciar directamente esa clase, es decir, no puedes hacer Animal a;
pero si puedes hacer:
Animal* pets[10];
pets[i] = new Dog();

Poner los constructores en protected es otra estrategia para evitar que la clase se pueda instanciar directamente, aunque no haya funciones puras. 

En una función polimórfica, el destructor ha de ser públic y virtual, para permitir delete polimórfico. 
- Si trabajamos con punteros a la base ...

El operador de asignación = y el constructor de copia no hace falta que sean protected. Una clase abstracta sigue pudiendo copiarse o asignarse mientras tengas una instancia válida, es decir, una clase hija concreta. Mejor que sean públicos, porque  las clases hijas concretas pueden necesitarlos. 

### Interfaces



### More info
