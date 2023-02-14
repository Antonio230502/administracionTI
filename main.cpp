#include <iostream>

using namespace std;

void M2x2 ();
void M3x3 ();
void M4x4 ();
void M5x5 ();

int main()
{
    int op;

    cout<<"\tCalculadora de sistemas de ecuaciones"<<endl;
    cout<<"\n1. Matriz de 2x2"<<endl;
    cout<<"2. Matriz de 3x3"<<endl;
    cout<<"3. Matriz de 4x4"<<endl;
    cout<<"4. Matriz de 5x5"<<endl;
    cout<<"\nSeleccione la opcion que desee realizar: "; cin>>op;

    switch (op)
    {
        case 1:
            M2x2(); ///Método de reducción
            break;
        case 2:
            M3x3(); ///Método de Gauss
            break;
        case 3:
            M4x4(); ///Método de Gauss
            break;
        case 4:
            M5x5(); ///Método de Gauss
            break;
    }

    return 0;
}

void M2x2 ()
{
    cout<<endl<<"Usted ha seleccionado Matriz de 2x2"<<endl;
    float x1[5],x2[5],R[5];
    float X1=0, X2=0;

    cout<<"\nIngrese los coeficientes de las variables de cada ecuacion\n"<<endl;

    for(int i=0; i<2; i++)
    {
        cout<<"\n\tEcuacion "<<i+1<<endl;
        cout<<"x1: "; cin>>x1[i];
        cout<<"x2: "; cin>>x2[i];
        cout<<"Resultado: "; cin>>R[i];
    }

    x1[2] = x1[0]*-x1[1];
    x2[2] = x2[0]*-x1[1];
    R[2] = R[0]*-x1[1];

    x1[3] = x1[1]*x1[0];
    x2[3] = x2[1]*x1[0];
    R[3] = R[1]*x1[0];

    x1[4] = x1[2]+x1[3];
    x2[4] = x2[2]+x2[3];
    R[4] = R[2]+ R[3];

    for(int i=2; i<4; i++)
    {
        cout<<"\n\tEcuacion equivalente a la ecuacion "<<i-1<<endl<<endl;

        cout<<x1[i]<<"x1";

        if(x2[i]>0)
        {
            cout<<" + "<<x2[i]<<"x2 = "<<R[i]<<endl;
        }
        else
        {
            cout<<" - "<<-x2[i]<<"x2 = "<<R[i]<<endl;
        }

    }

    cout<<"\n\tEcuacion reducida"<<endl<<endl;

    cout<<x2[4]<<"x2 = "<<R[4]<<endl;

    X2 = R[4]/x2[4];
    X1 = (R[0]-(x2[0]*X2))/x1[0];

    cout<<"\nValor de x1: "<<X1<<endl;
    cout<<"Valor de x2: "<<X2<<endl;
}

