# C++ Module 05 -- Explicación de Ejercicios (ex00--ex03)

Este documento resume qué pide cada ejercicio del módulo 05 de C++ en 42
y qué conceptos se espera que aprendas.

------------------------------------------------------------------------

# EX00 -- "Mom, when I grow up I want to be a bureaucrat"

## Objetivo

Crear una clase **Bureaucrat** que represente a un burócrata con un
nombre y un rango.

## Atributos

La clase debe tener:

-   `const std::string name`
-   `int grade`

### Significado

-   **name** → nombre del burócrata
-   **grade** → rango del burócrata

## Sistema de rangos

  Grade   Significado
  ------- ----------------
  1       rango más alto
  150     rango más bajo

Importante: **un número menor significa mayor poder**.

## Restricciones

Si el rango está fuera del intervalo:

-   `< 1` → lanzar `GradeTooHighException`
-   `> 150` → lanzar `GradeTooLowException`

Esto debe comprobarse:

-   en el constructor
-   al modificar el grade

## Métodos obligatorios

### Getters

-   `getName()`
-   `getGrade()`

### Subir rango

    incrementGrade()

Reduce el número del grade:

    grade--

Si intenta pasar de **1**, lanzar excepción.

### Bajar rango

    decrementGrade()

Aumenta el número del grade:

    grade++

Si intenta pasar de **150**, lanzar excepción.

## Excepciones

Debes crear dos clases:

-   `GradeTooHighException`
-   `GradeTooLowException`

Ambas deben heredar de:

    std::exception

Y sobrescribir:

    what()

## Operador \<\<

Debes sobrecargar:

    std::ostream& operator<<(std::ostream&, const Bureaucrat&);

Salida esperada:

    Bob, bureaucrat grade 42

## Conceptos que se aprenden

-   clases en C++
-   manejo de excepciones
-   sobrecarga de operadores

------------------------------------------------------------------------

# EX01 -- Form

## Objetivo

Crear una clase **Form** que puede ser firmada por un **Bureaucrat**.

Esto introduce interacción entre clases.

## Atributos

    const std::string name
    bool isSigned
    const int gradeSign
    const int gradeExecute

### Significado

-   **name** → nombre del formulario
-   **isSigned** → indica si está firmado
-   **gradeSign** → rango mínimo para firmar
-   **gradeExecute** → rango mínimo para ejecutar

## Método importante

    beSigned(Bureaucrat&)

Este método permite que un burócrata firme el formulario.

### Regla

Si el grade del burócrata es demasiado bajo → lanzar excepción.

## Nueva función en Bureaucrat

    signForm(Form&)

Esta función intenta firmar un formulario y muestra un mensaje indicando
si lo consiguió o no.

## Conceptos que se aprenden

-   relaciones entre clases
-   delegar responsabilidades
-   reutilizar excepciones

------------------------------------------------------------------------

# EX02 -- AForm y formularios concretos

## Objetivo

Convertir **Form** en una **clase abstracta** llamada **AForm** y crear
formularios específicos.

## Formularios que debes crear

### 1. ShrubberyCreationForm

Cuando se ejecuta:

-   crea un archivo
-   escribe un árbol ASCII dentro

Nombre del archivo:

    <target>_shrubbery

------------------------------------------------------------------------

### 2. RobotomyRequestForm

Cuando se ejecuta:

-   hace ruido de taladro
-   tiene **50% de éxito**

Salida típica:

    Bzzzzzz...
    Target has been robotomized successfully

o

    Robotomy failed

------------------------------------------------------------------------

### 3. PresidentialPardonForm

Cuando se ejecuta:

    <target> has been pardoned by Zaphod Beeblebrox

------------------------------------------------------------------------

## Cambios importantes

Ahora `execute()` es:

    virtual void execute(Bureaucrat const & executor) const = 0;

Esto convierte `AForm` en **clase abstracta**.

## Conceptos que se aprenden

-   herencia
-   polimorfismo
-   clases abstractas
-   funciones virtuales

------------------------------------------------------------------------

# EX03 -- Intern

## Objetivo

Crear una clase **Intern** capaz de generar formularios automáticamente.

Esto simula una **fábrica de objetos**.

## Función principal

    AForm* makeForm(std::string name, std::string target);

El intern debe crear el formulario correcto dependiendo del nombre.

## Formularios válidos

  Nombre                Formulario creado
  --------------------- ------------------------
  shrubbery creation    ShrubberyCreationForm
  robotomy request      RobotomyRequestForm
  presidential pardon   PresidentialPardonForm

Si el nombre no existe:

    Intern cannot create this form

## Concepto aprendido

Este ejercicio introduce una versión simple del **Factory Pattern**.

Un objeto decide **qué clase instanciar en tiempo de ejecución**.

------------------------------------------------------------------------

# Resumen del módulo

Este módulo enseña:

-   excepciones
-   clases abstractas
-   herencia
-   polimorfismo
-   interacción entre clases
-   patrones de creación básicos (factory)
