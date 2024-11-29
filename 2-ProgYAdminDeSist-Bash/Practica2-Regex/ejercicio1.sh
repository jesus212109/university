#!/bin/bash

# Comprobar si se proporciona un nombre de archivo como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 <nombre_del_archivo>"
    exit 1
fi

archivo="$1"

# 1. Mostrar el título de las películas que tengan una longitud de 4 palabras.
echo -e "\nTítulos de películas con 4 palabras:"
#egrep '^> .+ .+ .+ .+$' "$archivo"
egrep '^> [^ ]+ [^ ]+ [^ ]+ [^ ]+$' "$archivo"

# 2. Mostrar las duraciones de películas que sean superiores a 1h 45min.    Suponiendo que ninguna pelicula dura mas de 3h
echo -e "\nDuraciones de películas superiores a 1h 45min:"
cat $archivo | egrep '^[0-9]+hr [0-9]+min$' | egrep '(^1hr (4[5-9])|(5[0-9]))|(^2hr [0-5][0-9])min$' 

# 3. Contar cuántas películas hay de cada país, suponiendo que el país siempre está encerrado entre guiones.
echo -e "\nNúmero de películas por país:"
egrep -o "\-.+\-" "$archivo" | sort | uniq -c # sort|uniq -c te hace el conteo y te ordena automaticamente por mayor catidad de repeticiones

# 4. Mostrar aquellas palabras que contengan la letra “d”,“l” o “t”, una vocal y la misma letra.
echo -e "\nPalabras que contienen 'd', 'l' o 't', una vocal y la misma letra:"
egrep -o '[^ ]*([dlt])[aeiou]\1[^ ]* ' "$archivo"   #Muy útil siempre que quiera palabras

# 5. Mostrar todas aquellas líneas que terminen con 3 puntos (“...”) y no empiecen por espacio, utilizando el operador de repetición {}.
echo -e "\nLíneas que terminan con '...' y no empiezan por espacio:"
#egrep -o '^[^ ].*\.\.\.$' "$archivo"
egrep -o '^[^ ].*\.{3,3}$' "$archivo"










# El comando `grep` es una herramienta de búsqueda muy útil en sistemas Unix y en el intérprete de comandos Bash. Su función principal es buscar patrones en archivos de texto o en la salida de otros comandos.

# Aquí tienes una explicación básica de cómo funciona `grep`:           <PARA USAR LAS REDEX EXTENDIDAS PODEMOS USAR egrep SIEMPRE en vez de grep>

# 1. **Sintaxis básica**:
#    El formato básico de uso del comando `grep` es:
#    grep [opciones] patrón [archivos...]

# 2. **Patrón**:
#    El "patrón" es la cadena de texto que `grep` buscará en los archivos o en la entrada de texto. Puede ser una palabra simple, una expresión regular más compleja, o una cadena de caracteres.

# 3. **Opciones**:
#    `grep` tiene varias opciones que permiten personalizar la búsqueda. Algunas de las opciones más comunes son:
#    - `-i`: Realiza la búsqueda de manera insensible a mayúsculas y minúsculas.
#    - `-r` (o `-R`): Realiza una búsqueda recursiva en subdirectorios.
#    - `-n`: Muestra el número de línea junto con la salida que coincide.
#    - `-v`: Invierte la búsqueda, mostrando las líneas que no coinciden con el patrón.
#    - `-e patrón`: Permite especificar un patrón utilizando expresiones regulares.
#    - `-l`: Muestra solo los nombres de los archivos que contienen coincidencias, en lugar de las líneas coincidentes.
#    - `-c`: Muestra solo el número de líneas coincidentes, en lugar de las líneas en sí.   IMPORTANTE

# 4. **Archivos**:
#    Puedes especificar uno o más archivos en los cuales `grep` buscará el patrón. Si no se especifica ningún archivo, `grep` buscará en la entrada estándar (por ejemplo, la salida de otro comando).

# 5. **Ejemplos**:
#    - `grep "patrón" archivo.txt`: Busca el patrón en el archivo `archivo.txt`.
#    - `grep -i "patrón" archivo1.txt archivo2.txt`: Realiza una búsqueda insensible a mayúsculas y minúsculas en los archivos `archivo1.txt` y `archivo2.txt`.
#    - `grep -r "patrón" directorio`: Busca de manera recursiva en el directorio y sus subdirectorios.
#    - `ps aux | grep "proceso"`: Busca el patrón "proceso" en la salida del comando `ps aux`, que muestra información sobre procesos en ejecución.

# En resumen, `grep` es una herramienta poderosa y versátil para buscar patrones en archivos de texto y en la salida de otros comandos en el entorno de Bash.