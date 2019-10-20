#include <iostream>
#include <limits>

using namespace std;

template <class T>
class Par {

private:

    int vertice;
    int peso;

public:

    Par(){}
    Par (int vertice, int peso){
       this->vertice = vertice;
       this->peso = peso;
    }

    void setVertice(int v);
    void setPeso(int p);
    int getVertice();
    int getPeso();
    void imprime();
};

template <class T>
void Par<T>::setVertice(int v){
  this->vertice = v;
}

template <class T>
void Par<T>::setPeso(int p){
    this->peso=p;
}

template <class T>
int Par<T>::getVertice(){
  return this->vertice;
}

template <class T>
int Par<T>::getPeso(){
  return this->peso;
}

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

template <class T>
class FilaP{

 private:

    No<T> *tras, *frente;
    int tamHeap;

public:

    FilaP (){
      tamHeap = 0;
      frente = new No<T>();
      frente->setNULL();
      tras = frente;

    }

    void enfileira (T item);
    T desinfileira();
    No<T>* getFrente();
    int getPai(int i);
    int getEsq(int i);
    int getDir(int i);
    bool vazia();
    void heapficaMin(int valor);
    double busca(int i);
    void diminuiValor(int valor);
    void mudaValor(int i,int valor);
};

template<class T>
No<T>* FilaP<T>::getFrente(){
    return frente;
}

template<class T>
double FilaP<T>::busca(int i){

    No<T> *p = getFrente()->getProx();

    int cont = 1;
    int contido;

    while(p != NULL){
      if(cont == i){
         contido = p->getItem().getPeso();
         break;
       }
      cont++;
      p = p->getProx();
    }
  return contido;
}

template <class T>
bool FilaP<T>::vazia(){
  return tras == frente;
}

template <class T>
void FilaP<T>::enfileira(T item){

   tras->setNovoNo();
   tras = tras->getProx();
   tras->setItem(item);
   tras->setNULL();
   tamHeap++;
   diminuiValor(tamHeap);
}

template <class T>
int FilaP<T>::getPai(int i){
    return i/2;
}

template <class T>
int FilaP<T>::getEsq(int i){
    return 2*i;
}

template <class T>
int FilaP<T>::getDir(int i){
    return 2*i+1;
}

template <class T>
void FilaP<T>::diminuiValor(int valor){

    int x,y;
    int p;

    if(valor == 1){
       return;
    }

     p = getPai(valor);
     x = busca(valor);
     y = busca(p);

    if(x > y){

        mudaValor(valor,y);
        mudaValor(p,x);
        diminuiValor(p);
    }
}

template<class T>
void FilaP<T>::mudaValor(int i,int valor){

    No<T> *p = getFrente()->getProx();

    int cont = 1;

    while(p != NULL){
      if(cont == i){
         p->getItem().setPeso(valor);
         break;
      }
      cont++;
      p = p->getProx();
    }
}

template <class T>
void FilaP<T>::heapficaMin(int valor){

    int dir1,esq1,menor;
    int i,j,dir2,esq2,menor2;

     menor = valor;
     dir1 = getDir(valor);
     esq1 = getEsq(valor);

     dir2 = busca(dir1);
     esq2 = busca(esq1);

     menor2 = busca(menor);

    if(dir1 <= tamHeap && dir2 < menor2){
            menor = dir1;
      }

    if(esq1 <= tamHeap && esq2 < menor2){
        menor = esq1;
    }

    if(menor != valor){

       i = busca(valor);
       j = busca(menor);
       mudaValor(valor,j);
       mudaValor(menor,i);

        heapficaMin(menor);
    }
}

template <class T>
T FilaP<T>::desinfileira(){

    No<T>* aux = frente;
    T item;

    if (frente == tras){

      cout <<"Vazia \n";
    }
    else {
      item = frente->getProx()->getItem();
      frente = frente->getProx();
      delete aux;
      tamHeap--;

    return item;
    }
  return item;
}
template <class T>
class Grafo{
private:
    int **matriz;
    int ordem, tamanho=0;
    void inicializador();

public:
    Grafo(){}
    Grafo(int ordem){
       this->ordem = ordem;
       matriz = new int*[ordem+1];
       for(int i = 1; i <= ordem; i++){
                matriz[i] = new int[ordem+1];
        }
       inicializador();
    }
    int getOrdem();
    int** getMatriz();
    void insereAresta(T,T,int);
    void print();
    int getTamanho();
};

template <class T>
void Grafo<T>::inicializador(){
    for(int i = 1;i <= ordem; i++){
        for(int j = 1; j <= ordem; j++){
            matriz[i][j] = 0;
        }
    }
}

template <class T>
void Grafo<T>::insereAresta(T u, T v, int peso){
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
int** Grafo<T>::getMatriz(){
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
template <class T>
class Dijkstra{

private:

    int *vetPred,*vetCaminho;
    int *vetDist;
    Grafo<T> grafoD;
    int ordem, tam;


public:

       Dijkstra(){}
       Dijkstra (Grafo<T> grafo, int ordem, int tamanho){

             this->grafoD = grafo;
             this->ordem = ordem;
             this->tam = tamanho;

       }

       void executaDijkstra(int);
       void setvetDist(int*);
       void setvetPred(int*);
       void setvetCaminho(int*);
       void setGrafo(Grafo<T>);
       void setOrdem(int);
       void setTam(int);
       int* getvetDist();
       int* getvetPred();
       Grafo<T> getGrafo();
       int getOrdem();
       int getTam();
};

template <class T>
void Dijkstra<T>::executaDijkstra(int inicio){

     FilaP<Par<T> > fila;
     int *prede;
     int *dist;
     Par<T> u;

     dist = new int[getOrdem()+1];
     prede = new int[getOrdem()+1];

     for (int i = 1; i <=getOrdem(); i++){

        dist[i] = numeric_limits<int>::max();
        prede[i] = -1;
     }

     dist[inicio] = 0;
     Par<T> p(inicio,dist[inicio]);
     fila.enfileira(p);

     while (!fila.vazia()){

        u = fila.desinfileira();

        for(int v=1;v<=getOrdem();v++){


          int w = getGrafo().getMatriz()[u.getVertice()][v];

          if(w >  0){

             if(dist[v] > (dist[u.getVertice()] + w)){
             dist[v] = dist[u.getVertice()] + w;
             prede[v] = u.getVertice();
             Par<T> aux(v,dist[v]);
             fila.enfileira(aux);
             }
         }

      }
    }
    setvetDist(dist);
    setvetPred(prede);
}

template <class T>
void Dijkstra<T>::setvetDist(int* vet){
   this->vetDist = vet;
}

template <class T>
void Dijkstra<T>::setvetPred (int* pred){
   this->vetPred = pred;
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
int* Dijkstra<T>::getvetDist(){
   return this->vetDist;
}

template <class T>
int* Dijkstra<T>::getvetPred(){
   return this->vetPred;
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

int main(){

    int ordem,peso,ini;
    int *distancia;
    int maiorV =0;

    cin>>ordem;

    Grafo<int> g(ordem+1);

    for(int i = 1;i <= ordem;i++){
        for(int j = 1;j <= ordem;j++){
           cin>>peso;
           g.insereAresta(i,j,peso);
        }
    }
    cin>>ini;

  Dijkstra<int> d(g,g.getOrdem(),g.getTamanho());
  d.executaDijkstra(ini+1);

  distancia = d.getvetDist();
  maiorV = distancia[1];
    for (int i = 1; i< d.getOrdem();i++){
       if(distancia[i] > maiorV){
            maiorV = distancia[i];
        }

    }
  cout<<maiorV;

  return 0;
}
