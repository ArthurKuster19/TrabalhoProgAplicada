#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

ofstream ofzudo;
ifstream ifzudo;

class No
{
  public:
  int valor;
  No* proximo;

  No(int elemento)
  {
    this->valor=elemento;
    this->proximo=NULL;
  }

  void definirProximo(No* end)
  {
    proximo=end;
  }

  int obterValor()
  {
    return valor;
  }
  No* obterProximo()
  {
    return proximo;
  }
};

class Lista
{
  public:
  No* inicio;
  No* fim;

  Lista()
  {
    inicio = NULL;
    fim=NULL;
  }

  Lista(int num)
  {
    inicio = new No(num);
    fim = inicio;
  }

  virtual ~Lista()
  {
    delete inicio;
  } 
  bool seVazia()
  {
    return (inicio == NULL);
  }
 void imprimirElementos()
  {
    int ajd = 5;
    int opcaltu;
    int opcperi;
    int opcarea;
    int opchipo;

    cout<<"LISTA DE TRIANGULOS (Base, Altura, Perimetro,Area, Hipotenusa (respectivamente)) "<<endl;
    No* i=inicio;
    if(seVazia())
    {
      cout<<"Lista sem elementos!"<<endl;
    }
    else
    {
      while(i)
      {
        if (opchipo == 1){
        cout <<"Hipotenusa: ";
        opchipo = 0;
        }
        if (opcarea == 1){
        cout <<"Area: ";
        opcarea = 0;
        opchipo = 1;
        }
        if (opcperi == 1){
        cout <<"Perimetro: ";
        opcperi = 0;
        opcarea = 1;
        }
        if (opcaltu == 1){
        cout <<"Altura: ";
        opcaltu = 0;
        opcperi = 1;
        }
        if (ajd%5 == 0){
        cout <<"Base: ";
        opcaltu = 1;
        }
        ajd++;
        cout<< i->obterValor()<<endl;
        i = i->obterProximo();
        
      }
      cout<<endl;
    }
  }

  void gravarElementos()
  {
    int ajuda;
    No* i=inicio;
    if(seVazia())
    {
      cout<<"Lista sem elementos!"<<endl;
    }
    else
    {
      while(i)
      {
      
        ajuda = i->obterValor();
        ofzudo << ajuda <<endl;
        i = i->obterProximo();
        
      }
      cout<<endl;
    }
  }


  void insereNoFim(int valor)
  {
    No* novo = new No(valor);

    if(seVazia())
    {
      inicio = novo;
      fim = novo;
    }
    else
    {
      fim -> definirProximo(novo);
      fim = novo;
    
    }
  }

  int tamanhoLista()
  { 
    if(seVazia())
    {
      return 0;
    }
    No* i = inicio;
    int tamanho = 0;

    do
    {
      i = i->obterProximo();
      tamanho++;
    }while(i);

    return tamanho;
  }

  bool existeElemento(int valor)
  {
    No* i = inicio;
    while(i)
    {
      if(i->obterValor()==valor)
      {
        return true;
      }else
      {
        i = i->obterProximo();
      }
    }
    return false;
  }
};

struct tTriangulos{

  int l1, l2, l3, peri, area, hipo, aux;

  // Funçao que importa os valores do código principal.
  void inserir(int ll1, int ll2){
  l1 = ll1;
  l2 = ll2;
 
  }
  
  //Funçao que faz o *Cálculo do perímetro do triângulo.
  void cPerimetro(){
    l3 = ((l1 * l1) + (l2 * l2));
    l3 = sqrt(l3);
    peri = l1 + l2 + l3;

  }
 
 // Funçao que faz o *Cálculo da área do triângulo.
  void cArea(){
    area = ((l1 * l2) / 2);
    
  }
 
 //Funçao que faz o  *Cálculo da hipotenusa dado o valor dos outros dois lados.
  void cHipo(){
   hipo = ((l1 * l1) + (l2 * l2));
   hipo = sqrt(hipo);
    
  }
  
 // Funçao que retorna os valores calculados para o usuário.
 void mostrarParametros(){
 cout<<endl;
 cout <<"Valores: "<<endl;
 cout <<"Perimetro...: "<< peri <<endl;
 cout <<"Area........: "<< area <<endl;
 cout <<"Hipotenusa..: "<< hipo <<endl;

 }
};

int main() {
 
  int basee; 
  int altur;
  int opc;
  int qtdtriangulos;
  int selecaoP;
  
  
    cout<< "O usuário deseja continuar o programa ou deseja encerra-lo (Caso continuar digite 1; Caso deseje encerra-lo digite 2 )"<<endl;
    cin >> selecaoP;
    if(selecaoP == 2){
      abort();
    }

  cout<< "O usuário deseja gravar ou ler um banco de dados (Caso deseje gravar digite 1; Caso deseje ler digite 2 )"<<endl;
  cin >> opc;
   if(opc == 1){
       ofzudo.open("banco_de_dados.txt", ios:: app);

          cout << "Digite a quantidade de triangulos que serão armazenados"<<endl;
              cin >> qtdtriangulos;
            Lista gravar;
            tTriangulos triang ;

  for(int t = 0; t < qtdtriangulos; t++){

    cout << "Digite o valor da base do triangulo" <<endl;
        cin >> basee; 
    cout << "Digite o valor da altura do triangulo" <<endl;
        cin >> altur;

         triang.inserir(basee,altur);
         triang.cPerimetro();
         triang.cArea();
         triang.cHipo();
  
     gravar.insereNoFim(basee);
     gravar.insereNoFim(altur);
     gravar.insereNoFim(triang.peri);
     gravar.insereNoFim(triang.area);
     gravar.insereNoFim(triang.hipo);
  } 
     gravar.gravarElementos();
     ofzudo.close(); 
     return main();    
   }
   if(opc == 2){
       ifzudo.open("banco_de_dados.txt", ios::in);
          Lista ler;
          int dadosT;
         while(ifzudo >> dadosT){
            ler.insereNoFim(dadosT);
         }                                          
       ler.imprimirElementos();
       ifzudo.close();
       return main();
   }                                 
}
