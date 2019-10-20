#include <iostream>
#include <limits>

enum Cores {BRANCO,CINZA,PRETO};
int TEMPO;

using namespace std;

template<class T>
class No{

private:

    T item;
    No<T>* prox;

public:

    No(){
        prox = NULL;
    }
    No(T item){
    this->item = item;
    this->prox = NULL;
    }

    void setItem(T item);
    void setProx(No<T>* prox);
    T getItem();
    No<T>* getProx();
};

template<class T>
void No<T>::setItem(T item) {
    this->item = item;
}

template<class T>
void No<T>::setProx(No* prox) {
    this->prox = prox;
}

template<class T>
T No<T>::getItem() {
    return item;
}

template<class T>
No<T>* No<T>::getProx() {
     return prox;
}

template<class T>
class Lista{
private:

    No<T>* prim;
    No<T>* ult;
    int TAM;

public:

    Lista (){
    prim = new No<T>;
    prim->setProx(NULL);
    ult = prim;
    }

    ~Lista(){}
    No<T>* getPrim();
    int busca(int i);
    void insere(T item);
    void remove(No<T>* r);
    void print();
    int getTAM();
    bool vazia();
    No<T>* pred(No<T>*);
};

template<typename T>
bool Lista<T>::vazia() {
    return prim == ult;
}


template<typename T>
No<T>* Lista<T>::pred(No<T>* r) {
    No<T>* p = prim->getProx();
    while (p->getProx() != r) {
        p = p->getProx();
    }
    return p;
}

template<typename T>
void Lista<T>::remove(No<T>* r){
    if (vazia() || r == NULL || r == prim) {
        cout << "impossível remover\n";
    }
    else {
        No<T>* p = pred(r);
        p->setProx(r->getProx());
        if (p->getProx() == NULL) ult = p;
        delete r;
    }
}

template <class T>
int Lista<T>::getTAM(){
    return TAM;
}

template<class T>
No<T>* Lista<T>::getPrim(){
    return prim;
}

template<class T>
int Lista<T>::busca(int i){

    No<T> *p = getPrim()->getProx();

    int cont = 1;
    int achou;

    while(p != NULL){
      if(cont == i){
         achou = p->getItem();
      }
      cont++;
      p = p->getProx();
    }

    return achou;
}

template<class T>
void Lista<T>::insere(T item){
    ult->setProx(new No<T>);
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setItem(item);
    TAM++;
}

template<class T>
void Lista<T>::print(){
    No<T>* p = prim->getProx();
    while(p != NULL){
        cout << p->getItem() << " ";
        p = p->getProx();
    }
    cout << endl;
}

template<class T>
class Fila{
private:

    No<T>* frente;
    No<T>* tras;


public:

    Fila(){
    frente = new No<T>;
    frente->setProx(NULL);
    tras = frente;
    }

    T getFrente();
    bool vazia();
    void enfileira(T item);
    void desenfileira(T item);
    void print();
};

template<class T>
bool Fila<T>::vazia(){
    return tras == frente;
}

template<class T>
T Fila<T>::getFrente(){
    return frente->getProx()->getItem();
}

template<class T>
void Fila<T>::enfileira(T item){
    tras->setProx(new No<T>);
    tras = tras->getProx();
    tras->setItem(item);
    tras->setProx(NULL);
}

template<class T>
void Fila<T>::desenfileira(T item){
    No<T>* aux = frente;
    frente = frente->getProx();
    item = frente->getItem();
    delete aux;
}

template<class T>
void Fila<T>::print(){
    frente = frente->getProx();
    while(frente != NULL){
        cout << frente->getItem() << "\n";
        frente = frente->getProx();
    }
}

template<class T>
class Aresta{
private:

    T vertice1;
    T vertice2;
    float peso ;

public:
    Aresta(){}
    Aresta(T vertice1,T vertice2,float peso){
        this->vertice1= vertice1;
        this->vertice2= vertice2;
        this->peso= peso;
    }
    T getVertice1();
    T getVertice2();
    float getPeso();
};
template<class T>
T Aresta<T>::getVertice1() {
     return vertice1;
}

template<class T>
T Aresta<T>::getVertice2() {
     return vertice2;
}

template<class T>
float Aresta<T>::getPeso() {
     return peso;
}

template<class T>
class Grafo{
private:

    Lista<T> *adj;
    int ordem = 0;
    int tamanho;


public:

    Grafo(T ordem){
     inicializar(ordem);
    }
    void inicializar(T ordem);
    void insereAresta(T vert1, T vert2);
    void print();
    int getOrdem();
    Lista<T>* getAdj();
    Lista<T> BFS(T iniVert, T fimVert,Lista<T> listaExecao);
    int verificaAresta (T vert1, T vert2);
};

