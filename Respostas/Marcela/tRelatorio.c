#include "tRelatorio.h"

typedef struct  tRelatorio tRelatorio;

tRelatorio *criaRelatorio();

void DesalocaRelatorio(void *dado);

void ImprimeNaTelaRelatorio(void *dado);

void ImprimeEmArquivorelatorio(void *dado);
