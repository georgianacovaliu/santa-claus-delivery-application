#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "MosCraciun.h"
#define V 5

using namespace std;

MosCraciun::MosCraciun() {
    sol[0] = s;
}

void MosCraciun::hello() {
    cout << "\n{MOS CRACIUN}" << endl;
}

void MosCraciun::citesteKm() {      //Citeste din fisier matricea costurilor
    ifstream f("zbor.txt");

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            f >> graph[i][j];
}

void MosCraciun::bestRoute()     //Similar cu traveling Salesman Problem
{
    vector<int> vertex;               //Memoreaza toate nodurile cu exceptia nodului sursa

    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;       //Memoreaza ciclul Hamiltonian de cost minim (costul drumului critic)
    do {
        int current_pathweight = 0;      //Memoreaza costul curent

        int k = s;                                        //Calculeaza costurile drumului curent
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }

        if (current_pathweight < min_path) {                //Verifica daca costurile drumului curent sunt mai mici decat costurile drumului critic
            min_path = current_pathweight;                  //Daca da, atunci drumul curent devine noul drum critic
            for (int i = 0; i < vertex.size(); i++) {
                sol[i + 1] = vertex[i];
            }
        }

    } while (
        next_permutation(vertex.begin(), vertex.end()));    //Se trece la urmatoarea permutare

    cout << "\nDrumul critic va fi de " << min_path << " km." << endl;
}

void MosCraciun::afisareTraseu() {
    int i = 1;
    string orase[5] = { "Rovaniemi", "San Miguelito", "Bajo Boquete", "Las Tablas", "La Chorrera" };    //Orasele din scrisori
    
    for (int j = 0; j < V; j++) {
        traseu[j] = orase[sol[j]];              //Memoreaza orasele ca stringuri, in ordinea in care vor fi parcurse
    }

    cout << "\nTraseul Mosului este: "<< traseu[0];

    while (i < V) {
        cout << "-->" << traseu[i];
        ++i;
    }
    cout << endl;
}