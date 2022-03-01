# BlockVector
Vetor de tamanho variável limitado, varia seu tamanho em blocos, assim, apenas alocando memória necessária com baixo custe de memória extra para o gerenciamento de alocação dinâmica dos blocos

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
        //Lê os itens do vetor solicitado
        // No caso de um índice negativo, o vetor será lido de trás para a frente começando em -1;
    }
    
    cout<< a.memorySize() << endl << a.size();
    //a.memorySize() Retorna a quantidade de memória usada
    //a.size() Retorna o maior índice em uso do vetor
    a.clear();
    //Limpa o vetor
    return 0;
}
```
