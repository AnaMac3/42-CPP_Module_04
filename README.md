# 42-CPP_Module_04
42 Common Core CPP Module 02.  
- Object-Oriented Programming in C++
- Polymorphism

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

--> deep copy para que cada objeto de clase hija tenga su objeto Brain independiente?¡
deep copy: 

--> clases abstractas: cuando tienen algún método virtual puro -> significa que la clase no implementa esa función y que son las clases derivadas las que la implementan. 
Qué significa que no se pueda instanciar una clase? Que no puedes hacer Animal a;
pero si puedes hacer:
Animal* pets[10];
pets[i] = new Dog();

