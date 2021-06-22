#include <iostream>
#include "Funcao01.h"
#include "Funcao02.h"
#include "Funcao03.h"
#include "Funcao04.h"
#include "NC_A_P1.h"
#include "NC_F_P1.h"
#include "NC_A_P2.h"
#include "NC_F_P2.h"
#include "NC_A_P3.h"
#include "NC_F_P3.h"
#include "NC_A_P4.h"
#include "NC_F_P4.h"
#include "Funcao.h"
#include "Integracao.h"

using namespace std;

int main() {

  int no_fechada_ou_aberta = 0;
  int grau_polinomio_substituicao = -1;
  int particao_ou_precisao = 0;
  int numero_de_particoes = 0;
  int id_integrando = 0;
  Funcao *integrando = 0;
  Integracao *pintegrObj;

  double a = -1.0;
  double b = 1.0;
  double precisao = 0.000001;
  double integral;

  cout << "Escolha a função a ser integrada: \n";
  cout << "\t1 - x^3 \n";
  cout << "\t2 - sin(x) \n";
  cout << "\t3 - cos(x) \n";
  cout << "\t4 - (sen(2x)+4x^2+3x)^2 \n";
  cin >> id_integrando;
  switch (id_integrando) {
    case 1:
       integrando = new Funcao01;
       break;
    case 2:
       integrando = new Funcao02;
       break;
    case 3:
       integrando = new Funcao03;
       break;
    case 4:
       integrando = new Funcao04;
  }

  cout << "Escolha o valor de a: \n";
  cin >> a;

  cout << "Escolha o valor de b: \n";
  cin >> b;

  cout << "Escolha entre a filosofia aberta a fechada: \n";
  cout << "1 - Aberta \n";
  cout << "2 - Fechada \n";
  cin >> no_fechada_ou_aberta;

  cout << "Escolha o grau do polinômio de substituição: \n";
  cout << "1 - Grau 1 \n";
  cout << "2 - Grau 2 \n";
  cout << "3 - Grau 3 \n";
  cout << "4 - Grau 4 \n";
  cin >> grau_polinomio_substituicao;

  cout << "Escolha entre partição e precisão: \n";
  cout << "1 - Partição \n";
  cout << "2 - Precisão \n";
  cin >> particao_ou_precisao;

  if (particao_ou_precisao == 1) {
    cout << "Escolha o número de partições: \n";
    cin >> numero_de_particoes;
  } else {
    cout << "Escolha a precisão: \n";
    cin >> precisao;
  }

  switch (no_fechada_ou_aberta) {
    case 1:
       
       switch (grau_polinomio_substituicao) {
         case 1:
            pintegrObj = new NC_A_P1(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
            break;

         case 2:
            pintegrObj = new NC_A_P2(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
            break;

         case 3:
            pintegrObj = new NC_A_P3(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
            break;

         case 4:
            pintegrObj = new NC_A_P4(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
            break;

       }
       break;

    case 2:

       switch (grau_polinomio_substituicao) {
         case 1:
            pintegrObj = new NC_F_P1(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
            break;

         case 2:
            pintegrObj = new NC_F_P2(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
            break;

         case 3:
            pintegrObj = new NC_F_P3(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
            break;

         case 4:
            pintegrObj = new NC_F_P4(integrando, a, b, particao_ou_precisao, numero_de_particoes, precisao);
            integral = pintegrObj->integrar();
            break;
       }
       break;
  }

  cout << "O valor da integral é : " << integral;

}