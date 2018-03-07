#include "CacheSim.h"
#include "stdio.h" //input-output

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

int mc[128]; // 4096/32 = 128


int fallos = 0;
int encerts = 0;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen?ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	int i;
	for (i = 0; i < 128; ++i){
	  mc[i] = -1;
	}

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla?a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla?ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();

	unsigned int addr = address;
	byte = addr & 31;
	addr /= 32;
	bloque_m = addr & 134217727;
	linea_mc = addr & 127;
	addr /= 128;
	tag = addr & 1048575;
	tag_out = -1;

	//fallo lectura
	 
    //		no se reemplaza
	if (mc[linea_mc] == -1){
		mc[linea_mc] = tag;
		miss = 1;
		replacement = 0;
        ++fallos;
	}
	
	//		se reemplaza
	else if (mc[linea_mc] != tag){ 
		tag_out = mc[linea_mc];
		mc[linea_mc] = tag;
		miss = 1;
		replacement = 1;
        ++fallos;
	}

	//hit lectura
	else{
        ++encerts;
		miss = 0;
		replacement = 0;
	}



	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb? mesurem el temps d'execuci?
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
  printf("Hem arribat al final del programa\n");
  printf("ENCERTS: %d, FALLOS: %d \n", encerts, fallos);
  
}
