Propuesta de Proyecto: Galería de Fotos Inteligente mediante Listas Doblemente Enlazadas

## Integrantes

* Hector Cuichan
* Odalys Chavez
* Morrison Quillupangui

**Grupo Asignado:** Grupo 1 (Listas doblemente enlazadas)  
**Asignatura:** Estructuras de Datos

## Definición del Problema Real

En la actualidad, las aplicaciones móviles y de escritorio para la visualización de medios (como galerías de fotos, carruseles de imágenes y reproductores multimedia) requieren una navegación bidireccional fluida y eficiente entre elementos.

Cuando un usuario revisa un álbum de fotos, realiza frecuentemente las siguientes acciones:
* Avanzar a la foto siguiente.
* Retroceder a la foto anterior.
* Insertar nuevas fotos al inicio, al final o en una posición específica de la secuencia.
* Eliminar la foto actualmente seleccionada sin perder la secuencia previa o posterior.

Si este sistema se implementara con un arreglo estático, las operaciones de inserción y eliminación requerirían reorganizar y desplazar continuamente los elementos en memoria, lo que resulta ineficiente. Por otro lado, una lista simplemente enlazada obligaría a recorrer la estructura desde el inicio cada vez que se desee retroceder a la foto anterior. 

Por lo tanto, existe la necesidad de diseñar e implementar una estructura de datos dinámica que optimice el almacenamiento de metadatos de las imágenes y garantice tiempos de respuesta óptimos ($O(1)$) para navegar hacia adelante y hacia atrás.

## Objetivo del Proyecto

Diseñar e implementar en C++ una aplicación de consola/interfaz visual para la gestión y navegación de una galería de fotos en tiempo real, utilizando el TDA de Lista Doblemente Enlazada Genérica con punteros dinámicos, garantizando el encapsulamiento de datos, la gestión transparente de la memoria y la separación estricta entre la lógica de la estructura y la interfaz de usuario.
