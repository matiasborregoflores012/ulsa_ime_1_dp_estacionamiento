Simulador de Acceso a Estacionamiento
Este proyecto es un simulador sencillo de estacionamiento escrito en C++.
Permite:

Entrada de vehículos por tipo (COMPACTO, SEDAN, SUV).
Asignación automática de lugares disponibles.
Salida de vehículos indicando el número de lugar (ejemplo: SUV01).
Mostrar el estado general y porcentaje de ocupación.
Requisitos
Windows (MSYS2 + MinGW-w64)
Instalar MSYS2.
Abrir la terminal MSYS2 UCRT64.
Instalar el compilador:
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain

verificar la instalacion

g++ --version
macOS (Xcode CLI)
Instalar herramientas de línea de comandos:
xcode-select --install

Verificar instalación:
g++ --version

Compilacion y ejecucion windows
cd src g++ programa.h.cpp -o programa.h.cpp .\programa.exe
Compilacion y ejecucion macOS
cd src g++ programa.h.cpp -o programa.h.cpp .\programa
ejemplo de uso
Bienvenido al Simulador de Acceso a Estacionamiento Ingrese el tamaño del vehiculo para entrada (COMPACTO, SEDAN, SUV) o el numero de lugar para la salida (ej. SUV01) Escriba SALIR para terminar

SUV Vehiculo aceptado. Lugar asignado: SUV01
