#include "NC_A_P3.h"
#include <iostream>

NC_A_P3::NC_A_P3(Funcao* integrando, double a, double b, int particao_ou_precisao, int numero_de_particoes, double precisao) {

  this->integrando = integrando;
  this->a = a;
  this->b = b;
  this->particao_ou_precisao = particao_ou_precisao;
  this->numero_de_particoes = numero_de_particoes;
  this->precisao = precisao;

}

double NC_A_P3::integracao(Funcao *fun, double a1, double b1) {

  double h = (b1-a1)/3;
  return ((3.0/8.0)*h*(fun->f(a1) + 3*fun->f(a1+h) + 3*fun->f(a1+2*h) + fun->f(a1+3*h)));

}

double NC_A_P3::integrarP(int n) {

  double step = (b-a)/n;

  double integral = 0;

  for (int i = 0; i < n; i++) {
    integral += integracao(integrando, a+step*i, a+step*(i+1));
  }

  return integral;

}

double NC_A_P3::integrar () {

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

        if ( abs( (integral-oldIntegral)/integral ) < precisao) {
          break;
        }

        n*=2;
        oldIntegral = integral;

      }

    }


  }

  return integral;

}