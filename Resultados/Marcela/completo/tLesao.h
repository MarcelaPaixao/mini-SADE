#ifndef _TAGENTE_H_
#define _TAGENTE_H_

/*typedef enum
{
    FACE, 
    ORELHA, 
    COURO CABELUDO, 
    PEITORAL, 
    DORSO, 
    ABDOME,  
    BRAÇO, 
    ANTEBRAÇO, 
    MAO, 
    COXA, 
    CANELA,
    PE,
    OUTROS
}eRegiao;
*/

/*typedef enum
{
    CARCINOMA BASOCELULAR, 
    CARCINOMA ESPINOCELULAR, 
    MELANOMA, 
    CERATOSE ACTINICA, 
    NEVO, 
    CERATOSE SEBORREICA,
    OUTROS
}eDiagnostico;*/

typedef struct tLesao tLesao;

tLesao *CriaLesao();

void DesalocaLesao(tLesao *lesao);

void AdicionaRotulo

int EnviaCirugia(tLesao *lesao);

int EnviaCrioterapia(tLesao *lesao);

#endif