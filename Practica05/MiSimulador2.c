#include "CacheSim.h"
#include <stdio.h>


/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct{
	int v0;
	int v1;
	int use;
} cj;

int fallos = 0;
int encerts = 0;


cj mc[64]; // 4096/32 = 128; 128/2 (2 vias) = 64;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen?ar cada un dels tests.
 * */


void init_cache ()
{
    totaltime=0.0;
	int i;
	for (i = 0; i < 64; ++i){
		mc[i].use = -1;
		mc[i].v0 = -1;
		mc[i].v1 = -1;
	}



}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference(unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m;
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla?a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla?ada
	float t1, t2;		// Variables per mesurar el temps (NO modificar)

	t1 = GetTime();

	unsigned int addr = address;
	byte = addr & 31;
	addr /= 32;
	bloque_m = addr & 134217727;
	conj_mc = addr & 63;
	addr /= 64;
	tag = addr & 2097151;
	tag_out = -1;

	//if primera via vacia
	if (mc[conj_mc].v0 == -1){
		mc[conj_mc].v0 = tag;
		via_mc = 0;
		miss = 1;
		replacement = 0;
		mc[conj_mc].use = 1;
        ++fallos;
	}

	//if primera via no vacia pero != del tag
	else if (mc[conj_mc].v0 != tag){

		//segunda via vacia
		if (mc[conj_mc].v1 == -1){
			mc[conj_mc].v1 = tag;
			via_mc = 1;
			miss = 1;
			replacement = 0;
			mc[conj_mc].use = 0;
            ++fallos;
		}
		
		
		

		//segunda via no vacia pero != del tag
		else if (mc[conj_mc].v1 != tag){
			if (mc[conj_mc].use == 0){
				tag_out = mc[conj_mc].v0;
				mc[conj_mc].v0 = tag;
				via_mc = 0;
				mc[conj_mc].use = 1;
				miss = 1;
				replacement = 1;
                ++fallos;
			}
			else{
				tag_out = mc[conj_mc].v1;
				mc[conj_mc].v1 = tag;
				via_mc = 1;
				miss = 1;
				replacement = 1;
				mc[conj_mc].use = 0;
                ++fallos;
			}
		}
		//segunda via no facia y == al tag
		else{
			via_mc = 1;
			mc[conj_mc].use = 0;
			miss = 0;
			replacement = 0;
            ++encerts;
		}
	}
	//if primera via no vacia y == al tag
	else {
		via_mc = 0;
		mc[conj_mc].use = 1;
		miss = 0;
		replacement = 0;
        ++encerts;
	}





	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb? mesurem el temps d'execuci?
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
	printf("Hem arribat al final del programa\n");
    printf("ENCERTS: %d, FALLOS: %d \n", encerts, fallos);

  
}
