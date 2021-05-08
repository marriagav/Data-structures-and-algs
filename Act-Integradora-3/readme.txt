
Actividad: Act-Integradora-3
Autor:
Miguel Arriaga - A01028570 - CSF

Instrucciones para compilar y ejectuar el código:
Este programa tiene como objetivo ordenar y buscar información de una bitácora.
El programa está compuesto de 6 archivos. Tres archivos "header", que contienen la declaración e implementación de 
las clases: "IpHeap","IpAdress", "Fecha", "Registro" y "Bitacora". El cuarto archivo es "main.cpp" y es el archivo en dónde se inicializan los 
objetos tipo "Bitacora" y "IpHeap" y se utiliza el heap sort para ordenar la bitacora y obtener los 5 ips con más accesos.
Finalmente, se incluye el archivo "bitacoraHeap.txt", que es la base se datos que se busca ordenar. Esta no es necesaria para el programa y 
éste es capaz de ordenar otras bases de datos con la misma estructura, cambiando el parámetro del constructor del objeto tipo
Bitacora.

Para compilar el programa, se debe de acceder al archivo "main.cpp". Dependiendo del IDE en el que se esté trabajando, se
puede compilar y correr el código con alguna extensión (boton) o directamente desde la consola con los siguientes comandos:
g++ main.cpp -o main : compila tú programa con nombre main
./main.out - corre el programa

El resultado de main.cpp es la creación de dos archivos: "bitacoraHeap_ordenada.txt", que contiene a la bitácora ya ordenada por IPs ascendientemente. 
Además, se imprimirá en pantalla el tiempo en ms que tardó en ordenar a la bitácora. 
Posteriormente, se creara otro archivo llamado "IPs_ordenados_por_accesos.txt", que contine a los diferentes IPs
que se encuentran en la bitácora ordenados descendiencemente por cantidad de accesos, además de cuántos accesos tiene cada uno.
Finalmente, se imprimirá en consola a los 5 IPs con más accesos.

Un ejemplo del resultado en consola de la ejecución correcta del programa se muestra a continuación:

HEAP SORT DE IPs: 
Ordenando la Bitacora...
Tiempo de ejecución en ms: 3034

HEAP SORT POR ACCESOS: 
Ordenando las IPs por número de accesos...
Tiempo de ejecución en ms: 0

5 IPs CON MÁS ACCESOS (IP - NO. DE ACCESOS): 
10.15.176.241 - 38
10.15.187.246 - 38
10.15.176.230 - 37
10.15.177.224 - 37
10.15.183.241 - 37

