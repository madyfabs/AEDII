#include <iostream>
#include <limits>


using namespace std;

class Par {

private:

    int vertice;
    double peso;

public:

    Par(){}
    Par (int vertice, double peso){
       this->vertice = vertice;
       this->peso = peso;
    }

    int getVertice();
    double getPeso();
    void imprime();

};

void Par::imprime(){
    cout <<"v = "<<vertice <<" "<<"peso= "<<peso<<"\n";
}

int Par::getVertice(){
  return this->vertice;
}


double Par::getPeso(){
  return this->peso;
}


//---------------------------------------------------------------------------------------------------


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
class No {

private:

    T item;
    No<T>* prox;

public:


    No<T>(){

      this->prox = NULL;
    }

    No<T> (T item){

       this->item = item;
       prox = NULL;

    }

    T getItem();
    No<T>* getProx();
    void setItem(T item);
    void setProx (No<T>* prox);
    void setNULL();
    void setNovoNo();



};

template <class T>
T No<T>::getItem(){

  return this->item;
}

template <class T>
No<T>* No<T>::getProx(){
   return prox;
}

template <class T>
void No<T>::setItem(T item){
   this->item = item;
}

template <class T>
void No<T>::setProx(No<T>* prox){
   this->prox = prox;
}

template <class T>
void No<T>::setNULL (){
  this->prox = NULL;
}

template <class T>
void No<T>::setNovoNo (){
 this->prox = new No<T>();
}


//-------------------------------------------------------------------------------

template <class T>
class Fila{

 private:

    No<T> *tras, *frente;
    int TAM;

public:

    Fila (){
      TAM = 0;
      frente = new No<T>();
      frente->setNULL();
      tras = frente;

    }

    void Enfileira (T item);
    T Desinfileira();
    void ImprimeFila();
    bool vazia();


};

template <class T>
bool Fila<T>::vazia(){
  return tras == frente;
}

template <class T>
void Fila<T>::Enfileira(T item){

   tras->setNovoNo();
   tras = tras->getProx();
   tras->setItem(item);
   tras->setNULL();
   TAM++;

}

template <class T>
T Fila<T>::Desinfileira(){


    No<T>* aux = frente;
    T p;

    if (frente == tras){

        cout <<"Fila Vazia \n";
    }else{
    p = frente->getProx()->getItem();
    frente = frente->getProx();
    delete aux;
    return p;
    }


}

template <class T>
void Fila<T>::ImprimeFila(){

   No<T>* p = frente->getProx();

   while (p != NULL){


    p->getItem().imprime(); //mudar
    p = p->getProx();

   }
}