void M3x3 ()
{
    cout<<endl<<"Usted ha seleccionado Matriz de 3x3"<<endl;
    float x1[5],x2[5], x3[5], R[5], MA1x1[3], MA1x2[3], MA1x3[3], MA1_R[3];
    float X1=0, X2=0, X3=0;

    cout<<"\nIngrese los coeficientes de las variables de cada ecuacion\n"<<endl;

    for(int i=0; i<3; i++)
    {
        cout<<"\n\tEcuacion "<<i+1<<endl;
        cout<<"x1: "; cin>>x1[i];
        cout<<"x2: "; cin>>x2[i];
        cout<<"x3: "; cin>>x3[i];
        cout<<"Resultado: "; cin>>R[i];
    }

    cout<<"\nMATRIZ DEL SISTEMA DE ECUACIONES\n\n";

    for(int i=0; i<3; i++)
    {
        cout<<"\t"<<x1[i]<<" "<<x2[i]<<" "<<x3[i]<<" "<<R[i]<<endl;
    }

    MA1x1[0]= x1[0];
    MA1x2[0]= x2[0];
    MA1x3[0]= x3[0];
    MA1_R[0]= R[0];

    ///Ceros primera columna

    for(int i=1; i<3; i++)
    {
        x1[3] = x1[0]*-x1[i];
        x2[3] = x2[0]*-x1[i];
        x3[3] = x3[0]*-x1[i];
        R[3] = R[0]*-x1[i];

        x1[4] = x1[i]*x1[0];
        x2[4] = x2[i]*x1[0];
        x3[4] = x3[i]*x1[0];
        R[4] = R[i]*x1[0];

        MA1x1[i]= x1[3]+x1[4];
        MA1x2[i]= x2[3]+x2[4];
        MA1x3[i]= x3[3]+x3[4];
        MA1_R[i]= R[3]+R[4];
    }

    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros primera columna)\n\n";

    for(int i=0; i<3; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1_R[i]<<endl;
    }

    ///Ceros segunda columna

    x2[3] = MA1x2[1]*-MA1x2[2];
    x3[3] = MA1x3[1]*-MA1x2[2];
    R[3] = MA1_R[1]*-MA1x2[2];

    x2[4] = MA1x2[2]*MA1x2[1];
    x3[4] = MA1x3[2]*MA1x2[1];
    R[4] = MA1_R[2]*MA1x2[1];

    MA1x2[2]= x2[3]+x2[4];
    MA1x3[2]= x3[3]+x3[4];
    MA1_R[2]= R[3]+R[4];

    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros segunda columna)\n\n";

    for(int i=0; i<3; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1_R[i]<<endl;
    }

    X3 = MA1_R[2]/MA1x3[2];
    X2 = (MA1_R[1]-(MA1x3[1]*X3))/MA1x2[1];
    X1 = (MA1_R[0]-(MA1x3[0]*X3)-(MA1x2[0]*X2))/MA1x1[0];

    cout<<"\nValor de la variable x1: "<<X1<<endl;
    cout<<"Valor de la variable x2: "<<X2<<endl;
    cout<<"Valor de la variable x3: "<<X3<<endl;
}

void M4x4 ()
{
    cout<<endl<<"Usted ha seleccionado Matriz de 4x4"<<endl;
    float x1[6],x2[6], x3[6], x4[6], R[6], MA1x1[6], MA1x2[4], MA1x3[4], MA1x4[4], MA1_R[4];
    float X1=0, X2=0, X3=0, X4=0;

    cout<<"\nIngrese los coeficientes de las variables de cada ecuacion\n"<<endl;

    for(int i=0; i<4; i++)
    {
        cout<<"\n\tEcuacion "<<i+1<<endl;
        cout<<"x1: "; cin>>x1[i];
        cout<<"x2: "; cin>>x2[i];
        cout<<"x3: "; cin>>x3[i];
        cout<<"x4: "; cin>>x4[i];
        cout<<"Resultado: "; cin>>R[i];
    }

    cout<<"\nMATRIZ DEL SISTEMA DE ECUACIONES\n\n";

    for(int i=0; i<4; i++)
    {
        cout<<"\t"<<x1[i]<<" "<<x2[i]<<" "<<x3[i]<<" "<<x4[i]<<" "<<R[i]<<endl;
    }

    MA1x1[0]= x1[0];
    MA1x2[0]= x2[0];
    MA1x3[0]= x3[0];
    MA1x4[0]= x4[0];
    MA1_R[0]= R[0];

    ///Ceros primera columna

    for(int i=1; i<4; i++)
    {
        x1[4] = x1[0]*-x1[i];
        x2[4] = x2[0]*-x1[i];
        x3[4] = x3[0]*-x1[i];
        x4[4] = x4[0]*-x1[i];
        R[4] = R[0]*-x1[i];

        x1[5] = x1[i]*x1[0];
        x2[5] = x2[i]*x1[0];
        x3[5] = x3[i]*x1[0];
        x4[5] = x4[i]*x1[0];
        R[5] = R[i]*x1[0];

        MA1x1[i]= x1[4]+x1[5];
        MA1x2[i]= x2[4]+x2[5];
        MA1x3[i]= x3[4]+x3[5];
        MA1x4[i]= x4[4]+x4[5];
        MA1_R[i]= R[4]+R[5];

    }


    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros primera columna)\n\n";

    for(int i=0; i<4; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1x4[i]<<" "<<MA1_R[i]<<endl;
    }

    ///Ceros segunda columna

    for(int i=2; i<4; i++)
    {
        x2[4] = MA1x2[1]*-MA1x2[i];
        x3[4] = MA1x3[1]*-MA1x2[i];
        x4[4] = MA1x4[1]*-MA1x2[i];
        R[4] = MA1_R[1]*-MA1x2[i];

        x2[5] = MA1x2[i]*MA1x2[1];
        x3[5] = MA1x3[i]*MA1x2[1];
        x4[5] = MA1x4[i]*MA1x2[1];
        R[5] = MA1_R[i]*MA1x2[1];

        MA1x2[i]= x2[4]+x2[5];
        MA1x3[i]= x3[4]+x3[5];
        MA1x4[i]= x4[4]+x4[5];
        MA1_R[i]= R[4]+R[5];

    }

    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros segunda columna)\n\n";

    for(int i=0; i<4; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1x4[i]<<" "<<MA1_R[i]<<endl;
    }

    ///Ceros tercer columna

    x3[4] = MA1x3[2]*-MA1x3[3];
    x4[4] = MA1x4[2]*-MA1x3[3];
    R[4] = MA1_R[2]*-MA1x3[3];

    x3[5] = MA1x3[3]*MA1x3[2];
    x4[5] = MA1x4[3]*MA1x3[2];
    R[5] = MA1_R[3]*MA1x3[2];

    MA1x3[3]= x3[4]+x3[5];
    MA1x4[3]= x4[4]+x4[5];
    MA1_R[3]= R[4]+R[5];

    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros tercera columna)\n\n";

    for(int i=0; i<4; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1x4[i]<<" "<<MA1_R[i]<<endl;
    }

    X4 = MA1_R[3]/MA1x4[3];
    X3 = (MA1_R[2]-(MA1x4[2]*X4))/MA1x3[2];
    X2 = (MA1_R[1]-(MA1x4[1]*X4)-(MA1x3[1]*X3))/MA1x2[1];
    X1 = (MA1_R[0]-(MA1x4[0]*X4)-(MA1x3[0]*X3)-(MA1x2[0]*X2))/MA1x1[0];

    cout<<"\nValor de la variable x1: "<<X1<<endl;
    cout<<"Valor de la variable x2: "<<X2<<endl;
    cout<<"Valor de la variable x3: "<<X3<<endl;
    cout<<"Valor de la variable x4: "<<X4<<endl;

}

