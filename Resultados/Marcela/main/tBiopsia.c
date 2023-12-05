#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBiopsia.h"

struct tBiopsia {
    char nomePaciente[100];
    char cpfPaciente[15];
    char 
};

tBiopsia *CriaBiopsia();

void LiberaBiopsia(tBiopsia *biopsia);

/*Nome do paciente
CPF do paciente
Rótulo da(s) lesão(ões)
Diagnóstico da(s) lesão(ões)
Tamanho da(s) lesão(ões)
Nome do médico, CRM e data
*/

