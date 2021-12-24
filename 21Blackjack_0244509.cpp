#include <iostream>
#include <stdio.h> //random
#include <time.h> //tiempo
#include <bits/stdc++.h> //tiempo

using namespace std;

void Exe1()
{
  cout << "Jugará contra la casa, recibirá dos cartas boca abajo y podrá decidir si pedir otra o no." << endl << "El objetivo es acercarse a la suma en las cartas de 21" << endl;
  
  srand(time(NULL));
  
  
  int cartaA[5];
  int contA = 0;
  cartaA[0] = rand() % 9 + 1;
  contA += cartaA[0];
  cartaA[1] = rand() % 9 + 1; 
  contA += cartaA[1];
  //llenar ciclo
  cout << "Tus cartas son " << cartaA[0] << ", " << cartaA[1] << endl << endl;
  
  bool pedir = true;
  int nuCartasA = 2;
  while(pedir)
  {
    cout << "Pedir(1) Retar(0)" << endl;
    cin >> pedir;
    cout << endl;
    if(pedir)
    {
      nuCartasA++;
      cartaA[nuCartasA-1] = rand() % 9 + 1; 
      contA += cartaA[nuCartasA-1];
      cout << "La carta que tomaste es " <<  cartaA[nuCartasA-1] << endl;
      cout << "Tus cartas son ";
      for(int i=0; i<nuCartasA; i++)
      {
        cout << cartaA[i] << ", ";
      }
      if(contA > 21)
      {
        cout << endl << "Tus cartas sumaron " << contA << endl << "\u001b[31mYou LOSE" << endl;
        break;
      }
      if(nuCartasA == 5)
      {
        cout << endl << "Tus cartas sumaron " << contA << endl << "Ya tomaste 5 cartas." << endl << "\u001b[32mYou WIN" << endl;       
        break;
      }if(contA == 21)
      {
        cout << endl << "Tus cartas sumaron " << contA << endl << "\u001b[32mYou WIN" << endl;       
        break;
      }
    }
    else
    {
      int cartaB[5];
      int nuCartasB = 0;
      int contB = 0;
      //El metodo utilizado para que la casa no se pase de 21 es estandarizar el método de jugador humano y dejarlo en 16, ya que las personas suelen pedir otra si tienen 16 o menos, pero pedir una arriba cuando se tiene 17 o más se considera un riesgo.
      while(contB<=16)
      {
        nuCartasB++;
        cartaB[nuCartasB-1] = rand() % 9 + 1; 
        contB += cartaB[nuCartasB-1];
      }
      cout << "Las cartas de la casa fueron ";
      for(int i=0; i<nuCartasB; i++)
      {
        cout << cartaB[i] << ", ";
      }
      cout << endl << "La casa obtuvo " << contB << " puntos y tu obtuviste " << contA << " puntos" << endl;
      if(contB<=21)
      {
        if(contA >= contB)
        {
          cout << "\u001b[32mYou WIN" << endl;       
          break;
        }
        else
        {
          cout << "\u001b[31mYou LOSE" << endl;
          break;
        }
      }
      else
      {
        cout << "\u001b[32mYou WIN" << endl;       
        break;
      }
    }
  }
}

int main()
{
    int casos;
    bool exit = true;
    while(exit)
    {
      cout << "\u001b[0m" << endl;
      cout << endl  << "\u001b[34mBienvenido a Blackjack 21 en C++ de 0244509" << "\u001b[0m" << endl << endl;

      cout << "Para empezar el juego presione (1)" << endl;
      cout << "Para salir presione (0) " << endl;

      cin >> casos;
      cout << endl << endl; 
      switch(casos){
          case 1:
          Exe1(); 
          break;
          case 0:
          exit = false;
          break;
          default:
          cout << "Opción fuera de rango" << endl << endl;
          break;
      }
    } 
}
