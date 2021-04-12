
Actividad: Act-Integradora-2
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

NOTA: ES POSIBLE QUE LA PRIMERA VEZ QUE SE CORRA EL CÓDIGO ARROJE UN "SEGMENTATION FAULT", A PARTIR DE LA SEGUNDA CORRIDA DEBERÍA DE FUNCIONAR
CORRECTAMENTE.

Para compilar el programa, se debe de acceder al archivo "main.cpp". Dependiendo del IDE en el que se esté trabajando, se
puede compilar y correr el código con alguna extensión (boton) o directamente desde la consola con los siguientes comandos:
g++ main.cpp -o main : compila tú programa con nombre main
./main.out - corre el programa

El resultado de main.cpp es la creación de do archivos: "bitacora_ordenada.txt", que contiene a la bitácora ya ordenada por quickSort. Además, se imprimirá en pantalla el tiempi en ms que tardó en ordenar a la bitácora
. Posteriormente se imprimirá el resultado de una búsqueda binaria de ejemplo, para la fecha del 9 
de Julio a las 16:19:58. Finalmente, se llama al método pideUsuario(), pregintandole al usuario una fecha inicial y una fecha final, primero 
se pregunta el mes, que debe de estar en formato de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec). Posteriormente,
se pregunta la hora, que debe de estar en el formato 00:00:00. En donde (Hora:Minuto:Segundo). Es importante recalcar
que para que el programa funcione corretamente, se deben introducir las fechas de manera exacta, de otra manera el programa 
imprimirá que las fechas introducidas no se encontraron. El resultado de la búsqueda se encuentra en el archivo "resultado_busqueda.txt"

Un ejemplo del resultado en consola de la ejecución correcta del programa se muestra a continuación:

QUICK SORT: 
Ordenando la Bitacora, puede tomar unos minutos...
Tiempo de ejecución en ms: 50220


BINARY SEARCH: 
4406
Tiempo de ejecución en ms: 3

PIDE USUARIO (DOS BÚSQUEDAS BINARIAS): 
Introduce la fecha de inicio 
Mes en código de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): 
Jun 
Número de día: 
01
Hora en formato 00:00:00
00:22:36
Introduce la fecha de fin 
Mes en código de tres letras (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): 
Jun
Número de día: 
01
Hora en formato 00:00:00
02:37:14
Resultado de la búusqueda en archivo resultado_busqueda.txt