template <class T>
Lista<T>* Grafo<T>::getAdj(){
   return adj;
}

template <class T>
int Grafo<T>::getOrdem(){
    return ordem;
}

template<class T>
void Grafo<T>::inicializar(T ordem){
    this->ordem = ordem;
    adj = new Lista<T>[ordem + 1];
}

template <class T>
int Grafo<T>::verificaAresta(T vert1,T vert2){

    Lista<T> *aux = adj;
    int i = ordem;
    int cont=0;

    for (int j = 1;j<=i;j++){
        if(j==vert1){
                No<T> *z = aux[j].getPrim()->getProx();
                cont=0;
                while(z!=NULL){
                    if(z->getItem()==vert2){
                        cont++;
                    }
                    z= z->getProx();
                }
        }
    }


  if (cont > 0){
    return 0;
  }
  else{
    return 1;
  }

}

template<class T>
void Grafo<T>::insereAresta(T vert1, T vert2){
    adj[vert1].insere(vert2);
    adj[vert2].insere(vert1);
    tamanho++;
}

template<class T>
Lista<T> Grafo<T>::BFS (T iniVert, T fimVert,Lista<T> listaExecao){
    Lista<T> caminho;
    int mudarv,mudau,pulou;
    T vertice = iniVert;
    bool encontrou = false;
    int cor[ordem + 1];
    int distancia[ordem + 1];
    T predecessor[ordem + 1];

    for(int i = 0; i < ordem + 1; i++){
        cor[i] = BRANCO;
        distancia[i] = numeric_limits<int>::max();
        predecessor[i] = -1;
    }

    cor[vertice] = CINZA;
    distancia[vertice] = -1;
    predecessor[vertice] = -1;

    Fila<T> fila;
    fila.enfileira(vertice);

    while(!fila.vazia() && !encontrou){
        vertice = fila.getFrente();
        fila.desenfileira(vertice);
        No<T>* posicao = adj[vertice].getPrim()->getProx();
        while(posicao != NULL){
            No<T>* lista_execao = listaExecao.getPrim()->getProx();
            pulou=0;
            while(lista_execao != NULL){
                if(posicao->getItem() == lista_execao->getItem()){
                    pulou=1;
                }
                lista_execao = lista_execao->getProx();
            }
            if(pulou==1){
                posicao = posicao->getProx();
            }else{
                if(cor[posicao->getItem()] == BRANCO){
                    cor[posicao->getItem()] = CINZA;
                    distancia[posicao->getItem()] = distancia[vertice] + 1;
                    predecessor[posicao->getItem()] = vertice;
                    fila.enfileira(posicao->getItem());
                }

                if(posicao->getItem() == fimVert){
                    encontrou = true;
                    mudarv=predecessor[posicao->getItem()];
                    mudau=posicao->getItem();
                    for(int i=0;i<=distancia[fimVert]+1;i++){
                        caminho.insere(mudau);
                        mudau=mudarv;
                        mudarv=predecessor[mudarv];
                    }
                }
                posicao = posicao->getProx();
            }
        }
        cor[vertice] = PRETO;
    }
    return caminho;

}

template<class T>
void Grafo<T>::print(){
    for(int i = 1;i < ordem+1;i++){
        cout << "v[" << i << "] = ";
        adj[i].print();
    }
}

template <class T>
class DFS {
private:
  int *pred;
  Grafo<T> *grafocriado;
  Cores *cor;
  int *d;
  int *f;
  void dfs(Grafo<T> &);
  void dfsVisita(Grafo<T> &,int);
public:
  DFS(){ }
  void inicia(Grafo<T> &);
  int *getPred();
  Cores *getCor();
  int *getF();
  int *getD();
  Grafo<T>* getGrafoCriado();
};

template <class T>
Grafo<T>* DFS<T>::getGrafoCriado(){
  return grafocriado;
}

template <class T>
void DFS<T>::inicia(Grafo<T> &g){
  dfs(g);
}

template <class T>
int * DFS<T>::getPred(){
  return pred;
}

template <class T>
Cores * DFS<T>::getCor(){
  return cor;
}
template <class T>
int* DFS<T>::getF(){
  return f;
}

template <class T>
int* DFS<T>::getD(){
  return d;
}


