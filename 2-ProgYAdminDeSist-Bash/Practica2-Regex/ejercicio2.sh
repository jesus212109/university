#!/bin/bash

# Comprobar si se proporciona un nombre de archivo como argumento
if [ $# -ne 1 ]; then
    echo "Argumentos erroneos. Uso: $0 <fichero_peliculas>"
    exit 1
fi

archivo="$1"
output_file="peliculas_formateadas.txt"

# Verificar que el nombre del archivo sea correcto
if [ "$archivo" != "peliculas.txt" ]; then
    echo "Se esperaba un fichero del tipo peliculas.txt"
    exit 1
fi

# Eliminar líneas vacías, subrayados y formatear las películas

# sed '/^$/d; 
#     /^=/d;
#     /^ /d;
#     s/-.*-//;
#     s/^> \(.*\)$/Titulo: \1/
#     /^(.*)/s/^\(.*\)$/|->Fecha de estreno: \1/;
#     s/^Dirigida por \(.*$\)/|->Director: \1/;
#     s/^Reparto: \(.*$\)/|->Reparto: \1/;
#     s/^\(.hr ..min\)/|->Duración: \1/' "$archivo" | tee "$output_file"

# Las barras \ al final de cada linea es para mejorar legibilidad permitiendo tabulaciones
#\1 printea lo que halla entre parentesis y /p te da el resultado línea, es decir toda la linea menos el patrón modificado
cat "$archivo" | sed -r -n \
    -e 's/^>/Título:/p' \
    -e 's/(^\([^ ]+) .+$/| -> Fecha de estreno: \1/p' \
    -e 's/^Dirigida por (.+)/| -> Director: \1/p' \
    -e 's/^Reparto: (.+)/| -> Reparto: \1/p' \
    -e 's/(^[0-9]+hr [0-9]+min)/| -> Duración: \1/p' | tee peliculas_formateadas.txt
# sed -r EREs
# sed -n permite print (p)
# sed -r -n s/patron/reemplazo/p
# Con () puedes seleccionar parte del patron para usarlo como reemplazo con \1...\n

echo -e "\nFichero $output_file creado con exito\n"









# El comando `sed` (stream editor) es una poderosa herramienta de línea de comandos en Unix y sistemas basados en Unix, como Bash. Su función principal 
# es manipular y transformar flujos de texto de forma automatizada. Aquí tienes una explicación concisa de su uso:

# 1. **Sintaxis básica**:
#    La sintaxis básica del comando `sed` es:

#    sed [opciones] 'comando' archivo

# 2. **Comando**:
#    El `'comando'` es una serie de instrucciones que especifican qué transformaciones se deben aplicar al texto. Estas instrucciones pueden incluir operaciones 
#    como búsqueda y reemplazo, eliminación de líneas, inserción de texto, entre otras.

# 3. **Opciones**:
#    Algunas opciones comunes incluyen:
#    - `-e`: Permite especificar múltiples comandos sed en una sola línea de comando.
#    - `-i`: Realiza cambios en el archivo de entrada de forma directa, en lugar de mostrar la salida en la consola.
#    - `-r` (o `-E`): Habilita el uso de expresiones regulares extendidas en los comandos sed.

# 4. **Ejemplos**:
#    - `sed 's/patrón/reemplazo/' archivo.txt`: Busca el patrón en `archivo.txt` y lo reemplaza por el texto especificado.
#    - `sed -i 's/antiguo/nuevo/g' archivo.txt`: Realiza un reemplazo global de todas las ocurrencias de "antiguo" por "nuevo" en `archivo.txt`, modificando el archivo directamente.
#    - `sed '/patrón/d' archivo.txt`: Elimina todas las líneas que contienen el patrón especificado en `archivo.txt`.
#    - `sed -n '5,10p' archivo.txt`: Muestra solo las líneas del 5 al 10 de `archivo.txt`.