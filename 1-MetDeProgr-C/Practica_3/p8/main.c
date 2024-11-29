// Escribe un programa que, dada una imagen de niveles de gris en formato  PGM, obtenga otra
// nueva   imagen   con   la   representación   de   la   imagen   original   en  negativo.   El   programa   recibirá
// como parámetros los nombres de las imágenes original y resultado.
// Un fichero PGM tiene un formato mixto texto-binario con cabecera:  
// La cabecera está en formato texto y consta de:
// ·Un número mágico para identificar el tipo de fichero. En nuestro caso, de imágenes de niveles de gris, tiene asignado la cadena “P5”.
// ·Un número indeterminado de comentarios marcados delante con #.  Los ejemplos que
// se dejan para probar el programa no contienen ningún comentario (no es necesario
// comprobar   si   existen   y   leerlos).   Si   se   utilizan   otros   ficheros   de   imágenes,   éstas
// pueden presentar comentarios en la cabecera.
// ·Dos enteros  c  y  f  que representan,  en este orden, el número de columnas y   filas,
// separados por un número indeterminado de espacios.
// ·Un entero con el valor del mayor nivel de gris que puede tener la imagen (m).
// ·Cada una de estas informaciones está terminada, por un salto de línea.
// El contenido de la imagen está en formato binario.
// oUna secuencia binaria de f x c unsigned char, con valores entre 0 y m. Cada uno
// de estos valores representa un nivel de gris de un pixel. La imagen se almacena por
// filas, es decir, el primer pixel es la esquina superior izquierda, el segundo el que está
// a su derecha, etc.
// En la imagen siguiente se muestra, a modo de ejemplo, como se almacena una imagen de 4 
// filas y 3 columnas en este formato:
// El fichero se abrirá en modo “wb”.
// Para visualizar las imágenes en Linux local puede utilizar gimp o eog cuya sintaxis es:
// Fila 0 Fila 1Fila 2 Fila 3
// (0,0) (0,1) (0,2) (1,0) (1,1) (1,2) (2,0) (2,1) (2,2) (3,0) (3,1) (3,2)
// P5\n
// #ejemplo de comentario\n
// 3 4\n
// 255\n
// eog <fichero con la imagen>
// El negativo es una operación píxel a píxel en la que se genera una imagen similar al negativo de
// una fotografía. Para ello:
// valorPixelNegativo=255-valorPixel 