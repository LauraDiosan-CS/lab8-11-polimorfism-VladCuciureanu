#pragma once
#include <Entity.hpp>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Repository
{
protected:
    vector<T *> elems;

public:
    Repository()
    {
        static_assert(std::is_base_of<Entity, T>::value, "Derived not derived from BaseClass");
    }

    Repository(string fileName)
    {
    }

    ~Repository()
    {
    }

    vector<T *> getAll()
    {
        return this->elems;
    }

    int getSize()
    {
        return this->elems.size();
    }

    T *getT(int pos)
    {
        if (pos >= 0 && pos < this->getSize())
        {
            return this->elems[pos]->clone();
        }
        return new T();
    }

    void add(T *p)
    {
        this->elems.push_back(p->clone());
        //this->saveToFile();
    }

    void update(T *pVechi, T *pNou)
    {
        for (int i = 0; i < this->elems.size(); i++)
        {
            if (*(this->getT(i)) == *pVechi)
            {
                delete this->elems[i];
                this->elems[i] = pNou->clone();
                //this->saveToFile();
                return;
            }
        }
    }

    void remove(int id)
    {
        for (int i = 0; i < this->elems.size(); i++)
        {
            Entity* t = this->elems.at(i);
            if(t->entityId==id)
            {
                this->elems.erase(this->elems.begin()+i);
                return;
            }
        }
    }

    void remove(T *p)
    {
        for (int i = 0; i < this->elems.size(); i++)
        {
            // this->produse.begin() + i <=> un iterator care pointeaza spre pozitia i din vector
            if (**(this->elems.begin() + i) == *p)
            {
                delete this->elems[i];
                //este necesar un iterator pt. metoda erase
                this->elems.erase(this->elems.begin() + i);
                //this->saveToFile();
                return;
            }
        }
    }

    void emptyRepo()
    {
        for (int i = 0; i < this->getSize(); i++)
        {
            delete this->elems[i];
        }
        this->elems.clear();
    }
};
