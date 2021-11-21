################################################################################
# Makefile para compilar las pruebas del tp CarpinchOS
################################################################################

# Agrego las libs
LIBS := -lmatelib -lpthread -lcommons

#Agrego comandos extra
RM := rm -rf

# compilar --> Compila todos los carpinchos
compilar:
	mkdir build
	gcc -o "build/BatallaPorNordelta" BatallaPorNordelta.c $(LIBS)
	gcc -o "build/PruebaAsignacion" PruebaAsignacion.c $(LIBS)
	gcc -o "build/PruebaBase_Carpincho1" PruebaBase_Carpincho1.c $(LIBS)
	gcc -o "build/PruebaBase_Carpincho2" PruebaBase_Carpincho2.c $(LIBS)
	gcc -o "build/PruebaDeadlock" PruebaDeadlock.c $(LIBS)
	gcc -o "build/PruebaMMU" PruebaMMU.c $(LIBS)
	gcc -o "build/PruebaPlanificacion" PruebaPlanificacion.c $(LIBS)
	gcc -o "build/PruebaSuspension" PruebaSuspension.c $(LIBS)
	gcc -o "build/prueba_swamp" prueba_swamp.c $(LIBS)
	gcc -o "build/prueba_tlb_fifo" prueba_tlb_fifo.c $(LIBS)
	gcc -o "build/prueba_tlb_lru" prueba_tlb_lru.c $(LIBS)


# Install --> Copia el archivo matlib.h a /usr/include y a /usr/include/libs
install:
	sudo mkdir /usr/include/lib/
	sudo cp "./matelib_headers/matelib.h" "/usr/include/matelib.h"
	sudo cp "./matelib_headers/matelib.h" "/usr/include/lib/matelib.h"


# Limpiar todos los carpinchos
clean:
	-$(RM) build


