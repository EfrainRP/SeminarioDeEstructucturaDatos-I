//Efrain Robles Pulido

#include <iostream>
using namespace std;

double voto1=0,voto2=0,voto3=0,porcentaje1,porcentaje2,porcentaje3,porcentajeX;

double *ptr1,*ptr2,*ptr3,a,b,c,p1,p2,p3,resp;
int opc=0;

double setVoto(double *vptr) {
    return *vptr=*vptr+1;
}

double setPorcentajes(double votoIndicado, double voto1,double voto2,double voto3) {
    porcentajeX=(votoIndicado*100)/(voto1+voto2+voto3);
    return porcentajeX;
}

int main(int argc, char** argv) {
    do {
        system("cls");
        cout<<"\tMENU"<<endl;
        cout<<"Candidato -> Atlas [1]"<<endl;
        cout<<"Candidato -> Chivas [2]"<<endl;
        cout<<"Candidato -> Toluca [3]"<<endl;
        cout<<"Seleccione opcion"<<endl;
        cin>>opc;

        switch(opc) {
        case 1:
            voto1=setVoto(&voto1);
            ptr1 = &voto1;
            a=*ptr1;

            break;
        case 2:
            voto2=setVoto(&voto2);
            ptr2 = &voto2;
            b=*ptr2;

            break;
        case 3:
            voto3=setVoto(&voto3);
            ptr3 = &voto3;
            c=*ptr3;

            break;
        default:
            cout<<endl;
            cout<<"ERROR: Ingrese uno nuevo"<<endl;
        }

        porcentaje1=setPorcentajes(a,a,b,c);
        ptr1 = &porcentaje1;
        p1=*ptr1;

        porcentaje2=setPorcentajes(b,a,b,c);
        ptr2 = &porcentaje2;
        p2=*ptr2;

        porcentaje3=setPorcentajes(c,a,b,c);
        ptr3 = &porcentaje3;
        p3=*ptr3;

        cout<<endl;
        cout<<"*********VOTOS**********"<<endl;
        cout<<" Atlas: "<<a<<endl;
        cout<<" Chivas: "<<b<<endl;
        cout<<" Toluca: "<<c<<endl;
        cout<<endl;

        cout<<"*****PORCENTAJES********"<<endl;
        cout<<" % Atlas "<<p1<<endl;
        cout<<" % Chivas "<<p2<<endl;
        cout<<" % Toluca "<<p3<<endl;
        cout<<endl;

        cout<<"Ingresar nuevo voto    1[si] 2[no]"<<endl;
        cin>>resp;

    }while(resp!=2);

    system("pause");
    return 0;
}
