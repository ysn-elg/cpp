#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _s[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; i++)
        _s[i] = NULL;
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_s[i])
                delete _s[i];
            if (other._s[i])
                _s[i] = other._s[i]->clone();
            else
                _s[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++){
        if (_s[i]) {
            delete _s[i];
            _s[i] = NULL;
        }
    }
}

void  MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i++) {
        if (!_s[i]) {
            _s[i] = m->clone();
            delete m;
            return ;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_s[i] && _s[i]->getType() == type)
            return _s[i]->clone();
    }
    return NULL;
}
