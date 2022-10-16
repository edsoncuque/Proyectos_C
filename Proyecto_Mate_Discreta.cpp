#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;
// Codigo AsCII para simbolo de potencia alt+94 = ^
// declaracion de funciones
//funcion recursiva factorial
long f(long n){
    if (n==0){ //Caso Base
        n = 1;
    }  
    else{ // Caso General
	    n = n * f(n-1);
    }
    return n;
}
//funcion Permutacion sin repeticion formula nPr = n! / (n - r)!
long nPr(long n, long r){
	long resultado,r1,r2,tmp;
	r1 = f(n);
	tmp = n-r;
	r2 = f(tmp);
	resultado=r1/r2;
	return resultado;
}
//Permutacion con Repeticion formula PRn = n! / n1!n2!n3!nk!
long PRn(string cadena){
	int largo2,n,x,y;
	long resultado,valor1,valor2,tmp;
	char letra='A';
	largo2 = cadena.size();
	int valores[largo2];
	n=26;
	y=0;
	do
    {
        x=0;
        for(int i=0; i<largo2; i++){
			if(cadena[i]==letra)
			{
				x++;
			}
		}
        if(x>0){
        	cout << letra <<":" <<x <<endl;
        	valores[y]=x;
        	y++;
		}
        letra++;
        n--;
    }while(n!=0);
	
	valor1 = f(largo2);
	valor2 =1;
	for (int i = 0; i < largo2; i++)
    {
    	if(valores[i]==0){
    		break;
		}
		tmp = valores[i];
		valor2 *=  f(tmp);
    }
	resultado = valor1 / valor2;
    return resultado;
}
//funcion para convertir a Mayuscula las cadenas de caracteres
string Mayuscula(string texto){
	int largo;
	largo = texto.size();
	for(int i=0; i<largo; i++){
		texto[i]=toupper(texto[i]);
	}
	return texto;
}
// funcion para el principio de la multiplicacion
void principioMultiplicacion(int x){
	string pregunta="", pregunta2;
	int valores[5];
	int n,y,m,a;
	char* opciones[4];
	y=1;
	
	srand(time(NULL)); // se debe usar esta instruccion para inicializar el tiempo del randow
	a = rand()%(2); // el randowm seleccionara entre 0 y 2
	if(x==2){
		if(a==0){
			cout << "En una Obra de Teatro deben elegir parejas entre los diferentes tipos de personas" <<endl;
			cout << "Cuantas Parejas se pueden formar" <<endl;
			pregunta="Cantidad de ";
			string opciones[]={"Hombres","Mujeres","","",""};	
			pregunta2="Parejas";	
		}else{
			cout << "Las Ciudades A, B estan conectadas " <<endl;
			cout << "De cuantas Maneras podemos ir de A a B" <<endl;
			pregunta="Cantidad de Caminos hacia la Ciudad ";
			string opciones[]={"A","B","","",""};	
			pregunta2="Rutas";	
		}
		
	}else if(x>=3 && x<=4){
		cout << "Marta en su guardaropa tiene la siguiente cantidad de prendas" <<endl;
		cout << "de Cuantas formas se puede vestir" <<endl;
		pregunta="Cantidad de ";
		string opciones[]={"Pantalones","Blusas","Tops","Zapatos",""};	
		pregunta2="Conjuntos";
	}else if(x==5){
		cout << "Cuantas Placas de Moto se pueden diseñar si consta de dos letras y 3 numeros" <<endl;
		cout << "Ingresando el Limite para cada Caracter" <<endl;
		pregunta="Simbolos ";
		string opciones[]={"Letras","Letras","Numeros","Numeros","Numeros"};	
		pregunta2="Placas";
	}
	//inicializar vector
	for(int i=0; i<5; i++)
	{	
		valores[i]=0;
	}
	
	
	do{
		//,opciones[y-1].c_str()
		printf("%s %s ",pregunta.c_str(),opciones[y-1]);
		scanf("%d",&n);
		valores[y-1]=n;
		y=y+1;
	}while(y<=x);

	m=1;
	for(int i=0; i<5; i++)
	{
		if(valores[i]==0){
			break;
		}
		m=m * valores[i];
	}
	cout<< "Cantidad de " <<pregunta2 <<" Para Formar " <<m;
	system("pause>nul");
}
//funcion para el principio de la Suma
void principioSuma(int x){
	string pregunta="", pregunta2;
	int n,y,m,a;
	char* opciones[4];
	y=1;
	
	srand(time(NULL)); // se debe usar esta instruccion para inicializar el tiempo del randow
	a = rand()%(5); // el randowm seleccionara entre 0 y 4
	
	if(a==0){
		cout << "Cantidad de Lugares para Almorzar" <<endl;
		pregunta="Restaurantes de ";
		string opciones[]={"Pizza","Comida China","Pollo","Ceviche","Carne Asada"};	
		pregunta2="Restaurantes";
	}else if(a==1){
		cout << "Cantidad de Libros a Elegir en una Biblioteca" <<endl;
		pregunta="Libros de ";
		string opciones[]={"Biologia","Algebra Lineal","Administracion","Fisica","Programacion"};	
		pregunta2="Libros";
	}else if(a==2){
		cout << "Cantidad de Lineas de Buses a Elegir para ir a trabajar" <<endl;
		pregunta="Lineas ";
		string opciones[]={"A","B","C","D","E"};	
		pregunta2="Lineas de Buses";
	}else if(a==3){
		cout << "Cantidad de Hoteles para Vacacionar en cada Departamento" <<endl;
		pregunta="Hoteles en ";
		string opciones[]={"Atitlan","Xela","Retalhuleu","San Marcos","Peten"};	
		pregunta2="Hoteles";
	}else if(a==4){
		cout << "Cantidad de Colegios por Zona para Elegir" <<endl;
		pregunta="Colegios en Zona ";
		string opciones[]={"1","2","3","4","9"};	
		pregunta2="Colegios";
	}
	m=1;
	do{
		printf("%s %s ",pregunta.c_str(),opciones[y-1]);
		scanf("%d",&n);
		m = m + n;
		y=y+1;
	}while(y<=x);
	cout<< "Cantidad de " <<pregunta2 <<" a Elegir " <<m;
	system("pause>nul");
}
// permutacion con repeticion formula n^r
void permutacionConRepeticion(int x){
	string palabra;
	char* palabra2;
	int n,resultado,largo;
	int digitos,orden;
	if(x==1){
		cout << "Ingrese una palabra para ver cuantas formas de" <<endl;
		cout << "ordenar existen si se aceptan repeticiones de sus letras?" <<endl;
		cin >> palabra;	
		n = palabra.size();
		resultado = pow(n,n);
		cout<< "Hay " <<resultado <<" Maneras de ordenar la palabra " << Mayuscula(palabra)<<" Permitiendo repeticiones de sus letras ";	
	}else if(x==2){
		cout << "Ingrese Cantidad de digitos a utilizar maximo 10" <<endl;
		cin >> digitos;
		cout << "Ingrese cantidad de digitos a ordenar maximo 10" <<endl;
		cin >> orden;
		resultado = pow(digitos,orden);
		cout << "Hay " <<resultado <<" Maneras de ordenar " <<orden  <<" digitos, ";	
		cout << "si se aceptan repeticiones" <<endl;
	}else if(x==3){
		cout << "Ingrese una palabra con letras repetidas maximo 10" <<endl;
		cin >> palabra;
		cout << "Cuantas Formas diferentes de ordenar las letras existen en la palabra " <<Mayuscula(palabra) <<endl;
		largo=palabra.size();
		cout << "Hay " <<PRn(Mayuscula(palabra)) <<" Formas Diferentes de ordenar  las " <<largo  <<" Letras, de la Palabra " << Mayuscula(palabra);	
	}
	system("pause>nul");
}
// permutacion sin repeticion formula n!
void permutacionSinRepeticion(int x){
	string palabra;
	int n,r;
	if(x==1){
		cout << "Ingrese una palabra para ver cuantas formas de" <<endl;
		cout << "ordenar existen si no se aceptan repeticiones de sus letras?" <<endl;
		cin >> palabra;	
		n = palabra.size();
		cout<< "Hay " << f(n) <<" Maneras de ordenar la palabra " << Mayuscula(palabra)<<" sin permitir repeticiones de sus letras";
	}else if(x==2){
		cout << "Ingrese la cantidad de personas que van al cine maximo 10" <<endl;
		cin >> n;
		cout << "Y Ellos Encuentran " <<n  <<" Asientos Libres en una Fila" <<endl;
		cout << "¿De Cuantas maneras Diferentes Podran Sentarse si se Saben Ordenar en la Fila?" <<endl;
		cout <<endl;
		cout<< "Hay " << f(n) <<" Opciones diferentes de sentarse";
	}else if(x==3){
		cout << "Ingrese el numero de Atletas a Participar maximo 10! " <<endl;
		cin >> n;
		cout << "Ingrese la cantidad de Lugares de la Competicion " <<endl; 
		cin >> r;
		cout << "De cuantas maneras diferentes se pueden otorgar Los " <<r <<" Lugares";
		cout <<endl;
		cout << "Hay " << nPr(n,r) <<" Maneras de Ordenar los " <<r <<" Lugares";
	}else if(x==4){
		cout << "Ingrese La Cantidad de Bolas de Billar maximo 10! " <<endl;
		cin >> n;
		cout << "Si se Toman Unicamente " <<endl; 
		cin >> r;
		cout << "De cuantas maneras diferentes se pueden Ordenar las bolas si se tomaron " <<r <<" de Ellas";
		cout <<endl;
		cout << "Hay " << nPr(n,r) <<" Maneras de Distintas de Ordenar las " <<r <<" Bolas de Billar";
	}
	system("pause>nul");
}
//funcion combinacion sin repeticion formula nCr = n! / r!(n-r)!
void nCr(int x){   // Funcion Combinacion sin Repeticion
	int j,z,n,r,resultado,tmp1,tmp2,tmp3;
	char letra='A';
	char letra2,inicial;
	if(x==1){
		r=2;
		cout << "CAMPEONATO DE FUTBOL" <<endl;;
		cout << "SE DEFINIRAN EL PRIMERO Y SEGUNDO LUGAR DE LA COPA " <<endl;
		cout << "Introduzca el numero de equipos a participar maximo 10: " <<endl;
    	cin >> n;
    	char letras[n];
    	// crear vector de equipos
    	z=26;
    	j=0;
    	do{
    		letras[j]=letra;	
    		letra++;
    		z--;
    		j++;
    		if (j==n){
    			break;
			}
		}while(z!=0);
		// recorrer el vector
    	cout <<"Los Equipos a disputar la copa serian" <<endl;
    	for(int i=0; i<n; i++){
    		cout << letras[i] <<" ";
		}
    	cout <<endl;
    	// calculo de la formula
    	tmp1 = f(n); 
    	tmp2 = f(r);
    	tmp3 = f((n-r));
		resultado = tmp1 / (tmp2*tmp3); 
    	cout << "La Cantidad de Partidos a Disputar para estar en los " <<r <<" primeros lugares seria de " <<resultado <<" Partidos en Total" <<endl;
    	cout << "Los Equipos estarian conformados de la siguiente manera" <<endl;
    	// como estan conformados los equipos
    	for(int i=0; i<n; i++){
    		inicial=letras[i];
    		for(j=i+1;j<n;j++){
    			letra2=letras[j];
    			cout << inicial << letra2 <<endl;
			}
		}
	}else{
		cout << "UN ESTUDIANTE NECESITA RESOLVER UNA PRUEBA" <<endl;
		cout << "Ingrese la cantidad de preguntas de la que consta el examen maximo 10!!" <<endl;
    	cin >> n;
    	cout << "de estas " <<n <<" preguntas, ingresa la cantidad minima" <<endl;
		cout << "de pregutnas a responder para ganar la prueba, con la nota minima" <<endl;
		cin >> r;
		cout << "? De Cuantas formas puede hacer su eleccion sino importa el orden de las preguntas?" <<endl;
		// calculo de la formula
    	tmp1 = f(n); 
    	tmp2 = f(r);
    	tmp3 = f((n-r));
		resultado = tmp1 / (tmp2*tmp3); 
		cout << "Tiene " << resultado << " formas distintas de elegir " <<r <<" preguntas de" <<endl;
		cout << n << " de la prueba, para ganar su examen " <<endl;
	}
	system("pause>nul");
}
//funcion Combinacion con Repeticion formula C(n+r-1) = (n + r-1)! / r!(n-1)!
void Cnr(int x){
	int tmp1,tmp2,tmp3,n,r,resultado,r2;
	char* opciones[10];
	if(x==1){
		string opciones[]={"Rojo","Azul","Negro","Amarillo","Verde","Cafe","Morado","Naranja","Celeste","Blanco"};	
		cout << "\n\tVENTA DE ROPA PARA CABALLEROS";
		cout << "\n\t=============================\n";
		cout << "si el orden no importa y esta permitido repetir colores cuantos grupos de Camisas se pueden Formar?" <<endl;
		cout << "Ingrese la cantidad de colores de camisas que existen en la tienda?, Maximo 10 Colores" <<endl;
		cin >> r;
		cout << "Colores Disponibles" <<endl;
		for(int i=0; i<r; i++){
			cout << opciones[i] <<endl;
		}
		cout << "Ingrese la cantidad de camisas que llevara cada juego de camisas para la venta" <<endl;
		cin >> n;
		tmp1 = f((n+r-1));
		tmp2 = f(r);
		tmp3 = f((n-1));
		resultado = tmp1 / (tmp2*tmp3);  
		cout << "Hay " <<resultado <<" Formas distintas de combinar grupos de " <<n <<" Camisas entre los " <<r <<" Colores disponibles" <<endl;
	}else{
		string opciones[]={"Mora","Frambuesa","Ron con Pasas","Napolitano","Sandia","Limon","Pistacho","Vainilla","Chocolate","Fresa"};	
		cout << "\n\tHELADOS SARITA";
		cout << "\n\t===================\n";
		cout << "De Cuantas Formas se pueden elegir helados entre los sabores disponibles" <<endl;
		cout << "si Se permite repetir sabores para que al menos haya un Sabor de de cada Helado?" <<endl;
		cout << "Ingrese la cantidad de Sabores disponibles para la Venta, Maximo 10 Sabores" <<endl;
		cin >> n;
		cout << "Sabores Disponibles" <<endl;
		for(int i=0; i<n; i++){
			cout << opciones[i] <<endl;
		}
		cout << "Ingrese la cantidad de Helados que necesita" <<endl;
		cin >> r;
		r2=r;
		if(r>n){
			r = (r-n);		
		}
		tmp1 = f((n+r-1));
		tmp2 = f(r);
		tmp3 = f((n-1));
		resultado = tmp1 / (tmp2*tmp3);  
		cout << "Hay " <<resultado <<" Formas distintas de Elegir " <<r2 <<" Helados, Para que al Menos haya 1 Helado de cada Sabor" <<endl;
	}
	system("pause>nul");
}
//funcion factorial no recursiva
int fact(int n){
	int resultado=1;
	for(int i=1; i<=n; i++)
	resultado*=i;
	return resultado;		
}
//funcion de Combinacion
int combina(int n, int k){
	return (fact(n))/(fact(k)*fact(n-k));
}
//funcion Binomio de Newton
void BinomioNewton(string binomio,int n){
	int coef,x,i;
	x=n;
	cout <<"   ";
	for(i=0; i<n;i++){
		coef=0;
		coef=combina(n,i);
		if(i==0){
			cout << binomio[0] <<"^" <<x <<" + ";
		}else{
			if(i==1){
				cout <<coef << binomio[0] <<"^" <<x	<<binomio[2] <<" + ";
			}else{
				if(x==1){
					cout <<coef << binomio[0] <<binomio[2] <<"^" <<i <<" + ";	
				}else{
					if(x==0){
						cout <<binomio[2] <<" + " <<"^" <<i;								
					}else{
						cout <<coef << binomio[0] <<"^" <<x	<<binomio[2] <<"^" <<i <<" + ";	
					}
				}
			}
		}
		x--;
	}
	cout << binomio[2] <<"^" <<i;
	cout <<endl;
	system("pause>nul");
}
//funcion Triangulo de Pascal
void Pascal(int n){
	for(int i=0;i<=n; i++){
		//ciclo para agregar los espacios de la piramide
		for (int j=1; j<=n-i; j++)
        printf("   ");
        //ciclo donde imprimimos el resultado de la 
        //formula de combinacion
		for(int j=0;j<=i;j++){
			//utilizamos el formato %3d
			//para imprimir el resultado como entero
			//tomando 3 espacios para todos los numeros 
			printf("%3d   ", combina(i,j));
		}
		//agregamos salto de linea para 
		//el promximo renglon de la piramide
		cout <<endl;
	}
	//esperamos que el usuario pulse cualquier tecla para salir
	// de la funcion.
	system("pause>nul");
}
//funcion para encontrar el Coeficiente del Monomio
void findCoeficiente(string p1,string p2){
	int largo,largo2,i,x;
	long multi,resultado;
	int z;
	largo=p1.size();
	largo2=p2.size();	
	int exponente[5];
	char caracter='^';
	for(x=0;x<5;x++){
		exponente[x]=0;
	}
	x=0;
	for(i=0;i<largo;i++){
		if(p1[i]==caracter){
			stringstream ss;
			ss << p1[i+1];
			ss >> z;
			exponente[x]=z;
			x++;
		}
	}
	stringstream ss;
	ss << p2[largo2-1];
	ss >> z;
	multi=1;
	x=0;
	resultado=0;
	for(i=0;i<5;i++){
		if(exponente[i]==0){
			break;
		}
		x=exponente[i];
		multi = multi * fact(x);
	}
	resultado = fact(z)/multi;	
	cout <<endl;
	cout << "n=" <<z <<endl;
	cout << "k1=" <<exponente[0] <<endl;
	cout << "k2=" <<exponente[1] <<endl;
	cout <<endl;
	cout << "Respuesta = " << resultado << p1;
	system("pause>nul");
}
//funcion Operaciones con Conjuntos
void conjuntos(){
	int x,y,z,j,r,dif,largo,largo2;
	char letras[26];
	char letra='A';
	z=26;
    j=0;
   	do{
   		letras[j]=tolower(letra);	
   		letra++;
   		z--;
   		j++;
	}while(z!=0);
	///*
	cout << "U={";
	for(int i=0;i<26;i++){
		cout << letras[i] <<" ";
	}
	cout <<"}" <<endl;
	cout <<endl;
	//*/
	char ch,ch2; // letra='A';
	// Vector A
	srand(time(NULL));
	x = rand() % 10;
	largo=x;
	char A[largo];
	z = 0 + rand() % 25;
	dif=z+x;
	if(dif>25){	z=z-x; }
	for(int i=0; i<largo;i++){
		A[i]=letras[z];	
		z++;
	}
	
	// Vector B
	srand(time(NULL));
	j = rand() % 8;
	largo2=j;
	char B[largo2];
	r = 0 + rand() % 20;
	dif=0;
	dif=r+j;
	if(dif>25){	r=r-j; }
	for(int i=0; i<largo2;i++){
		B[i]=letras[r];	
		r++;
	}
	
	// MOSTRAR CONJUNTO A
	cout << "A={";
	for(int i=0; i<largo;i++){
		cout << A[i] << " ";
	}
	cout << "}" <<endl;
	cout <<endl;
	// MOSTRAR CONJUNTO B
	cout << "B={";
	for(int i=0; i<largo2;i++){
		cout << B[i] << " ";
	}
	cout << "}" <<endl;
	cout <<endl;
	
	// Union de Conjuntos
	cout << "A u B ={";
	int cont=0 ;
 	for(int i=0;i<largo;i++){
   		cout<<A[i]<<"  ";
 	}
  	for(int i=0;i<largo2;i++){
    		cont=0;
  		for(int j=0;j<largo;j++){
   			if(B[i]==A[j])
   			{
    			cont++;
   			}
  		}
  		if(cont==0)
  		cout<<B[i]<<"  ";
    }
	cout << "}" <<endl;
	cout <<endl;
	// Interseccion de Conjuntos
	cout<<"A n B ={";
 	for(int i=0;i<largo;i++){
  		for(int j=0;j<largo2;j++){
   			if(A[i]==B[j]){
    			cout<<A[i]<<"  ";
   			}
  		}
    }
	cout << "}" <<endl;
	cout <<endl;
	// Diferencia de Conjuntos
	cout<<"A - B ={";
	for(int i=0;i<largo;i++){
		z=0;
  		for(int j=0;j<largo2;j++){
   			if(A[i]==B[j]){
   				z=1;
    			break;
   			}
  		}
  		if (z==0){
   			cout<<A[i]<<"  ";	
        }
    }
	cout << "}" <<endl;	
	cout <<endl;
	// Diferencia de Conjuntos
	cout<<"B - A ={";
	for(int i=0;i<largo2;i++){
		z=0;
  		for(int j=0;j<largo;j++){
   			if(B[i]==A[j]){
   				z=1;
    			break;
   			}
  		}
  		if (z==0){
   			cout<<B[i]<<"  ";	
        }
    }
	cout << "}" <<endl;	
	cout <<endl;
	// Complemento de Ac
	cout<<"Ac ={";
	for(int i=0;i<26;i++){
		z=0;
  		for(int j=0;j<largo;j++){
   			if(letras[i]==A[j]){
   				z=1;
    			break;
   			}
  		}
  		if (z==0){
   			cout<<letras[i]<<"  ";	
        }
    }
	cout << "}" <<endl;	
	cout <<endl;
	// Complemento de Bc
	cout<<"Bc ={";
	for(int i=0;i<26;i++){
		z=0;
  		for(int j=0;j<largo2;j++){
   			if(letras[i]==B[j]){
   				z=1;
    			break;
   			}
  		}
  		if (z==0){
   			cout<<letras[i]<<"  ";	
        }
    }
	cout << "}" <<endl;	
	cout <<endl;
	
	system("pause>nul");
}
//Funcion Producto Cartesiano
void ProductoCartesiano(){
	int x,largo,largo2,z,dif,j,r;
	//Vector de Abecedario
	char letras[26];
	char letra='A';
	z=26;
    j=0;
   	do{
   		letras[j]=tolower(letra);	
   		letra++;
   		z--;
   		j++;
	}while(z!=0);
	// Vector A
	srand(time(NULL));
	x = rand() % 10;
	largo=x;
	char A[largo];
	z = 0 + rand() % 25;
	dif=z+x;
	if(dif>25){	z=z-x; }
	for(int i=0; i<largo;i++){
		A[i]=letras[z];	
		z++;
	}
	
	// Vector B
	srand(time(NULL));
	j = rand() % 8;
	largo2=j;
	char B[largo2];
	r = 0 + rand() % 20;
	dif=0;
	dif=r+j;
	if(dif>25){	r=r-j; }
	for(int i=0; i<largo2;i++){
		B[i]=letras[r];	
		r++;
	}
	
	// MOSTRAR CONJUNTO A
	cout << "A={";
	for(int i=0; i<largo;i++){
		cout << A[i] << " ";
	}
	cout << "}" <<endl;
	cout <<endl;
	// MOSTRAR CONJUNTO B
	cout << "B={";
	for(int i=0; i<largo2;i++){
		cout << B[i] << " ";
	}
	cout << "}" <<endl;
	cout <<endl;
	r=largo*largo2;
	cout << "An * Bn =(" <<largo <<"*" <<largo2 <<")=" <<r <<" Pares Ordenados" <<endl;
	cout <<endl;
	// GENERAR PARES ORDENADOS
	cout << "A * B = {";
	z=0;
	for(int i=0; i<largo;i++){
		for(int j=0;j<largo2;j++){
			cout <<"(" <<A[i] <<"," <<B[j] <<"),";
			z++;
			if(z==8){
				cout <<endl;
				z=0;
			}	
		}
	}
	cout << "}";
	system("pause>nul");
	
}
//funcion Recursiva de Numeros Primos
bool esprimo( int x, int tmp = 0 ) {
  if( x == 1 )
    return true;
 if( !tmp ) {
    tmp = x;
    --x;
  }
  if( !( tmp % x ) )
    return false;
  return esprimo( --x, tmp );
}
//funcion Factores Primos
void FactoresPrimos(int x){
	int i=2,numero,resultado,i_fact; 
	int fact1[10];
	string operacion;
	numero=x;
	cout <<endl;
	i_fact=0;
  	while(i<=numero)
  	{
    	if((numero%i)==0)  //Verificamos que la division no tenga residuo, sino elegimos otro numero para dividir
    	{
    		printf("%5d", numero); 
    		fact1[i_fact]=i;  //Añadimos el factor al arreglo.
    		numero=numero/i;  //Dividimos por el factor
    		cout <<"|";
    		printf("%5d", i);
    		//operacion=operacion+i;
    		cout <<endl;
    		i_fact++;            //Incrementamos indice de arreglo para el siguiente numero.
        	continue;
    	}     
  		i++;
  	}
  	printf("%5d", numero);
  	cout <<endl;
	cout <<endl;
  	i=0; 
	resultado=1;    
	while(i<i_fact)
  	{
  	   if(i>0){
  	   	 cout <<"X";		
	   }	
  	   printf(" %d ", fact1[i]);
  	   resultado*=fact1[i];
	   i++;
  	}
  	cout <<" = " <<resultado;
  	cout <<endl;
  	system("pause>nul");
}
//funcion para encotrar Maximo Comun Divisor
void MCD(int n,int r){
	int fact1[10];
	int fact2[10];
	int i=2,num1,num2,resultado,ind1,ind2; 
	num1=n;
	num2=r;
	// factores primos primer numero
	cout <<endl;
	ind1=0;
  	while(i<=num1)
  	{
    	if((num1%i)==0)  //Verificamos que la division no tenga residuo, sino elegimos otro numero para dividir
    	{
    		printf("%5d", num1); 
    		fact1[ind1]=i;  	//Añadimos el factor al arreglo.
    		num1=num1/i;  		//Dividimos por el factor
    		cout <<"|";
    		printf("%5d", i);
    		cout <<endl;
    		ind1++;           //Incrementamos indice de arreglo para el siguiente numero.
        	continue;
    	}     
  		i++;
  	}
  	printf("%5d", num1);
  	cout <<endl;
  	cout <<endl;
  	// Mostramos la operacion de los factores
  	i=0; 
	resultado=1;    
	while(i<ind1)
  	{
  	   if(i>0){
  	   	 cout <<"X";		
	   }	
  	   printf(" %d ", fact1[i]);
  	   resultado*=fact1[i];
	   i++;
  	}
  	cout <<" = " <<resultado;
  	cout <<endl;
  	i=2;
  	// factores primos segundo numero
  	ind2=0;
	cout <<endl;
  	while(i<=num2)
  	{
    	if((num2%i)==0)  //Verificamos que la division no tenga residuo, sino elegimos otro numero para dividir
    	{
    		printf("%5d", num2); 
    		fact2[ind2]=i;  //Añadimos el factor al arreglo.
    		num2=num2/i;  //Dividimos por el factor
    		cout <<"|";
    		printf("%5d", i);
    		cout <<endl;
    		ind2++;            //Incrementamos indice de arreglo para el siguiente numero.
        	continue;
    	}     
  		i++;
  	}
  	printf("%5d", num2);
  	cout <<endl;
  	cout <<endl;
  	//Mostramos la multiplicacion de los factores del segundo numero
  	i=0;
	resultado=1;   
	while(i<ind2)
  	{
  	   if(i>0){
  	   	 cout <<"X";		
	   } 	
  	   printf(" %d ", fact2[i]);
  	   resultado*=fact2[i];
	   i++;
  	}
  	cout <<" = " <<resultado;
  	cout <<endl;
  	cout <<endl;
  	// Verificamos que factores son iguales en cada uno de los factores
  	// de cada numero para encontrar el maximo comun divisor
  	cout <<"M.C.D(" <<n <<"," <<r <<")=";
  	resultado=1;
  	if (ind1<ind2){
  		int x=0;
  		for(i=0;i<ind1;i++){
  			
  			for(x;x<ind2;x++){
  				if(fact1[i]==fact2[x]){
  					if(i>0){
  	   	 			  cout <<"X";		
	   				} 
  					printf(" %d ", fact1[i]);
  					resultado*=fact1[i];
  					x++;
  					break;
		  		}		
			}
		}
  		cout <<" = " <<resultado;
  		cout <<endl;
  		cout <<endl;
	}else if(ind2<ind1){
		int x=0;
  		for(i=0;i<ind2;i++){
  			for(x;x<ind1;x++){
  				if(fact2[i]==fact1[x]){
  					if(i>0){
  	   	 			  cout <<"X";		
	   				} 
  					printf(" %d ", fact2[i]);
  					resultado*=fact2[i];
  					x++;
  					break;
		  		}		
			}
		}
  		cout <<" = " <<resultado;
  		cout <<endl;
  		cout <<endl;
	}else if(ind1=ind2){
		for(i=0;i<ind2;i++){
			if(fact1[i]==fact2[i]){
				if(i>0){
  	   	 			  cout <<"X";		
	   			} 
  				printf(" %d ", fact2[i]);
  				resultado*=fact2[i];
	  		}		
		}
		cout <<" = " <<resultado;
  		cout <<endl;
  		cout <<endl;
	}
  	system("pause>nul");
}
//funcion Algoritmo de la Division
void AlgoritmoDivision(int n,int z){
	div_t resultado;
	int a,b,q,r,total;
	a=n;
	b=z;
	if(b!=0){
		resultado=div(a,b);
		q=resultado.quot;
		r=resultado.rem;
		cout <<endl;
		cout <<"Variables ===" <<endl;
		cout <<"a = " <<a <<endl;
		cout <<"b = " <<b <<endl;
		cout <<"q = " <<q <<endl;
		cout <<"r = " <<r <<endl;
		cout <<endl;
		cout <<"Formula ===" <<endl;
		cout << "a = (b * q) + r" <<endl;
		cout <<endl;
		total = (b * q)+r;
		cout << a <<" = (" <<b <<" * " <<q <<") + " <<r <<endl;
		cout <<endl;
		cout << a <<" = " <<total <<endl;
	}else{
		cout <<"ERROR - no puede dividr por 0" <<endl;
	}
	system("pause>nul");
}
//funcion Algoritmo de Euclides
int Euclides(int a, int b) {
	// guardamos b en una temporal para no perderla
	// Tecnica para encontrar el MCD de dos enteros
	// lo que hace el algoritmo es verificar que ambos
	// A y B sean diferentes de 0
	// luego divide A entre B y si la division tiene residuo
	// A pasa a ser B y B pasa a ser igual que el residuo
	// y se repite nuevamente el proceso
	// y si el residuo de la division es 0
	// se detiene y muestra a A como el MCD de ambos numeros
    int temporal; 
    while (b != 0) {
        temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}
//funcion Induccion Matematica
void Induccion(string formula){
	int a,l,largo,resultado;
	char caracter='n';
	char operador;
	string nueva,hipotesis,tesis;
	largo = formula.size();
	resultado=0;
	l=0;
	for(int i=0; i<largo;i++){
		if(isdigit(formula[i]) || formula[i]==caracter){
			if (formula[i]==caracter){
				a=1;
			}else{
				stringstream ss;
				ss << formula[i];
				ss >> a;	
			}
			if(l==0){
				//primer numero
				resultado = resultado + a;		
			}else if(l==1){
				//potencia
				resultado = pow(resultado,a);
			}else if(l==2){
				//suma
				resultado = resultado + a;
			}else if(l==3){
				//resta
				resultado = resultado - a;
			}else if(l==4){
				//multiplicacion
				resultado = resultado * a;
			}else if(l==5){
				//division
				resultado = resultado / a;
			}
		}else{
			operador=formula[i];
			switch(operador){
				case '^':
					l=1;
					break;
				case '+':
					l=2;
					break;
				case '-':
					l=3;
					break;
				case '*':
					l=4;
					break;
				case '/':
					l=5;
					break;
			}
		}
	}
	//paso 1
	cout <<endl;
	cout <<"\n\tPaso 1 - Comprobacion n=1";
	cout <<"\n\t-------------------------\n";
	for(int i=0; i<largo;i++){
		if(formula[i]==caracter){
			nueva=nueva+'1';
		}else{
			nueva=nueva+formula[i];
		}
	}
	cout <<"\t" << nueva <<" = " <<resultado;
	//hipotesis n = k
	cout <<endl;
	cout <<"\n\tPaso 2 - Hipotesis";
	cout <<"\n\t------------------";
    cout <<endl;
	for(int i=0; i<largo;i++){
		if(formula[i]==caracter){
			hipotesis=hipotesis+'k';
		}else{
			hipotesis=hipotesis+formula[i];
		}
	}
	cout <<"\t" <<hipotesis;
	//tesis n = k + 1
	cout <<endl;
	cout <<"\n\tPaso 3 - Tesis\n";
	cout <<"\n\t--------------";
    cout <<endl;
	for(int i=0; i<largo;i++){
		if(formula[i]==caracter){
			tesis=tesis+"(k+1)";
		}else{
			tesis=tesis+formula[i];
		}
	}
	cout <<"\t" <<tesis;
	//comprobacion
	cout <<endl;
	cout <<"\n\tPaso 4 - Demostracion\n";
	cout <<"\n\t---------------------";
    cout <<endl;
	cout <<"\t"  <<hipotesis <<" = " <<tesis;
}
// Metodo Principal Main, Menu del sistema
int main()
{   
	int y,x;
	string palabra,palabra2;
	
	int opcion;
    bool repetir = true;

    do
    {
        system("cls");
		
		cout << "\n\n\t\t\tMenu de Opciones" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\t 1. Principio Fundamental de la Suma" << endl;
        cout << "\t 2. Principio Fundamental de la Multiplicacion" << endl;
        cout << "\t 3. Permutacion con Repeticion" << endl;
        cout << "\t 4. Permutacion sin Repeticion" << endl;
        cout << "\t 5. Combinacion sin Repeticion" << endl;
        cout << "\t 6. Combinacion con Repeticion" << endl;
        cout << "\t 7. Binomio de Newton" << endl;
        cout << "\t 8. Triangulo de Pascal" << endl;
        cout << "\t 9. Determinar Coeficiente Binomial" << endl;
        cout << "\t10. Operaciones con Conjuntos" << endl;
        cout << "\t11. Producto Cartesiano" << endl;
        cout << "\t12. Principio de Induccion Matematica" << endl;
        cout << "\t13. Funcion Recursiva Numeros Primos" << endl;
        cout << "\t14. Representar Numero Entero en Factores Primos" << endl;
        cout << "\t15. Maximo Comun Divisor" << endl;
        cout << "\t16. Algoritmo de la Division" << endl;
        cout << "\t17. Algoritmo de EUCLIDES" << endl;
        cout << endl;
        cout << endl;
        cout << "\t0. SALIR" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        int numero1, numero2;
        float resultado;
        switch (opcion)
        {
        case 1:
        	system("cls");
        	cout << "\n\tPRINCIPIO FUNDAMENTAL DE LA SUMA";
    		cout << "\n\t================================\n";
        	cout <<endl;
            cout << "Cantidad de Incognitas a Evaludar Maximo 5 " <<endl;
    		cin >> y;
    	    principioSuma(y);
            break;

        case 2:
        	system("cls");
        	cout << "\n\tPRINCIPIO FUNDAMENTAL DE LA MULTIPLICACION";
    		cout << "\n\t==========================================\n";
    		cout <<endl;
            cout << "Cantidad de Incognitas a Evaludar Maximo 5 " <<endl;
    		cin >> y;
    		principioMultiplicacion(y);
            break;

        case 3:
        	system("cls");
        	cout << "\n\tPERMUTACION CON REPETICION";
    		cout << "\n\t==========================\n";
    		cout <<endl;
    		cout << "Que Ejemplo quiere Realizar 1 o 2, formula n^r" <<endl;
    		cout << "Que Ejemplo quiere Realizar 3    , formula n!/(n1!n2!..nk!)) " <<endl;
    		cin >> y;
    		permutacionConRepeticion(y);
            break;

        case 4:
        	system("cls");
            cout << "\n\tPERMUTACION SIN REPETICION";
    		cout << "\n\t==========================\n";
    		cout <<endl;
    		cout << "Que Ejemplo quiere Realizar 1 o 2, formula (n!) " <<endl;
    		cout << "Que Ejemplo quiere Realizar 3 y 4, formula (n!/(n-r)!)) " <<endl;
    		cin >> y;
    		permutacionSinRepeticion(y);
            break;
		case 5:
			system("cls");
            cout << "\n\tCOMBINACION SIN REPETICION";
    		cout << "\n\t==========================\n";
    		cout <<endl;
    		cout << "Que Ejemplo quiere Realizar 1 o 2" <<endl;
    		cin >> y;
    		nCr(y);
            break;
		case 6:
			system("cls");
            cout << "\n\tCOMBINACION CON REPETICION";
    		cout << "\n\t==========================\n";
    		cout <<endl;
    		cout << "Que Ejemplo quiere Realizar 1 o 2" <<endl;
    		cin >> y;
    		Cnr(y);
            break;
		case 7:
			system("cls");
            cout << "\n\tBINOMIO DE NEWTON";
    		cout << "\n\t=================\n";
    		cout <<endl;
    		cout <<"Ingrese el Binomio a Desarrollar" <<endl;
    		cin >> palabra;
    		cout <<"Ingrese el exponente del Binomio" <<endl;
    		cin >> y;
    		cout <<"   El Polinomio desarrollado es el siguiente" <<endl;
    		cout <<endl;
    		BinomioNewton(palabra,y);
            break;			            
		case 8:
			system("cls");
            cout << "\n\tTRIANGULO DE PASCAL";
    		cout << "\n\t===================\n";
    		cout <<endl;
    		cout << "Ingrese el Valor del Coeficiente a Calcular" <<endl;
    		cin >> y;
    		Pascal(y);
            break;			            
		case 9:
            system("cls");
            cout << "\n\tDETERMINAR COEFICIENTE BINOMIAL";
    		cout << "\n\t=================================\n";
    		cout <<endl;
    		cout << "Determine el Coeficiente Binomial de: " <<endl;
    		cin >> palabra;
    		cout << "En el Desarrollo de: " <<endl;
    		cin >> palabra2;
    		cout <<endl;
    		findCoeficiente(palabra,palabra2);
            break;			            
		case 10:
            system("cls");
            cout << "\n\tOPERACIONES CON CONJUNTOS";
    		cout << "\n\t=================================\n";
    		cout <<endl;
    		conjuntos();
            break;			            			            
		case 11:
            system("cls");
            cout << "\n\tPRODUCTO CARTESIANO";
    		cout << "\n\t=================================\n";
    		cout <<endl;
    		ProductoCartesiano();
            break;			            			            
		case 12:
			system("cls");
            cout << "\n\tPRINCIPIO DE INDUCCION MATEMATICA";
    		cout << "\n\t=================================\n";
    		cout <<endl;
    		cout << "Ingrese la Formula a Evaluar" <<endl;
    		cin >> palabra;
    		cout <<endl;
			Induccion(palabra);
			system("pause>nul");
            break;			            			            
		case 13:
    		do{
    			system("cls");
            	cout << "\n\tFUNCION RECURSIVA NUMEROS PRIMOS";
    			cout << "\n\t=================================\n";
    			cout <<endl;
    			cout << "Ingrese un Numero para Comprobar si es Primo, 0 para Finalizar" <<endl;
    			cin >> y;
    			if(y==0){
    				break;
				}
    			if(esprimo(y)){
    				cout << "El Numero Ingresado es Primo" <<endl;
				}else{
					cout << "No es Numero Primo" <<endl;
				}	
				system("pause>nul");
			}while (true);    		
            break;			            			            
		case 14:
            system("cls");
            cout << "\n\tREPRESENTAR ENTERO EN FACTORES PRIMOS";
    		cout << "\n\t======================================\n";
    		cout <<endl;
    		cout << "Ingrese un Numero Entero" <<endl;
    		cin >> y;
    		FactoresPrimos(y);
            break;			            			            									            
        case 15:
        	system("cls");
            cout << "\n\tMAXIMO COMUN DIVISOR";
    		cout << "\n\t====================\n";
    		cout <<endl;
    		cout << "Ingrese Primer Numero Entero" <<endl;
    		cin >> y;
    		cout << "Ingrese Segundo Numero Entero" <<endl;
    		cin >> x;
    		MCD(y,x);
            break;			            			            									                
		case 16:
            system("cls");
            cout << "\n\tALGORITMO DE LA DIVISION";
    		cout << "\n\t========================\n";
    		cout <<endl;
    		cout << "Ingrese El Dividendo" <<endl;
    		cin >> x;
    		cout << "Ingrese El Divisor" <<endl;
    		cin >> y;
    		AlgoritmoDivision(x,y);
            break;			            			            									                        
		case 17:
			do{
    			system("cls");
            	cout << "\n\tALGORITMO DE EUCLIDES";
    			cout << "\n\t=====================\n";
    			cout <<endl;
    			cout << "Ingrese Primer Numero Entero, 0 para Terminar" <<endl;
    			cin >> x;
    			if(x==0){
    				break;
				}
    			cout << "Ingrese Segundo Numero Entero" <<endl;
    			cin >> y;
    			cout << "M.C.D.(" <<x <<"," <<y <<")=" <<Euclides(x,y) <<endl;
				system("pause>nul");
			}while (true);    	
            break;			            			            									                        
        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
    return 0;
}
