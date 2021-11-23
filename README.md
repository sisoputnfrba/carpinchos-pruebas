# Carpinchos de prueba

Dentro de este repositorio se van a encontrar con los archivos `*.c` 
correspondientes a los carpinchos.

Dentro del repositorio se encuentra un archivo makefile que tiene los siguientes
objetivos:

## `compile`

Este objetivo va a generar los carpinchos a ejecutar dentro del 
directorio build.

Antes de ejecutarlo, es muy importante que la variable `LIBRARY_PATH` esté 
configurada apuntando hacia la ruta donde se encuentra el archivo `*.so` que se
genera al compilar la library. Esto se puede hacer utilizando el comando 
`export`:

```
$ export LIBRARY_PATH=$LIBRARY_PATH:/home/utnso/tp-2021-2c-xxxx/matelib/bin
```

También, antes de ejecutar cada carpincho, se deberá hacer lo mismo para
`LD_LIBRARY_PATH`:

```
$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/utnso/tp-2021-2c-xxxx/matelib/bin
```

## `clean`

Este objetivo elimina todos los carpinchos compilados por el comando compilar.
