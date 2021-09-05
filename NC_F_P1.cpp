#include "NC_F_P1.h"
#include <iostream>

NC_F_P1::NC_F_P1(Funcao* integrando, double a, double b, int particao_ou_precisao, int numero_de_particoes, double precisao) {

  this->integrando = integrando;
  this->a = a;
  this->b = b;
  this->particao_ou_precisao = particao_ou_precisao;
  this->numero_de_particoes = numero_de_particoes;
  this->precisao = precisao;

}

double NC_F_P1::integracao(Funcao *fun, double a1, double b1) {

  double h = b1-a1;
  return ((1.0/2.0)*h*(fun->f(a1) + fun->f(a1+h)));
  
}

double NC_F_P1::integrarP(int n) {

  double step = (b-a)/n;

  double integral = 0;

  for (int i = 0; i < n; i++) {
    integral += integracao(integrando, a+step*i, a+step*(i+1));
  }

  return integral;

}

double NC_F_P1::integrar () {

  double integral = 0;

  if (particao_ou_precisao == 1) {

    integral = integrarP(numero_de_particoes);

  } else {

    double n = 1;
    double oldIntegral;

    while (1) {

      integral = integrarP(n);
      
      if (n == 1) {

        oldIntegral = integral;
        n*=2;
        continue;

      } else {

        if (integral == 0) {
          if (abs(integral-oldIntegral) < precisao) {
            break;
          }
        } else if ( abs( (integral-oldIntegral)/integral ) < precisao) {
          break;
        }

        n*=2;
        oldIntegral = integral;

      }

    }


  }

  return integral;

}