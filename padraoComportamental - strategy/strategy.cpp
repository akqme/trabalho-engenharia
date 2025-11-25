#include <iostream>
#include <memory>
#include <string>

using namespace std;

class ComportamentoStrategy {
public:
    virtual ~ComportamentoStrategy() {}
    virtual void agir(string nome) = 0;
};

class Agressivo : public ComportamentoStrategy {
public:
    void agir(string nome) override {
        cout << nome << " avança e ataca rapidamente!\n";
    }
};

class Defensivo : public ComportamentoStrategy {
public:
    void agir(string nome) override {
        cout << nome << " assume posição defensiva e bloqueia ataques.\n";
    }
};

class Fugir : public ComportamentoStrategy {
public:
    void agir(string nome) override {
        cout << nome << " entra em pânico e tenta fugir!\n";
    }
};

class Patrulhar : public ComportamentoStrategy {
public:
    void agir(string nome) override {
        cout << nome << " está patrulhando a área calmamente.\n";
    }
};

class Inimigo {
private:
    string nome;
    unique_ptr<ComportamentoStrategy> strategy;

public:
    Inimigo(string n) : nome(n) {}

    void setStrategy(unique_ptr<ComportamentoStrategy> s) {
        strategy = std::move(s);
    }

    void agir() {
        if (!strategy) {
            cout << nome << " não tem estratégia definida!\n";
            return;
        }
        strategy->agir(nome);
    }
};

int main() {
    Inimigo goblin("Goblin");
    Inimigo orc("Gustavin");

    cout << "=== Turno de Goblin ===\n";
    goblin.setStrategy(make_unique<Patrulhar>());
    goblin.agir();

    goblin.setStrategy(make_unique<Agressivo>());
    goblin.agir();

    goblin.setStrategy(make_unique<Fugir>());
    goblin.agir();

    cout << "\n=== Turno de Gustavin ===\n";
    orc.setStrategy(make_unique<Defensivo>());
    orc.agir();

    orc.setStrategy(make_unique<Agressivo>());
    orc.agir();

    return 0;
}
