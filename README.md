
# 📚 Ordenamiento de 100,000 Palabras en C++

> Proyecto académico en C++ para comparar algoritmos y estructuras de datos aplicados al ordenamiento de grandes volúmenes de palabras.

---

## 🚀 Descripción

Este proyecto desarrolla un programa en **C++** capaz de ordenar **100,000 palabras** utilizando tres enfoques diferentes:

- **QuickSort**
- **HeapSort**
- **Árbol balanceado (AVL o Red-Black Tree)**

El objetivo es comparar su comportamiento en términos de:

- ⏱️ Tiempo de ejecución  
- 💾 Uso de memoria  
- 📈 Rendimiento práctico vs. complejidad teórica  

---

## 🎯 Objetivos

- Implementar algoritmos de ordenamiento **desde cero**
- Usar distintas estructuras de datos para resolver el mismo problema
- Comparar el desempeño de cada enfoque
- Analizar diferencias entre teoría y práctica

---

## 🗂️ Dataset

El conjunto de datos se genera a partir del archivo:

`words_alpha.txt`

A partir de él:

- Se seleccionan **100,000 palabras aleatorias**
- Se almacenan en `dataset.txt`

Este archivo sirve como entrada principal del programa.

---

## ⚙️ Algoritmos implementados

| Algoritmo / Estructura | Descripción | Característica principal |
|------------------------|-------------|--------------------------|
| **QuickSort** | Implementado desde cero con `std::vector` | Muy eficiente en promedio |
| **HeapSort** | Implementado desde cero con un **Binary Heap** | Ordenamiento basado en montículos |
| **Árbol balanceado** | Inserción en AVL o Red-Black Tree + recorrido inorder | Mantiene los datos ordenados dinámicamente |

---

## 🧠 Enfoques utilizados

### 🔹 QuickSort
Ordena las palabras alfabéticamente mediante la estrategia de **divide y vencerás**, usando un arreglo dinámico (`std::vector`).

### 🔹 HeapSort
Construye un **montículo binario** desde cero y luego extrae los elementos para obtener el resultado ordenado.

### 🔹 Árbol balanceado
Inserta las palabras en un árbol balanceado (**AVL o Red-Black Tree**), realiza un recorrido **inorder** y almacena el resultado en una lista ordenada.

---

## 🔍 Análisis del proyecto

Este proyecto permite estudiar cómo la elección del algoritmo o estructura de datos afecta el rendimiento al trabajar con grandes volúmenes de información.

Se comparan aspectos como:

- Tiempo de ejecución
- Uso de memoria
- Facilidad de implementación
- Comportamiento real frente a la complejidad teórica

---

## ✅ Conclusión

El proyecto demuestra que diferentes algoritmos y estructuras de datos pueden producir el mismo resultado, pero con costos computacionales distintos.

Comparar **QuickSort**, **HeapSort** y **árboles balanceados** permite comprender mejor sus ventajas, limitaciones y aplicaciones en escenarios reales.

---

## Aclaraciones

Se utilizo ayuda de claude ai para el desarrollo del proyecto, y chat gpt para organizar el README.md

---
## 👨‍💻 Autores

**Juan Esteban Grisales Restrepo**  
**Sofía Rojo Salazar**
