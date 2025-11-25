#include <iostream>
#include <string>
using namespace std;

class Sanduiche {
public:
    string pao;
    string carne;
    string molho;
    string salada;

    void mostrar() const {
        cout << "\n--- Lanche Pronto ---\n";
        cout << "Pão: " << pao << "\n";
        cout << "Carne: " << carne << "\n";
        cout << "Molho: " << (molho.empty() ? "Nenhum" : molho) << "\n";
        cout << "Salada: " << (salada.empty() ? "Nenhuma" : salada) << "\n";
    }
};

class SanduicheBuilder {
    public:
    virtual ~SanduicheBuilder() {}

    virtual void setPao() = 0;
    virtual void setCarne() = 0;
    virtual void setMolho() = 0;
    virtual void setSalada() = 0;

    virtual Sanduiche getSanduiche() = 0;
};

class HamburguerBuilder : public SanduicheBuilder {
private:
    Sanduiche lanche;

public:
    void setPao() override { lanche.pao = "Pão de hambúrguer"; }
    void setCarne() override { lanche.carne = "Carne bovina"; }
    void setMolho() override { lanche.molho = "Maionese"; }
    void setSalada() override { lanche.salada = "Alface e tomate"; }

    Sanduiche getSanduiche() override { return lanche; }
};

class CachorroQuenteBuilder : public SanduicheBuilder {
private:
    Sanduiche lanche;

public:
    void setPao() override { lanche.pao = "Pão de hot dog"; }
    void setCarne() override { lanche.carne = "Salsicha"; }
    void setMolho() override { lanche.molho = "Ketchup e mostarda"; }
    void setSalada() override { lanche.salada = "Batata palha"; }

    Sanduiche getSanduiche() override { return lanche; }
};

class Diretor {
private:
    SanduicheBuilder& builder;

public:
    Diretor(SanduicheBuilder& b) : builder(b) {}

    Sanduiche montarNormal() {
        builder.setPao();
        builder.setCarne();
        builder.setSalada();
        builder.setMolho();

        return builder.getSanduiche();
    }

    Sanduiche montarSemMolho() {
        builder.setPao();
        builder.setCarne();
        builder.setSalada();

        return builder.getSanduiche();
    }

    Sanduiche montarSemSalada() {
        builder.setPao();
        builder.setCarne();
        builder.setMolho();

        return builder.getSanduiche();
    }
};

int main() {
    HamburguerBuilder hb;
    Diretor diretor1(hb);

    Sanduiche hamburguer = diretor1.montarNormal();
    cout << "\nHamburguer comum:";
    hamburguer.mostrar();

    Sanduiche hSemMolho = diretor1.montarSemMolho();
    cout << "\nHamburguer sem molho:";
    hSemMolho.mostrar();

    CachorroQuenteBuilder cb;
    Diretor diretor2(cb);

    Sanduiche dogSemSalada = diretor2.montarSemSalada();
    cout << "\nCachorro quente sem salada:";
    dogSemSalada.mostrar();

    return 0;
}