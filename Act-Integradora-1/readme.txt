Actividad: Act-Integradora-1
Autor:
Miguel Arriaga - A01028570 - CSF

Instrucciones para compilar y ejectuar el código:
Este programa tiene como objetivo ordenar y buscar información de una bitácora.
El programa está compuesto de 5 archivos. Tres archivos "header", que contienen la declaración e implementación de 
las clases, "Fecha", "Registro" y "Bitacora". El cuarto archivo es "main.cpp" y es el archivo en dónde se inicializan los 
objetos tipo "Bitacora" y se utilizan los algoritmos de ordenamiento y búsqueda para ordenar la bitacora y buscar un rango de fechas.
Más información sobre los métodos de las clases y su funcionamiento se puede encontrar en el archivo "ReflexActIntegradora1.pdf". Finalmente,
se incluye el archivo "bitacora.txt", que es la base se datos que se busca ordenar. Esta no es necesaria para el programa y 
éste es capaz de ordenar otras bases de datos con la misma estructura, cambiando el parámetro del constructor del objeto tipo
Bitacora.

Para compilar el programa, se debe de acceder al archivo "main.cpp". Dependiendo del IDE en el que se esté trabajando, se
puede compilar y correr el código con alguna extensión (boton) o directamente desde la consola con los siguientes comandos:
g++ main.cpp -o main : compila tú programa con nombre main
./main.out - corre el programa

El resultado de main.cpp es la creación de do archivos: "mergeSort.txt" y "quickSort.txt", que contienen a la bitacora ya ordenada,
cada uno por su respectivo algoritmo de ordenamiento. Además, se imprimirá en pantalla el tiempi en ms que tardó en ordenar a la bitácora 
cada algoritmo. Posteriormente se imprimirá el resultado de una búsqueda binaria de ejemplo, para la fecha del 9 
de Julio a las 16:19:58. Finalmente, se llama al método pideUsuario(), pregintandole al usuario una fecha inicial y una fecha final, primero 
se pregunta el mes, que debe de estar en formato de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec). Posteriormente,
se pregunta la hora, que debe de estar en el formato 00:00:00. En donde (Hora:Minuto:Segundo). Es importante recalcar
que para que el programa funcione corretamente, se deben introducir las fechas de manera exacta, de otra manera el programa 
imprimirá que las fechas introducidas no se encontraron.

Un ejemplo del resultado en consola de la ejecución correcta del programa se muestra a continuación:

QUICK SORT: 
Tiempo de ejecución en ms: 2801

MERGE SORT: 
Tiempo de ejecución en ms: 3629

BINARY SEARCH: 
4406
Tiempo de ejecución en ms: 0

