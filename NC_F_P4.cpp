#include "NC_F_P4.h"
#include <iostream>

NC_F_P4::NC_F_P4(Funcao* integrando, double a, double b, int particao_ou_precisao, int numero_de_particoes, double precisao) {

  this->integrando = integrando;
  this->a = a;
  this->b = b;
  this->particao_ou_precisao = particao_ou_precisao;
  this->numero_de_particoes = numero_de_particoes;
  this->precisao = precisao;

}

double NC_F_P4::integracao(Funcao *fun, double a1, double b1) {

  double h = (b1-a1)/4;
  return ((2.0/45.0)*h*(7*fun->f(a1) + 32*fun->f(a1+h) + 12*fun->f(a1+2*h) + 32*fun->f(a1+3*h) + 7*fun->f(a1+4*h)));
  
}

double NC_F_P4::integrarP(int n) {

  double step = (b-a)/n;

  double integral = 0;

  for (int i = 0; i < n; i++) {
    integral += integracao(integrando, a+step*i, a+step*(i+1));
  }

  return integral;

}

double NC_F_P4::integrar () {

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