//-------------------------------------------------------------------------------
template <class T>
class Grafo{
private:
    double **matriz;
    Aresta<T> *vet;
    int ordem, tamanho=0;
    void inicializador();

public:
    Grafo(){}
    Grafo(int ordem){
       this->ordem = ordem;
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
    tamanho++;
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

//--------------------------------------------------------------------------------------------FIM GRAFU---------------------------------------

template <class T>
class Dijkstra{

private:

    int *vetPred,*vetCaminho;
    double *vetDist;
    Grafo<T> grafoD;
    int ordem, tam;


public:

       Dijkstra(){}
       Dijkstra (Grafo<T> grafo, int ordem, int tamanho){

             this->grafoD = grafo;
             this->ordem = ordem;
             this->tam = tamanho;

       }

       void getCaminhoMin(int);
       void executaDijkstra(int);
       void setvetDist(double*);
       void setvetPred(int*);
       void setvetCaminho(int*);
       void setGrafo(Grafo<T>);
       void setOrdem(int);
       void setTam(int);
       double* getvetDist();
       int* getvetPred();
       int* getvetCaminho();
       Grafo<T> getGrafo();
       int getOrdem();
       int getTam();
};

template <class T>
void Dijkstra<T>::executaDijkstra(int inicio){

     Fila<Par> filap;
     int *prede;
     double *dist;
     Par u;

     dist = new double[getOrdem()+1];
     prede = new int[getOrdem()+1];

     for (int i = 1; i <=getOrdem(); i++){

        dist[i] = numeric_limits<double>::max();
        prede[i] = -1;
     }

     dist[inicio] = 0;
     Par p(inicio,0);
     filap.Enfileira(p);

     while (!filap.vazia()){

        u = filap.Desinfileira();

        for(int v=1;v<=getOrdem();v++){


          double w = getGrafo().getMatriz()[u.getVertice()][v];

          if(w >  0){

             if(dist[v] > (dist[u.getVertice()] + w)){
             dist[v] = dist[u.getVertice()] + w;
             prede[v] = u.getVertice();
             Par aux(v,dist[v]);
             filap.Enfileira(aux);
             }
         }

      }
    }
    for (int i = 1; i<=getOrdem();i++){
        cout <<"distancia do V"<<inicio<< "  ao V"<<i<< " ="<<dist[i]<<"\n";
    }
    setvetDist(dist);
    setvetPred(prede);
}

template <class T>
void Dijkstra<T>::getCaminhoMin(int destino){

    int *vetaux = new int[getOrdem()+1];
    int x =2;
    double soma =0;

    vetaux[1] = destino;

    int minimo = getvetPred()[destino];
    while(minimo != -1){
      vetaux[x] = minimo;
      minimo = getvetPred()[minimo];
      x++;
    }

    cout <<"CAMINHO MINIMO ";
    for (int i = 1; i<x;i++){
        cout <<" PASSA PELO V "<< vetaux[i] <<" ";
    }

    soma = getvetDist()[destino];

    cout <<" E tem valor total = "<<soma;


}

template <class T>
void Dijkstra<T>::setvetDist(double* vet){
   this->vetDist = vet;
}

template <class T>
void Dijkstra<T>::setvetPred (int* pred){
   this->vetPred = pred;
}

template <class T>
void Dijkstra<T>::setvetCaminho(int* cami){
   this->vetCaminho = cami;
}

template <class T>
void Dijkstra<T>::setGrafo(Grafo<T> grafo){
   this->grafoD = grafo;
}

template <class T>
void Dijkstra<T>::setOrdem(int ordem){
   this->ordem = ordem;
}

template <class T>
void Dijkstra<T>::setTam(int tam){
   this->tam = tam;
}

template <class T>
double* Dijkstra<T>::getvetDist(){
   return this->vetDist;
}

template <class T>
int* Dijkstra<T>::getvetPred(){
   return this->vetPred;
}

template <class T>
int* Dijkstra<T>::getvetCaminho(){
   return this->vetCaminho;
}

template <class T>
Grafo<T> Dijkstra<T>::getGrafo(){
   return this->grafoD;
}

template <class T>
int Dijkstra<T>::getOrdem(){
   return this->ordem;
}

template <class T>
int Dijkstra<T>::getTam(){
   return this->tam;
}

//------------------------------------------------------------------------------------------------------------------------
int main(){

Grafo<int> g(5);

g.insereAresta(1,2,1);
g.insereAresta(2,3,99);
g.insereAresta(3,4,1);
g.insereAresta(4,5,99);
g.insereAresta(2,5,1);
g.insereAresta(5,4,1);


/*
g.insereAresta(1, 3, 1.0);
g.insereAresta(1, 9, 1.0);
g.insereAresta(1, 15, 1.0);
g.insereAresta(1 ,16, 1.0);
g.insereAresta(1 ,17, 1.0);
g.insereAresta(2 ,4 ,99.0);
g.insereAresta(2, 5, 99.0);
g.insereAresta(2 ,11 ,99.0);
g.insereAresta(2, 12, 99.0);
g.insereAresta(2 ,18, 99.0);
g.insereAresta(3, 8 ,1.0);
g.insereAresta(3 ,9, 1.0);
g.insereAresta(3 ,14, 1.0);
g.insereAresta(4, 5, 99.0);
g.insereAresta(4 ,6, 99.0);
g.insereAresta(4 ,7, 99.0);
g.insereAresta(4 ,9, 99.0);
g.insereAresta(4 ,15 ,99.0);
g.insereAresta(5, 7, 1.0);
g.insereAresta(5, 12, 1.0);
g.insereAresta(5 ,14, 1.0);
g.insereAresta(5 ,15, 1.0);
g.insereAresta(6, 7, 1.0);
g.insereAresta(6, 9, 1.0);
g.insereAresta(7 ,8, 99.0);
g.insereAresta(7, 12, 99.0);
g.insereAresta(7, 13, 99.0);
g.insereAresta(7 ,15, 99.0);
g.insereAresta(7 ,17, 99.0);
g.insereAresta(8, 11, 1.0);
g.insereAresta(8, 12 ,1.0);
g.insereAresta(8 ,14 ,1.0);
g.insereAresta(9 ,10, 99.0);
g.insereAresta(9 ,11, 99.0);
g.insereAresta(9 ,12, 99.0);
g.insereAresta(9 ,13, 99.0);
g.insereAresta(9 ,14 ,99.0);
g.insereAresta(10, 14, 1.0);
g.insereAresta(10 ,15, 1.0);
g.insereAresta(11, 12, 99.0);
g.insereAresta(11 ,13, 99.0);
g.insereAresta(11 ,16, 99.0);
g.insereAresta(11 ,18, 99.0);
*/

g.print();


Dijkstra<int> d(g,g.getOrdem(),g.getTamanho());
d.executaDijkstra(1); //aqui quando tu montar tu passa o vertice inicial;
d.getCaminhoMin(3); //aqui tu passa o destino;


  return 0;
}
