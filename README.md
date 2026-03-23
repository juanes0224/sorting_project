Descripción del proyecto

Este proyecto consiste en el desarrollo de un programa en C++ capaz de ordenar un conjunto grande de datos (100,000 palabras) utilizando tres estrategias diferentes basadas en estructuras de datos y algoritmos clásicos.

El objetivo principal es analizar el comportamiento de distintos algoritmos de ordenamiento cuando trabajan con grandes volúmenes de información, evaluando su rendimiento en términos de tiempo de ejecución y uso de memoria.

Objetivos 

Implementar algoritmos de ordenamiento desde cero.

Utilizar diferentes estructuras de datos para resolver el mismo problema.

Comparar el rendimiento de cada enfoque.

Analizar diferencias entre complejidad teórica y resultados prácticos.


Dataset

El programa utiliza un conjunto de datos generado a partir del archivo:
words_alpha.txt

A partir de este archivo se seleccionan 100,000 palabras aleatorias y se almacenan en un archivo llamado dataset.txt


Algoritmos Implementados

1. QuickSort (Arreglo dinámico)
Es implementado desde cero y utiliza std::vector<string>. Su función es ordenar las palabras alfabéticamente

2. HeapSort (Montículo binario)
Es implementado desde cero y se construye un Binary Heap. A partir del heap se obtiene el arreglo ordenado

3. Árbol Balanceado (AVL o Red-Black Tree)
En donde el proceso empieza por la inserción de las 100,000 palabras en el árbol, luego hace el recorrido inorder y por último almacena el resultado en una lista ordenada.


Conclusión 

Este proyecto permite evidenciar cómo diferentes estructuras de datos y algoritmos pueden influir en el rendimiento al trabajar con grandes volúmenes de información.

Autores

Juan Esteban Grisales
Sofía Rojo
