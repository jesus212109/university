#!/bin/bash

# Verificamos que se haya proporcionado un archivo de texto como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 <archivo_de_texto>"
    exit 1
fi

# Verificamos que el archivo exista
input_file="$1"
if [ ! -f "$input_file" ]; then
    echo "El archivo $input_file no existe."
    exit 1
fi

# Extraemos las palabras de las líneas que contienen números y las ordenamos
# Se busca cualquier línea que contenga al menos un número utilizando grep
# Luego, se convierten las palabras a minúsculas, se separan por líneas, se eliminan caracteres de espacio en blanco adicionales,
# se convierten letras con tildes a su equivalente sin tilde, se eliminan signos de puntuación al final de las palabras y se ordenan en orden inverso
#[:punct:]': Esto especifica una clase de caracteres que contiene todos los signos de puntuación. 
#'[:blank:]': Esto especifica una clase de caracteres que contiene espacios y tabulaciones
#Para convertir a mayusculas en el sed en vez de L, U de upper

#words=$(grep '[0-9]' "$input_file" | sed 's/\(.*\)/\L\1/' | sed 's/[[:blank:]]\+/\n/g' | sed 'y/áéíóúüÁÉÍÓÚÜ/aeiouuAEIOUU/' | sed -r 's/[0-9]+//' | sed 's/\.\.\.//'  | sed 's/[,.:]$//' | sort -r) 
words=$(grep '[0-9]' "$input_file" | tr -d '[:punct:]' | sed 's/\(.*\)/\L\1/' | sed 'y/áéíóúüÁÉÍÓÚÜ/aeiouuAEIOUU/' | tr -s '[:blank:]' '\n' | sed -r 's/[0-9]+//' | sort -r)

# Contamos las palabras y eliminamos duplicados
# Se cuentan las ocurrencias de cada palabra y se eliminan las repeticiones
unique_words=$(echo "$words" | uniq -c)

# Mostramos las palabras ordenadas por orden alfabético inverso
# Se muestra cada palabra con su recuento en orden numérico usando nl
echo -e "#   \tCount \tWord"
echo "$unique_words" | nl -w1

#----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#cat $1 | grep -E  "[0-9]" | sed -n -r "s/\.+//p" | sed "s/[[:punct:]]//g" | sed "s/[0-9]//g" | sed -n -r "s/^(.*)$/\L\1/p" | sed "s/ /\n/g" | sed "/^ *$/d" | sed 'y/áéíóúÁÉÍÓÚ/aeiouAEIOU/' | sort -r | uniq -c | nl
#funcion rarilla -> sed 'y/áéíóúÁÉÍÓÚ/aeiouAEIOU/' -> acordarse de la y!
#sed -> bandera x/g -> sustituyeme lo que te ponga por x (si x vacio por vacio).
#/p tiene que estar si o si el numero y ademas solo 1 ocurrencia /g sustituye y hasta N elementos





# Ej) /gp
# hola mundo
# adiós mundo

# Si queremos reemplazar todas las ocurrencias de la palabra "mundo" con "planeta" y luego imprimir las líneas modificadas, podemos usar sed de la siguiente manera:

# sed -n 's/mundo/planeta/gp' archivo.txt

# En este comando:

#     -n suprime la salida normal de sed.
#     s/mundo/planeta/g es el comando de sustitución que reemplaza todas las ocurrencias de "mundo" por "planeta".
#     /p indica que las líneas modificadas deben ser impresas.

# La salida de este comando sería:

# hola planeta
# adiós planeta

# Porque se han reemplazado todas las ocurrencias de "mundo" por "planeta" en cada línea, y la opción /p de sed imprime cada línea modificada.

