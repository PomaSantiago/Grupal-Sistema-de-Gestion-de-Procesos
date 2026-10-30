# Sistema de Gestión de Procesos

Proyecto de **Estructura de Datos** – Universidad Continental.

Simula la administración de procesos de un sistema operativo usando solo estructuras de datos dinámicas lineales implementadas desde cero (sin STL): lista enlazada, cola de prioridad y pila.

## Integrantes y responsabilidades

| Integrante | Usuario de GitHub | Parte |
|---|---|---|
| Poma Santiago Alex (líder) | PomaSantiago | Pila de memoria, utilidades, menú principal, diagramas y documentación |
| Doloriel Vargas Jhoel Ronaldo | (usuario) | Lista enlazada y menú de procesos |
| Nuñez Huaman Gerardo | (usuario) | Cola de prioridad y menú de CPU y memoria |
| Malpartida Zevallos John | (usuario) | Persistencia, pruebas y manual de usuario |

## Módulos

| Módulo | Estructura | Archivo | Responsable |
|---|---|---|---|
| Gestor de procesos | Lista enlazada simple | `proceso_lista.h`, `menu_procesos.h` | Jhoel |
| Planificador de CPU | Cola de prioridad enlazada | `cola_cpu.h` | Gerardo |
| Gestor de memoria (RAM) | Pila enlazada | `pila_memoria.h` | Alex |
| Menús de CPU y memoria | – | `menu_cpu_memoria.h` | Gerardo |
| Guardar y cargar estado | Archivo de texto | `persistencia.h` | John |
| Utilidades de lectura | – | `utilidades.h` | Alex |
| Menú principal | – | `main.cpp` | Alex |

## Cómo compilar y ejecutar (DEV C++)

1. Guardar todos los archivos `.h` y `main.cpp` en la misma carpeta.
2. Abrir `main.cpp` en DEV C++.
3. Compilar y ejecutar con **F11**.

El estado se guarda en `estado.txt`, en la misma carpeta del ejecutable.

## Estado del proyecto

- [x] Documento de diseño (Semana 1)
- [ ] Estructuras básicas (Semana 2)
- [ ] Funcionalidades completas y pruebas (Semana 3)
- [ ] Manual de usuario
