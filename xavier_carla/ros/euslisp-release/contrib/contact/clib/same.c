/* Oct.16, 1990.  definition of error is changed to Euclid norm        */
/*                UNIT is considered when error is evaluated           */ 

#include "arith.h"

same(w,en,hashtab)
REAL w[MAXRANK][MAXEDGE];
int en;
TABLE hashtab;
{
    VECTOR w1,w2;
    REAL error;
    int i,k,hashkey,hashval;

    for(i=0; i<MAXRANK; i++)
	w1[i]= w[i][en];

    hashval=hash5(w1);

    for(k=hashval; k<HASHNO; k++){
	hashkey= hashtab[k];
	if(hashkey == EMPTY){
	    return(k);
	}
	else{
	    error= 0.0e0;
	    for(i=0; i<MAXRANK; i++){
		w2[i] = w[i][hashkey];
		error += (w1[i] - w2[i]) * (w1[i] - w2[i]);
	    }
	    if(sqrt(error) < EPS / UNIT)
		return(COLLISION);
	}
    }

    for(k=0; k<HASHNO; k++){
	hashkey= hashtab[k];
	if(hashkey == EMPTY){
	    return(k);
	}
	else{
	    error= 0.0e0;
	    for(i=0; i<MAXRANK; i++){
		w2[i] = w[i][hashkey];
		error += (w1[i] - w2[i]) * (w1[i] - w2[i]);
	    }
	    if(sqrt(error) < EPS / UNIT)
		return(COLLISION);
	}
    }
}





