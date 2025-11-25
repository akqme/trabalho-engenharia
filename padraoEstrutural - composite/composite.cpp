#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class ItemSistema {
public:
    virtual ~ItemSistema() {}
    virtual void mostrar(int nivel = 0) const = 0;
    virtual int tamanho() const = 0;
};

class Arquivo : public ItemSistema {
private:
    string nome;
    int tam;
public:
    Arquivo(string n, int t) : nome(n), tam(t) {}

    void mostrar(int nivel = 0) const override {
        cout << string(nivel, '-') << nome << " (" << tam << " KB)\n";
    }

    int tamanho() const override {
        return tam;
    }
};

class Pasta : public ItemSistema {
private:
    string nome;
    vector<unique_ptr<ItemSistema>> itens;
public:
    Pasta(string n) : nome(n) {}

    void adicionar(unique_ptr<ItemSistema> item) {
        itens.push_back(move(item));
    }

    void mostrar(int nivel = 0) const override {
        cout << string(nivel, '-') << "[" << nome << "]\n";
        for (auto &item : itens) {
            item->mostrar(nivel + 2);
        }
    }

    int tamanho() const override {
        int soma = 0;
        for (auto &item : itens) {
            soma += item->tamanho();
        }
        return soma;
    }
};

int main() {
    auto raiz = make_unique<Pasta>("Trabalho-Engenharia");

    auto strategy = make_unique<Pasta>("padraoComportamental - strategy");
    auto builder = make_unique<Pasta>("padraoCriacional - builder");
    auto composite = make_unique<Pasta>("padraoEstrutural - composite");

    strategy->adicionar(make_unique<Arquivo>("strategy.cpp", 120));
    builder->adicionar(make_unique<Arquivo>("builder.cpp", 300));
    composite->adicionar(make_unique<Arquivo>("composite.cpp", 450));


    raiz->adicionar(move(strategy));
    raiz->adicionar(move(builder));
    raiz->adicionar(move(composite));
    raiz->adicionar(make_unique<Arquivo>("README.md", 10));

    raiz->mostrar();
    cout << "\nTamanho total da pasta Trabalho-Engenharia: " << raiz->tamanho() << " KB\n";

    return 0;
}
