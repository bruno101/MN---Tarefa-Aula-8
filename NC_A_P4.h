#include "Integracao.h"

class NC_A_P4 : 
   public Integracao {

  public:
    
    NC_A_P4(Funcao* integrando, double a, double b, int particao_ou_precisao, int numero_de_particoes, double precisao);
    double integrar();
    double integrarP(int n);
    double integracao(Funcao *f, double a1, double b1);
  
};