PIDE USUARIO (DOS BÚSQUEDAS BINARIAS): 
Introduce la fecha de inicio 
Mes en código de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): 
Jun
Número de día: 
1
Hora en formato 00:00:00
00:49:31
Introduce la fecha de fin 
Mes en código de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): 
Jun
Número de día: 
1
Hora en formato 00:00:00
18:41:47
Las fechas en ese rango son:
Jun 01 00:49:31 15.113.211.66:1795 Failed password for illegal user root
Jun 01 00:59:02 159.72.70.232:99 Failed password for illegal user guest
Jun 01 01:06:03 65.57.18.239:1163 Failed password for illegal user root
Jun 01 01:18:39 168.51.35.137:512 Illegal user
Jun 01 01:22:22 123.81.238.176:9497 Failed password for illegal user root
Jun 01 01:23:03 249.27.6.194:7341 Failed password for illegal user guest
Jun 01 01:34:06 246.21.58.234:2986 Illegal user
Jun 01 01:52:37 111.89.38.165:1772 Failed password for illegal user guest
Jun 01 02:04:02 244.67.92.254:8034 Failed password for illegal user guest
Jun 01 02:10:33 186.115.187.178:7655 Failed password for illegal user root
Jun 01 02:10:34 234.204.180.48:3154 Failed password for admin
Jun 01 02:18:16 89.52.87.155:4329 Failed password for illegal user guest
Jun 01 02:18:20 128.47.216.109:6740 Failed password for illegal user root
Jun 01 02:29:09 122.135.158.172:1461 Failed password for illegal user guest
Jun 01 02:37:14 129.84.230.64:1135 Failed password for illegal user root
Jun 01 02:49:11 12.12.202.218:2548 Illegal user
Jun 01 03:23:38 88.171.169.174:6369 Failed password for admin
Jun 01 03:27:20 56.15.203.204:6494 Failed password for illegal user guest
Jun 01 03:33:55 22.109.15.199:868 Failed password for illegal user guest
Jun 01 03:34:02 13.60.65.222:2326 Failed password for illegal user root
Jun 01 03:47:00 202.112.127.217:1970 Failed password for illegal user guest
Jun 01 03:52:12 130.136.119.233:9222 Illegal user
Jun 01 03:54:52 57.134.210.237:2310 Failed password for illegal user guest
Jun 01 03:55:27 252.120.15.197:1819 Failed password for admin
Jun 01 04:04:27 49.231.173.75:8966 Failed password for illegal user root
Jun 01 04:06:11 238.56.243.235:4244 Failed password for illegal user guest
Jun 01 04:14:55 194.182.219.58:692 Failed password for admin
Jun 01 04:18:08 85.198.80.74:9438 Failed password for illegal user guest
Jun 01 04:21:48 196.71.136.156:3305 Failed password for admin
Jun 01 04:41:46 12.207.97.106:1495 Illegal user
Jun 01 04:46:57 200.35.230.207:794 Failed password for admin
Jun 01 05:04:35 49.90.77.91:3583 Illegal user
Jun 01 05:30:59 20.242.129.33:9522 Illegal user
Jun 01 05:46:25 95.51.44.141:5723 Failed password for admin
Jun 01 05:55:33 156.169.34.118:3672 Failed password for illegal user guest
Jun 01 06:02:16 97.211.87.171:79 Failed password for illegal user guest
Jun 01 06:38:34 51.99.55.241:412 Failed password for illegal user root
Jun 01 06:46:16 142.235.96.123:5402 Failed password for illegal user guest
Jun 01 07:15:36 143.106.150.139:3028 Failed password for admin
Jun 01 08:04:31 212.175.23.31:9904 Failed password for illegal user guest
Jun 01 08:15:33 126.3.164.87:2407 Failed password for illegal user guest
Jun 01 08:20:27 53.198.233.139:6880 Illegal user
Jun 01 08:23:57 11.105.45.36:4225 Failed password for admin
Jun 01 08:43:04 76.75.115.27:500 Failed password for admin
Jun 01 08:46:02 181.119.225.74:1471 Failed password for admin
Jun 01 09:00:50 46.131.67.221:2717 Failed password for admin
Jun 01 09:03:25 128.131.187.27:5534 Failed password for illegal user root
Jun 01 09:10:45 11.65.103.18:3202 Failed password for illegal user guest
Jun 01 09:20:38 48.222.230.219:8500 Failed password for illegal user root
Jun 01 09:34:28 62.214.215.81:2862 Illegal user
Jun 01 09:36:33 106.8.62.135:1020 Failed password for illegal user guest
Jun 01 09:50:46 2.45.241.36:7388 Failed password for illegal user root
Jun 01 10:02:36 215.84.202.93:3846 Failed password for admin
Jun 01 10:05:35 88.58.137.243:2158 Illegal user
Jun 01 10:09:21 147.163.74.109:7006 Failed password for illegal user root
Jun 01 10:09:53 102.114.4.250:6898 Illegal user
Jun 01 10:24:58 161.82.210.15:2605 Failed password for illegal user guest
Jun 01 10:30:22 189.125.131.40:9939 Failed password for illegal user guest
Jun 01 10:49:32 195.157.206.74:646 Failed password for admin
Jun 01 11:03:39 163.83.79.107:3432 Failed password for illegal user guest
Jun 01 11:19:06 88.43.66.161:8432 Failed password for illegal user guest
Jun 01 11:36:38 105.195.245.206:3632 Failed password for illegal user guest
Jun 01 11:42:19 173.228.119.191:9094 Failed password for admin
Jun 01 11:44:21 58.153.1.17:1262 Failed password for illegal user guest
Jun 01 11:58:30 227.204.48.150:3813 Illegal user
Jun 01 12:09:18 90.39.10.103:2028 Failed password for illegal user root
Jun 01 12:11:09 4.63.160.140:9302 Failed password for illegal user guest
Jun 01 12:11:31 83.57.147.84:9095 Failed password for illegal user guest
Jun 01 12:26:51 50.144.204.201:267 Failed password for illegal user root
Jun 01 12:31:41 151.25.187.246:2023 Failed password for illegal user root
Jun 01 12:42:00 187.210.203.117:1555 Failed password for illegal user guest
Jun 01 13:04:21 126.252.52.115:1145 Failed password for illegal user guest
Jun 01 13:06:33 246.28.161.83:5503 Failed password for illegal user guest
Jun 01 13:24:42 179.167.222.251:8989 Failed password for illegal user guest
Jun 01 14:04:52 59.115.211.238:2868 Failed password for illegal user root
Jun 01 14:23:00 30.138.250.204:3871 Failed password for illegal user guest
Jun 01 14:29:33 70.103.12.61:1107 Failed password for illegal user guest
Jun 01 14:37:39 87.235.61.59:6789 Illegal user
Jun 01 14:45:31 26.216.30.113:5060 Failed password for illegal user guest
Jun 01 14:48:43 99.126.216.77:7944 Illegal user
Jun 01 15:10:31 222.241.55.80:7891 Failed password for admin
Jun 01 15:41:12 161.236.225.106:9785 Failed password for admin
Jun 01 16:10:20 95.204.134.124:8619 Failed password for illegal user root
Jun 01 16:39:47 1.96.237.110:7486 Failed password for illegal user guest
Jun 01 16:40:41 200.39.252.219:2853 Illegal user
Jun 01 16:46:02 134.76.53.249:6127 Failed password for admin
Jun 01 16:46:24 47.227.2.166:2147 Failed password for illegal user guest
Jun 01 17:06:25 190.178.208.110:8189 Failed password for illegal user guest
Jun 01 17:15:41 34.156.100.46:5258 Failed password for illegal user guest
Jun 01 17:33:08 69.145.13.4:1377 Illegal user
Jun 01 17:41:17 22.90.21.157:2909 Failed password for illegal user root
Jun 01 17:42:37 28.45.32.253:7299 Failed password for admin
Jun 01 18:12:11 159.168.180.162:4606 Failed password for illegal user root
Jun 01 18:25:55 192.58.247.36:8326 Failed password for illegal user guest
Jun 01 18:41:47 214.253.174.41:1518 Failed password for illegal user guest