void M5x5 ()
{
    cout<<endl<<"Usted ha seleccionado Matriz de 5x5"<<endl;
    float x1[7],x2[7], x3[7], x4[7], x5[7], R[7], MA1x1[7], MA1x2[5], MA1x3[5], MA1x4[5],MA1x5[5], MA1_R[5];
    float X1=0, X2=0, X3=0, X4=0, X5=0;

    cout<<"\nIngrese los coeficientes de las variables de cada ecuacion\n"<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<"\n\tEcuacion "<<i+1<<endl;
        cout<<"x1: "; cin>>x1[i];
        cout<<"x2: "; cin>>x2[i];
        cout<<"x3: "; cin>>x3[i];
        cout<<"x4: "; cin>>x4[i];
        cout<<"x5: "; cin>>x5[i];
        cout<<"Resultado: "; cin>>R[i];
    }

    cout<<"\nMATRIZ DEL SISTEMA DE ECUACIONES\n\n";

    for(int i=0; i<5; i++)
    {
        cout<<"\t"<<x1[i]<<" "<<x2[i]<<" "<<x3[i]<<" "<<x4[i]<<" "<<x5[i]<<" "<<R[i]<<endl;
    }

    MA1x1[0]= x1[0];
    MA1x2[0]= x2[0];
    MA1x3[0]= x3[0];
    MA1x4[0]= x4[0];
    MA1x5[0]= x5[0];
    MA1_R[0]= R[0];

    ///Ceros primera columna

    for(int i=1; i<5; i++)
    {
        x1[5] = x1[0]*-x1[i];
        x2[5] = x2[0]*-x1[i];
        x3[5] = x3[0]*-x1[i];
        x4[5] = x4[0]*-x1[i];
        x5[5] = x5[0]*-x1[i];
        R[5] = R[0]*-x1[i];

        x1[6] = x1[i]*x1[0];
        x2[6] = x2[i]*x1[0];
        x3[6] = x3[i]*x1[0];
        x4[6] = x4[i]*x1[0];
        x5[6] = x5[i]*x1[0];
        R[6] = R[i]*x1[0];

        MA1x1[i]= x1[5]+x1[6];
        MA1x2[i]= x2[5]+x2[6];
        MA1x3[i]= x3[5]+x3[6];
        MA1x4[i]= x4[5]+x4[6];
        MA1x5[i]= x5[5]+x5[6];
        MA1_R[i]= R[5]+R[6];
    }

    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros primera columna)\n\n";

    for(int i=0; i<5; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1x4[i]<<" "<<MA1x5[i]<<" "<<MA1_R[i]<<endl;
    }

    ///Ceros segunda columna

    for(int i=2; i<5; i++)
    {
        x2[5] = MA1x2[1]*-MA1x2[i];
        x3[5] = MA1x3[1]*-MA1x2[i];
        x4[5] = MA1x4[1]*-MA1x2[i];
        x5[5] = MA1x5[1]*-MA1x2[i];
        R[5] = MA1_R[1]*-MA1x2[i];

        x2[6] = MA1x2[i]*MA1x2[1];
        x3[6] = MA1x3[i]*MA1x2[1];
        x4[6] = MA1x4[i]*MA1x2[1];
        x5[6] = MA1x5[i]*MA1x2[1];
        R[6] = MA1_R[i]*MA1x2[1];

        MA1x2[i]= x2[5]+x2[6];
        MA1x3[i]= x3[5]+x3[6];
        MA1x4[i]= x4[5]+x4[6];
        MA1x5[i]= x5[5]+x5[6];
        MA1_R[i]= R[5]+R[6];
    }


    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros segunda columna)\n\n";

    for(int i=0; i<5; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1x4[i]<<" "<<MA1x5[i]<<" "<<MA1_R[i]<<endl;
    }

    ///Ceros tercera columna

    for(int i=3; i<5; i++)
    {
        x3[5] = MA1x3[2]*-MA1x3[i];
        x4[5] = MA1x4[2]*-MA1x3[i];
        x5[5] = MA1x5[2]*-MA1x3[i];
        R[5] = MA1_R[2]*-MA1x3[i];

        x3[6] = MA1x3[i]*MA1x3[2];
        x4[6] = MA1x4[i]*MA1x3[2];
        x5[6] = MA1x5[i]*MA1x3[2];
        R[6] = MA1_R[i]*MA1x3[2];

        MA1x3[i]= x3[5]+x3[6];
        MA1x4[i]= x4[5]+x4[6];
        MA1x5[i]= x5[5]+x5[6];
        MA1_R[i]= R[5]+R[6];
    }

    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros tercera columna)\n\n";

    for(int i=0; i<5; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1x4[i]<<" "<<MA1x5[i]<<" "<<MA1_R[i]<<endl;
    }

    ///Ceros cuarta columna

    x4[5] = MA1x4[3]*-MA1x4[4];
    x5[5] = MA1x5[3]*-MA1x4[4];
    R[5] = MA1_R[3]*-MA1x4[4];

    x4[6] = MA1x4[4]*MA1x4[3];
    x5[6] = MA1x5[4]*MA1x4[3];
    R[6] = MA1_R[4]*MA1x4[3];

    MA1x4[4]= x4[5]+x4[6];
    MA1x5[4]= x5[5]+x5[6];
    MA1_R[4]= R[5]+R[6];

    cout<<"\nMATRIZ AUXILIAR DEL SISTEMA DE ECUACIONES (Ceros cuarta columna)\n\n";

    for(int i=0; i<5; i++)
    {
        cout<<"\t"<<MA1x1[i]<<" "<<MA1x2[i]<<" "<<MA1x3[i]<<" "<<MA1x4[i]<<" "<<MA1x5[i]<<" "<<MA1_R[i]<<endl;
    }

    X5 = MA1_R[4]/MA1x5[4];
    X4 = (MA1_R[3]-(MA1x5[3]*X5))/MA1x4[3];
    X3 = (MA1_R[2]-(MA1x5[2]*X5)-(MA1x4[2]*X4))/MA1x3[2];
    X2 = (MA1_R[1]-(MA1x5[1]*X5)-(MA1x4[1]*X4)-(MA1x3[1]*X3))/MA1x2[1];
    X1 = (MA1_R[0]-(MA1x5[0]*X5)-(MA1x4[0]*X4)-(MA1x3[0]*X3)-(MA1x2[0]*X2))/MA1x1[0];

    cout<<"\nValor de la variable x1: "<<X1<<endl;
    cout<<"Valor de la variable x2: "<<X2<<endl;
    cout<<"Valor de la variable x3: "<<X3<<endl;
    cout<<"Valor de la variable x4: "<<X4<<endl;
    cout<<"Valor de la variable x5: "<<X5<<endl;
}
