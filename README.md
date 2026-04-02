# 👨‍💻 Sobre este repositorio

Bienvenido a mi repositorio principal de **C++**. Contiene una ruta de aprendizaje estructurada y profunda del lenguaje, diseñada para escalar desde los conceptos básicos hasta las herramientas de más alto nivel del estándar **C++20**.

> 📚 **Bibliografía base:** El contenido de este repositorio está basándo fuertemente en *C++ Primer* y *Effective Modern C++* (Scott Meyers).

---

## 🗺️ La Ruta de Estudio

El aprendizaje está dividido en **cuatro grandes fases conceptuales**. Cada nivel construye sobre el anterior, pasando de la gestión manual de memoria a la abstracción moderna.

### 📌 Fase 1: Fundamentos y Memoria (Niveles 0 al 7)
*Basado en los conceptos centrales de C++ Primer.*

* **Nivel 0 - Fundamentos y Control de Flujo:** Transición desde C clásico al C++ moderno. Uso del namespace `std`, tipos nativos como `bool` y `string`, entrada/salida con `cin`/`cout`, y paso de parámetros por referencia.
* **Nivel 1 - POO Básica:** Clases, objetos, encapsulamiento (`public`/`private`), constructores (listas de inicialización y copia), y sobrecarga de operadores básica.
* **Nivel 2 - Punteros y Organización:** El puntero `this`, relaciones de composición, separación arquitectónica en `.h` y `.cpp`, gestión manual de memoria dinámica (`new`/`delete`), y la **Regla del Tres**.
* **Nivel 3 - Herencia y Polimorfismo:** Relación **"ES UN"**, miembros `protected`, funciones `virtual`, clases abstractas, y la obligatoriedad del destructor virtual.
* **Nivel 4 - C++ Moderno (Bases):** Adopción de `auto`, bucles *range-based*, introducción a **Smart Pointers** (`unique_ptr`, `shared_ptr`), Templates genéricos, Lambdas y Excepciones.
* **Nivel 5 - STL Profundo:** Dominio de contenedores de la *Standard Template Library* (`vector`, `list`, `map`, `set`, `stack`, `queue`), Iteradores y Algoritmos (`<algorithm>`, `<numeric>`).
* **Nivel 6 - C++11/14/17 Avanzado:** *Move Semantics*, *Rvalue References*, callbacks con `std::function`, evaluación en compilación con `constexpr`, *Structured Bindings* y la **Regla del Cinco**.
* **Nivel 7 - Concurrencia y Sistemas:** Manejo de archivos (`<fstream>`), cronometraje de precisión (`<chrono>`), y programación multihilo (`std::thread`, `std::mutex`, `std::async`).

### 📌 Fase 2: Abstracción y Diseño (Niveles 8 y 9)
*Basado en las características avanzadas de C++ Primer.*

* **Nivel 8 - Programación Genérica y Metaprogramación:** Especialización de templates (total y parcial), *Variadic Templates*, manipulación de tipos en compilación (*Type Traits*), y **SFINAE** (`enable_if`).
* **Nivel 9 - Patrones de Diseño:** Implementación de arquitecturas clásicas adaptadas a la filosofía de C++: **RAII** (Resource Acquisition Is Initialization), Singleton, Factory Method, Observer, Strategy y Decorator.

### 📌 Fase 3: Buenas Prácticas y C++11/14 (Niveles 10 y 11)
*Basado en "Effective Modern C++" de Scott Meyers.*

* **Nivel 10 - Deducciones de Tipos Avanzadas:** Las reglas sutiles detrás de `auto` y `decltype`, la importancia de usar `nullptr` sobre `NULL` o `0`, y las ventajas de `using` frente a `typedef`.
* **Nivel 11 - Rendimiento y Modernización Extrema:** Prevención de *memory leaks* con `std::weak_ptr` rompiendo ciclos de referencia, *Perfect Forwarding* con `std::forward`, optimizaciones garantizadas con `noexcept`, y uso avanzado de lambdas (genéricas, capturas por movimiento, y `mutable`).

### 📌 Fase 4: La Era de C++20 (Nivel 12)
*El estándar moderno y sus revoluciones arquitectónicas.*

* **Nivel 12 - El C++ Moderno Definitivo:**
    * **Concepts:** Creación de restricciones claras y legibles para templates, reemplazando SFINAE por validaciones directas.
    * **Ranges:** Procesamiento declarativo y perezoso (*lazy evaluation*) de secuencias de datos usando el operador pipe (`|`).
    * **Coroutines:** Funciones pausables (`co_yield`, `co_await`, `co_return`) para generadores y programación asíncrona de alto rendimiento.
    * **Views & Formatting:** Manejo de `std::span` para observar memoria de forma segura sin realizar copias, y formateo moderno de strings con `std::format`.
    * **Spaceship Operator:** Uso de `<=>` (*Three-way comparison*) para generar automáticamente todos los operadores de comparación.
