#include "Integracao.h"

class NC_F_P3 : 
   public Integracao {

  public:
    
    NC_F_P3(Funcao* integrando, double a, double b, int particao_ou_precisao, int numero_de_particoes, double precisao);
    double integrar();
    double integrarP(int n);
    double integracao(Funcao *f, double a1, double b1);
  
};