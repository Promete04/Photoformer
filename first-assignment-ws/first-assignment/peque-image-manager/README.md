# TinyImage
A tiny C/C++ image loading and saving library for graphics APIs.

///////// JMGM 2020-12-14
/*
A continuación se detalla la estructura de la cabecera de un fichero .BMP
Bytes 	Información
0, 1 	Tipo de fichero "BM"
2, 3, 4, 5 	Tamaño del archivo
6, 7 	Reservado
8, 9 	Reservado
10, 11, 12, 13 	Inicio de los datos de la imagen
14, 15, 16, 17 	Tamaño de la cabecera del bitmap
18, 19, 20, 21 	Anchura (píxels)
22, 23, 24, 25 	Altura (píxels)
26, 27 	Número de planos
28, 29 	Tamaño de cada punto
30, 31, 32, 33 	Compresión (0=no comprimido)
34, 35, 36, 37 	Tamaño de la imagen
38, 39, 40, 41 	Resolución horizontal
42, 43, 44, 45 	Resolución vertical
46, 47, 48, 49 	Tamaño de la tabla de color
50, 51, 52, 53 	Contador de colores importantes 

 *
 * */