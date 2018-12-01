//Nicolas Toro F , Rut= 187615194
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


double suma=0, cont=0, temp=0;
int v[60], temp2=0;
int moda=0,poc=0;
float med;

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
            temp=((temp*10));
            temp=((temp-10));
            temp2=(int)temp;
            v[temp2]=v[temp2]+1;
        }
        fi.close();
        med=float(suma/cont);

    for(int j=0;j<60;j++){
        if( v[j]>moda){
            moda=v[j];
            poc=j;
        }
    }
        cout << "La Suma es: "<< suma << endl;
        cout << "Hay un total de: "<<cont<<"  notas"<< endl;
        cout << "La Media es: "<< med << endl;
        cout << "La Moda es: "<< poc+10 << " y se repitio "<<v[poc]<<" veces"<< endl;
     }
    else cout << "Error al abrir el archivo" << endl;
    return 0;
}


