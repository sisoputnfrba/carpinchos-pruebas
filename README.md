# Carpinchos de prueba

Dentro de este repositorio se van a encontrar con los archivos `*.c` 
correspondientes a los carpinchos.

Dentro del repositorio se encuentra un archivo makefile que tiene los siguientes
objetivos:

## `compile`

Este objetivo va a generar los carpinchos a ejecutar dentro del directorio 
build.

Es muy importante haber realizado **una** de estas dos acciones antes de 
ejecutarlo:

a. Copiar el archivo `*.so` que se genera al compilar matelib en **uno** de los
directorios donde el compilador va a buscar las bibliotecas compartidas:
```
/usr/local/lib
/usr/lib
/lib
```
💡 ¡Deberás contar con permisos de `root` para poder copiarlo!

b. Agregar el directorio donde se encuentra el archivo `*.so` a las variables 
de entorno:

- `LIBRARY_PATH`, para que `gcc` las incluya al compilar; y
- `LD_LIBRARY_PATH`, para que se vinculen al momento de ejecutar cada 
carpincho.

Se puede setear el valor de una variable de entorno ingresando por consola 
el comando `export`. Para ingresar varios valores, se deben separar usando `:`.
Ejemplo:

```
export LIBRARY_PATH=$LIBRARY_PATH:/home/utnso/tp-2021-2c-ayudantes/matelib/bin
```

💡 `export` solamente setea esa variable para la terminal actual y todos los 
comandos que ésta ejecute. Podés setear su valor permanentemente agregando 
esa línea al final del script `~/.bashrc`, el cual se ejecuta antes de iniciar
cualquier consola `bash`.

💡 También podés verificar el valor de cualquier variable de entorno mediante
el comando `printenv`:

```
$ printenv LIBRARY_PATH
/home/utnso/tp-2021-2c-ayudantes/matelib/bin
```

## `clean`

Este objetivo elimina todos los carpinchos compilados por el comando 
`compile`.


