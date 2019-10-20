#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class UnionFind{
private:

   int *vetorVertice, tamanho;

public:
  UnionFind(){};
  UnionFind(int tamanho){
    this->tamanho = tamanho;
    vetorVertice = new int[tamanho+1];
    for(int i = 1; i <= tamanho;i++){
        vetorVertice[i] = i;
    }
  }

   int getTamanho();
   int busca(int);
   void une(int,int);

};

template <class T>
int UnionFind<T>::getTamanho() {
    return tamanho;
}

template <class T>
int UnionFind<T>::busca(int vertice) {
    if(vetorVertice[vertice] == vertice){
        return vertice;
    }
    return busca(vetorVertice[vertice]);
}

template <class T>
void UnionFind<T>::une(int vertice1, int vertice2) {
    int valorVertice1 = busca(vertice1);
    int valorVertice2 = busca(vertice2);

    vetorVertice[valorVertice1] = valorVertice2;
}


//------------------------------------------------------------------------fim union find-----------------------------------------------------------------------

template<class T>
class Aresta{
private:

    T vertice1;
    T vertice2;
    double peso ;

public:
    Aresta(){}
    Aresta(T vertice1,T vertice2,double peso){
        this->vertice1= vertice1;
        this->vertice2= vertice2;
        this->peso= peso;
    }
    void setVertice1(T vertice);
    void setVertice2(T vertice);
    void setPeso(double peso);
    T getVertice1();
    T getVertice2();
    double getPeso();
};

template <class T>
void Aresta<T>::setVertice1(T vertice){
     this->vertice1 = vertice;
}

template <class T>
void Aresta<T>::setVertice2(T vertice){
     this->vertice2 = vertice;
}

template <class T>
void Aresta<T>::setPeso(double peso){
     this->peso = peso;
}

template<class T>
T Aresta<T>::getVertice1() {
     return vertice1;
}

template<class T>
T Aresta<T>::getVertice2() {
     return vertice2;
}

template<class T>
double Aresta<T>::getPeso() {
     return peso;
}

//----------------------------------------------------------------------------------------------
template <class T>
class Grafo{
private:
    double **matriz;
    Aresta<T> *vet;
    int ordem, tamanho,aux = 0;
    void inicializador();

public:
    Grafo(){}
    Grafo(int ordem,int tamanho){
       this->ordem = ordem;
       this->tamanho = tamanho;
       vet = new Aresta<T>[tamanho+1];
       matriz = new double*[ordem+1];
       for(int i = 1; i <= ordem; i++){
                matriz[i] = new double[ordem+1];
        }
       inicializador();
    }
    int getOrdem();
    double** getMatriz();
    void insereAresta(T,T,double);
    void print();
    int getTamanho();
    Aresta<T>* getVet();
    void setVet(Aresta<T>*);
};

template <class T>
void Grafo<T>::setVet(Aresta<T>* vetAux){
   this->vet = vetAux;
}

template <class T>
Aresta<T>* Grafo<T>::getVet(){
   return vet;
}

template <class T>
void Grafo<T>::inicializador(){
    for(int i = 1;i <= ordem; i++){
        for(int j = 1; j <= ordem; j++){
            matriz[i][j] = 0;
        }
    }
}

template <class T>
void Grafo<T>::insereAresta(T u, T v, double peso){
    matriz[u][v] = peso;
    matriz[v][u] = peso;
    vet[aux].setVertice1(u);
    vet[aux].setVertice2(v);
    vet[aux].setPeso(peso);
    aux++;

}

template <class T>
int Grafo<T>::getOrdem(){
    return ordem;
}

template <class T>
int Grafo<T>::getTamanho(){
    return tamanho;
}

template <class T>
double** Grafo<T>::getMatriz(){
    return matriz;
}

template <class T>
void Grafo<T>::print(){

    cout << " ";

    for(int i = 1; i <= ordem; i++){
        cout <<  i << "   ";

    }
     cout << endl;

    for(int i = 1; i <= ordem; i++){
        cout <<  i << " ";
        for(int j = 1; j <= ordem; j++){
            cout << matriz[i][j]<< "  ";
        }
        cout << endl;
    }
}

//-------------------------------------------------------------------------------------------------------------