template <class T>
void DFS<T>::dfsVisita(Grafo<T> &g, int u){
  TEMPO = TEMPO +1;
  d[u] = TEMPO;
  cor[u] = CINZA;
  Lista<int> adj = g.getAdj()[u];
  int i = 1;
  while(i <= adj.getTAM()){
        int v = adj.busca(i);
        if(cor[v] == BRANCO){
            pred[v] = u;
            dfsVisita(g,v);
            grafocriado->insereAresta(u,v);
        }
        i++;
    }
  cor[u] = PRETO;
  TEMPO = TEMPO + 1;
  f[u] = TEMPO;
}

template <class T>
void DFS<T>::dfs(Grafo<T> &g){
    const int N = g.getOrdem();
    pred = new int[N];
    cor = new Cores[N];
    d = new int[N];
    f = new int[N];
    grafocriado = new Grafo<T>(N);

    for(int u=1;u<=N;u++){
      cor[u] = BRANCO;
      pred[u] = -1;
    }
    TEMPO = 0;
    for(int u=1;u<=N;u++){
      if(cor[u] == BRANCO){
         dfsVisita(g,u);
      }
    }
}


template<class T>
class SistemaPlanetario{
private:

    Grafo<T> *grafo;
    Lista<Aresta<int> > arestas;
    float tamanho;
    int ordem;

public:
    SistemaPlanetario(){}
    SistemaPlanetario(T ordem){
        this->grafo= new Grafo<int>(ordem) ;
        this->tamanho=0;
        this->ordem=ordem;
    }
    void insereAresta(int vert1, int vert2,float peso);
    void print();
    T BFS(T iniVert, T fimVert,Lista<T> listaExecao);
    float getTamanho();
    void soma();
    Grafo<T>* getGrafo();


};

template <class T>
Grafo<T>* SistemaPlanetario<T>::getGrafo(){
    return grafo;
}

template <class T>
float SistemaPlanetario<T>::getTamanho(){
    return tamanho;
}
template<class T>
void SistemaPlanetario<T>::insereAresta(int vert1, int vert2,float peso){
    grafo->insereAresta(vert1,vert2);
    Aresta<T> x(vert1,vert2,peso);
    Aresta<T> y(vert2,vert1,peso);
    arestas.insere(x);

}
template<class T>
void SistemaPlanetario<T>::print(){
    grafo->print();
}
template<class T>
T SistemaPlanetario<T>::BFS(T iniVert, T fimVert,Lista<T> listaExecao){
    grafo->BFS(iniVert,fimVert,listaExecao);
}

template <class T>
void SistemaPlanetario<T>::soma(){
    DFS<int> dfs;
    int i=0;
    Grafo<int> grafoAux(ordem);
    No<Aresta<T> >* p = arestas.getPrim()->getProx();
    while(p != NULL){
        grafoAux.insereAresta(p->getItem().getVertice1(),p->getItem().getVertice2());
        p = p->getProx();
    }

    dfs.inicia(grafoAux);

    No<Aresta<T> >* s = arestas.getPrim()->getProx();

    while(s != NULL){
        i = dfs.getGrafoCriado()->verificaAresta(s->getItem().getVertice1(),s->getItem().getVertice2());
        if(i==0){
            tamanho = tamanho + s->getItem().getPeso();
        }
        s = s->getProx();
    }

}

int main(){

    int ordem,tamanho,vert1,vert2,inimigo,vInicial,vFinal,contador;
    Lista<int> LInimigos,caminho;
    float total=0,peso;

    cin>>ordem;
    cin>>tamanho;

    Grafo<int> g(ordem);
    SistemaPlanetario<int> sistema[ordem+1];
    for(int j=0;j<tamanho;j++){
        cin>>vert1;
        cin>>vert2;
        g.insereAresta(vert1,vert2);
    }
    cin>>tamanho;
    for(int j=0;j<tamanho;j++){
        cin>>inimigo;
        LInimigos.insere(inimigo);
    }
    cin>>vInicial;
    cin>>vFinal;

    contador = ordem;

    for(int j=1;j<=contador;j++){
        cin>>ordem;
        cin>>tamanho;
        SistemaPlanetario<int> s(ordem);
        for(int i=1;i<=tamanho;i++){
            cin>>vert1;
            cin>>vert2;
            cin>>peso;
            s.insereAresta(vert1,vert2,peso);
        }
        s.soma();

        sistema[j]=s;
    }

    caminho= g.BFS(vInicial,vFinal,LInimigos);
    No<int>* p = caminho.getPrim()->getProx();

    while(p != NULL){

        total=total + sistema[p->getItem()].getTamanho();
        p = p->getProx();
    }
    cout << fixed;
    cout.precision(1);
    cout<<total<<endl;

   return 0;
}




























