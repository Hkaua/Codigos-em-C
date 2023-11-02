#include <iostream>
using namespace std;

struct arvore
{
    int x;
    arvore* dir;
    arvore* esq;
};

struct pilha
{
    arvore* num;
    pilha* prox;
};

int main()
{
    arvore* raiz = nullptr;
    arvore* aux;
    arvore* novo;
    pilha* topo;
    pilha* aux_pilha;

    int op;
    bool flag = false;

    do
    {
        cout << "1 - Inserir na Árvore binária" << endl;
        cout << "2 - Exibir Árvore em ordem" << endl;
        cout << "3 - Exibir Árvore em pré-ordem" << endl;
        cout << "4 - Exibir Árvore em pós-ordem" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opção: ";
        cin >> op;

        if (op == 1)
        {
            cout << "Inserir na árvore binária..." << endl;
            cout << "Digite o valor: ";
            novo = new arvore();
            cin >> novo->x;
            novo->dir = nullptr;
            novo->esq = nullptr;
            cout << "Valor " << novo->x << " adicionado na árvore" << endl;

            if (raiz == nullptr)
            {
                raiz = novo;
            }
            else
            {
                flag = false;
                aux = raiz;
                while (!flag)
                {
                    if (novo->x >= aux->x)
                    {
                        if (aux->dir == nullptr)
                        {
                            aux->dir = novo;
                            flag = true;
                        }
                        else
                        {
                            aux = aux->dir;
                        }
                    }
                    else
                    {
                        if (aux->esq == nullptr)
                        {
                            aux->esq = novo;
                            flag = true;
                        }
                        else
                        {
                            aux = aux->esq;
                        }
                    }
                }
            }
        }
        else if (op == 2)
        {
            if (raiz == nullptr)
            {
                cout << "Árvore vazia" << endl;
            }
            else
            {
                cout << "Exibindo os valores na árvore em ordem" << endl;
                aux = raiz;
                topo = nullptr;

                do
                {
                    while (aux != nullptr)
                    {
                        aux_pilha = new pilha();
                        aux_pilha->num = aux;
                        aux_pilha->prox = topo;
                        topo = aux_pilha;
                        aux = aux->esq;
                    }
                    if (topo != nullptr)
                    {
                        aux_pilha = topo;
                        cout << aux_pilha->num->x << " ";
                        aux = aux_pilha->num->dir;
                        topo = topo->prox;
                    }

                } while (topo != nullptr || aux != nullptr);
            }
            cout << endl;
        }
        else if (op == 3)
        {
            cout << "Exibindo os valores na árvore em pré-ordem... " << endl;

            if (raiz == nullptr)
            {
                cout << "Árvore vazia" << endl;
            }
            else
            {
                aux = raiz;
                topo = nullptr;
                while (aux != nullptr)
                {
                    aux_pilha = new pilha();
                    aux_pilha->num = aux;
                    aux_pilha->prox = topo;
                    topo = aux_pilha;
                    cout << aux_pilha->num->x << " ";
                    aux = aux_pilha->num->esq;
                    topo = topo->prox;
                }
                if (topo != nullptr)
                {
                    aux_pilha = topo;
                    cout << aux_pilha->num->x << " ";
                    aux = aux_pilha->num->dir;
                    topo = topo->prox;
                }
            }

            cout << endl;
        }
        else if (op == 4)
        {
            cout << "Exibindo os valores na árvore em pós-ordem... " << endl;
            // Implemente a lógica para a travessia pós-ordem aqui
        }
        else if (op == 5)
        {
            cout << "Até mais, obrigado!" << endl;
        }
        else
        {
            cout << "Opção Inválida" << endl;
        }

    } while (op != 5);

    return 0;
}
