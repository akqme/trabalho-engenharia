#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Iterator {
public:
    virtual ~Iterator() {}
    virtual void primeiro() = 0;
    virtual void prox() = 0;
    virtual bool fim() const = 0;
    virtual string atual() const = 0;
};

class NomeCollection;

class NomeIterator : public Iterator {
private:
    const NomeCollection& collection;
    size_t index;

public:
    NomeIterator(const NomeCollection& col);
    
    void primeiro() override;
    void prox() override;
    bool fim() const override;
    string atual() const override;
};

class NomeCollection {
private:
    vector<string> Nomes;

public:
    void adicionar(const string& Nome) {
        Nomes.push_back(Nome);
    }

    size_t tamanho() const { return Nomes.size(); }
    string get(size_t i) const { return Nomes[i]; }

    Iterator* createIterator() const {
        return new NomeIterator(*this);
    }
};

NomeIterator::NomeIterator(const NomeCollection& col)
    : collection(col), index(0) {}

void NomeIterator::primeiro() {
    index = 0;
}

void NomeIterator::prox() {
    if (index < collection.tamanho()) index++;
}

bool NomeIterator::fim() const {
    return index >= collection.tamanho();
}

string NomeIterator::atual() const {
    if (!fim())
        return collection.get(index);
    return "";
}

int main() {
    NomeCollection Nomes;
    Nomes.adicionar("Igor");
    Nomes.adicionar("Henrique");
    Nomes.adicionar("Gustavin");
    
    Iterator* it = Nomes.createIterator();

    for (it->primeiro(); !it->fim(); it->prox()) {
        cout << it->atual() << endl;
    }

    delete it;
}
