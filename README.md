# Sistema de Gestion de Procesos

Proyecto de **Estructura de Datos** - Universidad Continental.

Simula la administracion de procesos de un sistema operativo usando solo estructuras de datos dinamicas lineales implementadas desde cero (sin STL): lista enlazada, cola de prioridad y pila.

## Integrantes y responsabilidades

| Integrante | Usuario de GitHub | Parte |
|---|---|---|
| Poma Santiago Alex | PomaSantiago | Pila de memoria, utilidades, menu principal, diagramas y documentacion |
| Doloriel Vargas Jhoel Ronaldo | Dolo25 | Lista enlazada y menu de procesos |
| Nunez Huaman Gerardo | 70955967-ai | Cola de prioridad y menu de CPU y memoria |
| Malpartida Zevallos John | CINA-code | Persistencia, pruebas y manual de usuario |

## Modulos

| Modulo | Estructura | Archivo | Responsable |
|---|---|---|---|
| Gestor de procesos | Lista enlazada simple | `proceso_lista.h`, `menu_procesos.h` | Jhoel |
| Planificador de CPU | Cola de prioridad enlazada | `cola_cpu.h` | Gerardo |
| Gestor de memoria (RAM) | Pila enlazada | `pila_memoria.h` | Alex |
| Menus de CPU y memoria |  | `menu_cpu_memoria.h` | Gerardo |
| Guardar y cargar estado | Archivo de texto | `persistencia.h` | John |
| Utilidades de lectura |  | `utilidades.h` | Alex |
| Menu principal |  | `main.cpp` | Alex |

## Como compilar y ejecutar (DEV C++)

1. Guardar todos los archivos `.h` y `main.cpp` en la misma carpeta.
2. Abrir `main.cpp` en DEV C++.
3. Compilar y ejecutar con **F11**.

El estado se guarda en `estado.txt`, en la misma carpeta del ejecutable.

## Estado del proyecto

- [x] Documento de diseno (Semana 1)
- [x] Estructuras basicas (Semana 2)
- [ ] Funcionalidades completas y pruebas (Semana 3)
- [ ] Manual de usuario
