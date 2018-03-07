#include "CacheSim.h"
#include <stdio.h>
//WT
/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

int mc[128]; //4096/32 = 128
int hits, misses;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La mc es inicialitzada al començar cada un dels tests.
 * */

void init_cache ()
{
  /* Escriu aqui el teu codi */

  hits = 0;
  misses = 0;
  int i;
  for(i = 0; i < 128; mc[i++] = -1){}
  
}
/* La rutina reference es cridada per cada referencia a simular */

void reference (unsigned int address, unsigned int LE)
{
    unsigned int byte;
    unsigned int bloque_m;
    unsigned int linea_mc;
    unsigned int tag;
    unsigned int miss;
    unsigned int lec_mp;
    unsigned int mida_lec_mp;
    unsigned int esc_mp;
    unsigned int mida_esc_mp;
    unsigned int replacement;
    unsigned int tag_out;

    /* Escriu aqui el teu codi */

    unsigned int addr = address;
    byte = addr & 31;

    addr /= 32;
    bloque_m = addr&0x7FFFFFF;
    linea_mc = addr&127;

    addr /= 128;
    tag = addr&0xFFFFF;
    tag_out = -1;


    //write
    if(LE) {
        lec_mp = 0;
        mida_esc_mp = 1;
        esc_mp = 1;
        replacement = 0;
        mida_lec_mp = 0;

        //hit
        if((mc[linea_mc] != -1) && (mc[linea_mc] == tag)){
            miss = 0;
            ++hits;
        }

        //miss
        else{
            miss = 1;
            ++misses;
        }
    }
    else { // lectura
        esc_mp = 0;
        mida_esc_mp = 0;

        //miss w/o replacement
        if(mc[linea_mc] == -1) {
            mc[linea_mc] = tag;
            miss = 1;
            replacement = 0;
            lec_mp = 1;
            mida_lec_mp = 32;
            ++misses;
        }

        //miss w/ replacement
        else if(mc[linea_mc] != tag) {
            tag_out = mc[linea_mc];
            mc[linea_mc] = tag;
            replacement = 1;
            lec_mp = 1;
            miss = 1;
            mida_lec_mp = 32;
            ++misses;
        }

        //hit
        else {
            miss = 0;
            lec_mp = 0;
            mida_lec_mp = 0;
            replacement = 0;
            ++hits;
      }
    }


    /* La funcio test_and_print escriu el resultat de la teva simulacio
     * per pantalla (si s'escau) i comproba si hi ha algun error
     * per la referencia actual
     * */

    test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
            miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
            replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */

void final ()
{
    /* Escriu aqui el teu codi */
    printf("num de hits: %d, num de misses: %d\n", hits, misses);
}
