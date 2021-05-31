Actividad: Act-Integradora-3
Autor:
Miguel Arriaga - A01028570 - CSF

Instrucciones para compilar y ejectuar el código:
Este programa tiene como objetivo ordenar y buscar información de una bitácora.
El programa está compuesto de varios archivos. Cuatro archivos "header", que contienen la declaración e implementación de 
las clases: "heap","ipNode","bitacoraGraph" y "hash.h". El quinto archivo es "main.cpp" y es el archivo en dónde se inicializa el 
objeto tipo "Bitacoragraph" y se utiliza el heap sort para ordenar la bitacora y obtener los 5 ips con más conexiones.
Finalmente, se incluye el archivo "bitacoraGrafos.txt", que es la base se datos que se busca ordenar. Esta no es necesaria para el programa y 
éste es capaz de ordenar otras bases de datos con la misma estructura, cambiando el parámetro del constructor del objeto tipo
BitacoraGraph.

Para compilar el programa, se debe de acceder al archivo "main.cpp". Dependiendo del IDE en el que se esté trabajando, se
puede compilar y correr el código con alguna extensión (boton) o directamente desde la consola con los siguientes comandos:
g++ main.cpp -o main : compila tú programa con nombre main
./main - corre el programa

El resultado de main.cpp es la creación de tres archivos: "Grafo Bitácora.txt", que contiene a la lista de adyacencia con cada Ip, 
seguida de sus Ips adyacentes. Posteriormente, se creara otro archivo llamado "Bitácora por conexiones.txt", que contine a los diferentes IPs
que se encuentran en la bitácora ordenados descendiencemente por número de conexiones, además de cuántos accesos tiene cada uno.
También e archivo "Mapa.txt", que contiene el hashmap.
Finalmente, se imprimirá en consola a los 5 IPs con más conexiones.

Un ejemplo del resultado en consola de la ejecución correcta del programa se muestra a continuación:

No Duplicate keys
0
Primeras 5 ips que más conexiones tienen:
73.89.221.25 -> 18
185.109.34.183 -> 18
219.75.168.78 -> 17
220.210.239.189 -> 17
115.157.160.175 -> 17
La lista de adyacencia se puede encontrar en el archivo: Grafo Bitácora.txt
El resto de las ips ordenadas por conexiones se pueden encontrar en el archivo: Bitácora por conexiones.txt
El mapa se puede encontar en el archivo: Mapa.txt