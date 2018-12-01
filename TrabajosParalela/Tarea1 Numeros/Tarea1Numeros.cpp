//Nicolas Toro F , Rut= 187615194
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "math.h"
#include "conio.h"
using namespace std;


double suma=0, cont=0, temp=0;
int v[60], temp2=0;
int moda=0,poc=0;
float med=0.0, varian=0, temp3;

int main(int argc, char argv[])
{
    ifstream fi; char linea[10];
    fi.open("numeros.txt",ios::in);

    if(fi.is_open()){
    cout << "El archivo se esta leyendo" << endl;
    for(int i=0;i<60;i++){
       v[i]=0;
    }
        while(!fi.eof()){
            fi >> linea;
            linea[1]='.';
            temp = (double)atof(linea);
            suma+=temp;
            cont++;
            //variables para acumular frecuencia
            temp=((temp*10));
            temp=((temp-10));
            temp2=(int)temp;
            v[temp2]=v[temp2]+1;
        }
        fi.close();
        med=float(suma/cont);

    //Moda
    for(int j=0;j<60;j++){
        if( v[j]>moda){
            moda=v[j];
            poc=j;
        }
    }

    //desviacion
    for(int h=0; h<cont; h++) {
       varian+= pow(((h+10)*v[h])-(med*v[h]), 2.0);
    }
    varian=varian/(cont-1);
    varian = sqrt(varian);

        cout << "La Suma es: "<< suma << endl;
        cout << "Hay un total de: "<<cont<<"  notas"<< endl;
        cout << "La Media es: "<< med << endl;
        temp3 = (float)poc;
        temp3= (temp3/10);
        cout << "La Moda es: "<< temp3+1 << " y se repitio "<<v[poc]<<" veces"<< endl;
        cout << "La Varianza es: "<< varian << endl;
     }
    else cout << "Error al abrir el archivo" << endl;
    return 0;
}


