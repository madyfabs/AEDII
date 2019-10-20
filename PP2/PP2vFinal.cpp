#include <iostream>
#include <limits>
#include <cstring>

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


template <class T>
class Grafo{
private:
    double **matriz;
    Aresta<T> *vet;
    int ordem, tamanho,aux = 0;;
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
    No<T>* getFrente();

};

template <class T>
No<T>* Fila<T>::getFrente(){
   return frente;
}

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
    return p;


}

template <class T>
void Fila<T>::ImprimeFila(){

   No<T>* p = frente->getProx();

   while (p != NULL){


    cout<< endl<<"tem algo aqui : "<<p->getItem();
    p = p->getProx();

   }
}

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
        Aresta<T> arvore[tam+1];
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

				arvore[i].setVertice1(vet[i].getVertice1());
				arvore[i].setVertice2(vet[i].getVertice2());
				arvore[i].setPeso(vet[i].getPeso());
				h++;
				une.une(v1, v2);
			    soma = soma + vet[i].getPeso();

			}
		}

		setPesoMST(soma);
}

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

       Fila<T> getCaminhoMin(int);
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

    setvetDist(dist);
    setvetPred(prede);
}

template <class T>
Fila<T> Dijkstra<T>::getCaminhoMin(int destino){
    Fila<T> caminho;
    int *vetaux = new int[getOrdem()+1];
    int x =2;


    vetaux[1] = destino;

    int minimo = getvetPred()[destino];
    while(minimo != -1){
      vetaux[x] = minimo;
      minimo = getvetPred()[minimo];
      x++;
    }


    for (int i = 1; i<x;i++){

        caminho.Enfileira(vetaux[i]);
    }



    return caminho;
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

template<class T>
class BlocoNeuronio{
private:

    Grafo<T> *grafo;
    int cor;
    Fila<Aresta<int> > arestas;
    Fila<T> doentes;
    double tamanho;
    int ordem;

public:
    BlocoNeuronio(){}
    BlocoNeuronio(T ordem, T tamanho){
        this->grafo= new Grafo<int>(ordem,tamanho) ;
        this->tamanho=0;
        this->ordem=ordem;
        this->cor=0;
    }
    void insereAresta(int vert1, int vert2,double peso);
    void print();
    double getTamanho();
    Grafo<T>* getGrafo();
    void setDoente(int doente);
    void trocarCor();


};

template<class T>
void BlocoNeuronio<T>::trocarCor() {
    this->cor=1;
}

template<class T>
void BlocoNeuronio<T>::setDoente(int doente) {
    this->doentes.insere(doente);
}

template <class T>
Grafo<T>* BlocoNeuronio<T>::getGrafo(){
    return grafo;
}

template <class T>
double BlocoNeuronio<T>::getTamanho(){
    return tamanho;
}
template<class T>
void BlocoNeuronio<T>::insereAresta(int vert1, int vert2,double peso){
    grafo->insereAresta(vert1,vert2,peso);
    Aresta<T> x(vert1,vert2,peso);
    Aresta<T> y(vert2,vert1,peso);
    arestas.Enfileira(x);

}
template<class T>
void BlocoNeuronio<T>::print(){
    grafo->print();
}

int main(){

    int ordemP,tamanhoP,ordem,tamanho,vert1,vert2,vInicial,vFinal,contador,doente,doentes;
    double peso,soma=0;
    Fila<int> doentess;

    cin>>ordemP;
    cin>>tamanhoP;

    Grafo<int> g(ordemP,tamanhoP);
    BlocoNeuronio<int> neuronio[ordemP+1];
    for(int h=0;h<tamanhoP;h++){
        cin>>vert1;
        cin>>vert2;
        cin>>peso;
        g.insereAresta(vert1,vert2,peso);
    }
    cin>>vInicial;
    cin>>vFinal;

    contador = ordemP;

    for(int j=1;j<=contador;j++){

        cin>>ordem;
        cin>>tamanho;

        cin>>doente;

        if(doente != 0){
            doentess.Enfileira(j);
        }
        for(int h=0;h<doente;h++){
            cin>>doentes;
        }


        BlocoNeuronio<int> b(ordem,tamanho);
        for(int i=1;i<=tamanho;i++){
            cin>>vert1;
            cin>>vert2;
            cin>>peso;
            b.insereAresta(vert1,vert2,peso);
        }
        if(tamanho>0){
            b.trocarCor();
        }
        neuronio[j]=b;
    }

    Dijkstra<int> d(g,g.getOrdem(),g.getTamanho());
    d.executaDijkstra(vInicial);
    Fila<int> filaa = d.getCaminhoMin(vFinal);



    No<int>* p = filaa.getFrente()->getProx();

    while (p != NULL){
        No<int>* don = doentess.getFrente()->getProx();
        while (don != NULL){

            if(p->getItem() == don->getItem()){
                Kruskal <int> k (neuronio[p->getItem()].getGrafo()->getVet(),neuronio[p->getItem()].getGrafo()->getTamanho(),neuronio[p->getItem()].getGrafo()->getOrdem());
                k.chamaKruskal();
                soma=soma+k.getpesoMST();
            }
            don = don->getProx();
        }
        p = p->getProx();
    }

    cout<<soma;

  return 0;
}