template <class T>
class Kruskal {

private:
      Aresta<T>*  vetKruskal;
      double** matriz;
      int tam,ordem;
      double pesoMST;
public:
       Kruskal (){}
       Kruskal (Aresta<T>* vet,int tam, int ordem){
           this->vetKruskal = vet;
           this->ordem = ordem;
           this->tam = tam;
           this->pesoMST = 0;

       }
       double** getMatriz();
       void setMatriz(double**);
       void ordenaVetor(Aresta<T>*, int);
       void executaKruskal();
       int getTam();
       int getOrdem();
       double getpesoMST();
       Aresta<T>* getvetKruskal();
       void setPesoMST(double peso);
       void setvetKruskal(Aresta<T>*);
       void chamaKruskal ();

};

template <class T>
double** Kruskal<T>::getMatriz(){
    return this->matriz;
}

template <class T>
void Kruskal<T>::setMatriz(double** mat){
    this->matriz = mat;
}

template <class T>
void Kruskal<T>::setvetKruskal(Aresta<T>* vet){
    this->vetKruskal = vet;
}

template <class T>
int Kruskal<T>::getOrdem(){
    return this->ordem;
}

template <class T>
void Kruskal<T>::chamaKruskal (){


   executaKruskal();


}


template <class T>
void Kruskal<T>::ordenaVetor(Aresta<T>* vetor, int tam){

  int vert1,vert2;
  double peso;

  for(int i=0;i<tam-1;i++){
    for(int j=0;j<tam-i-1;j++){
      if (vetor[j].getPeso() > vetor[j+1].getPeso()) {

        vert1 = vetor[j].getVertice1();
        vert2 = vetor[j].getVertice2();
        peso = vetor[j].getPeso();

        vetor[j].setVertice1(vetor[j+1].getVertice1());
        vetor[j].setVertice2(vetor[j+1].getVertice2());
        vetor[j].setPeso(vetor[j+1].getPeso());

        vetor[j+1].setVertice1(vert1);
        vetor[j+1].setVertice2(vert2);
        vetor[j+1].setPeso(peso);


      }
    }
  }
}

template <class T>
int Kruskal<T>::getTam(){
    return this->tam;
}

template <class T>
void Kruskal<T>::setPesoMST(double peso){
   this->pesoMST = peso;
}

template <class T>
double Kruskal<T>::getpesoMST(){
    return this->pesoMST;
}


template <class T>
Aresta<T>* Kruskal<T>::getvetKruskal(){
    return vetKruskal;
}

template <class T>
void Kruskal<T>::executaKruskal(){

        Aresta<T>* vet = getvetKruskal();
        int tam = getTam();
        int ordem = getOrdem();
        Aresta<T> arvore[tam];
        UnionFind<T> une(ordem);
        int h = 0;
		double soma =0;


	  ordenaVetor(vet,tam);

	  for(int i = 0; i < tam; i++)
		{
			int v1 = une.busca(vet[i].getVertice1());
			int v2 = une.busca(vet[i].getVertice2());

			if(v1 != v2)
			{
				// se diferentes NÃO forma ciclo, insere no vetor
				arvore[i].setVertice1(vet[i].getVertice1());
				arvore[i].setVertice2(vet[i].getVertice2());
				arvore[i].setPeso(vet[i].getPeso());
				h++;
				une.une(v1, v2); // une os subconjuntos
			    soma = soma + vet[i].getPeso();

			}
		}
        for (int i = 0; i<h;i++){
            cout <<"VERTICE 1= "<<arvore[i].getVertice1()<<" "<<"VERTICE 2= "<<arvore[i].getVertice2()<<" "<<"PESO= "<<arvore[i].getPeso()<<"\n";
        }
		cout <<"soma da arvore minima = "<< soma;
		setPesoMST(soma);
}


//-------------------------------------------------------------fim kruskal----------------------------------------------

int main(){

Grafo<int> g(5,5);

 g.insereAresta(1, 2, 2);
   g.insereAresta(2, 4, 4);
   g.insereAresta(1, 4, 3);
   g.insereAresta(1, 3, 3);
   g.insereAresta(2, 5, 2);
   g.insereAresta(3, 5, 3);



g.print();

Kruskal <int> k (g.getVet(),g.getTamanho(),g.getOrdem());

k.chamaKruskal();



  return 0;
}

