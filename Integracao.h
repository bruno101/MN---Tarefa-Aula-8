#pragma once
#include "Funcao.h"

class Integracao {

  protected:
    
    Funcao* integrando;
    double a;
    double b;
    int particao_ou_precisao;
    int numero_de_particoes;
    double precisao;

  public:
    
    virtual double integrar() = 0;

};