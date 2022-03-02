#BlockVector
```    
Vetor de tamanho variável limitado, varia seu tamanho em blocos, assim,
apenas alocando memória necessária com baixo custe de memória extra para 
o gerenciamento de alocação dinâmica dos blocos

Um blockVector<int>(10, 100);  possui 10 arrays não inicializados, sendo assim,
cada um usa apenas 8 bytes, cada um destes arrays possui 100 variáveis do tipo 
definido, neste caso <int>, porém, os arrays apenas são alocados quando nescessário,
diminuindo a memória usada.
    Uma boa distribuição entre a quantidade de blocos e o 
tamanho dos blocos pode tornar este vetor menos caro em relação à memoria em comparação
a um std::vector.
```


Exemplos de uso:

```
#include "blockVector"

int main(){

    blockVector<int> a(10, 100);
    // Cria um blockVector com 10 blocos de arrays com tamanho 100;
    
    for(int i = 0; i < 200; i++){
        a.push_back(i);
        // Adiciona novos itens ao vetor;
    }
    
    for(int i = -1; i > -200; i--){
        cout<< *a[i] << endl;
        //Lê os itens do vetor
        // No caso de um índice negativo, o vetor será lido de trás para a frente, começando em -1
    }
    
    cout<< a.memorySize() << endl << a.size();
    //a.memorySize() Retorna a quantidade de memória usada
    //a.size() Retorna o maior índice em uso do vetor
    a.clear();
    //Limpa o vetor
    return 0;
}
```
