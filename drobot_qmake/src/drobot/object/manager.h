#ifndef DROBOT_OBJECT_MANAGER_H
#define DROBOT_OBJECT_MANAGER_H

#include <vector>
#include <string>
#include <map>

namespace drobot {
namespace object {

template<typename T>
class Manager {
private:
    std::map<std::string, T*> _items;
public:
    Manager() {
    }

    Manager(std::vector<T*> items) {
        for (typename std::vector<T*>::iterator iItem = items.begin(); iItem != items.end(); iItem++) {
            add(*iItem);
        }
    }

    std::vector<T*> list() const {
        std::vector<T*> items;

        for (typename std::map<std::string, T*>::const_iterator iItem = _items.begin(); iItem != _items.end(); iItem++) {
            items.push_back(iItem->second);
        }

        return items;
    }

    T* get(std::string name) {
        typename std::map<std::string, T*>::iterator iItem = _items.find(name);
        if (iItem == _items.end())
            return 0;
        else
            return iItem->second;
    }

    bool add(T* item) {
        if (!has(item->getName())) {
            _items[item->getName()] = item;
            this->onAdd(item);
            return true;
        } else {
            return false;
        }
    }

    void add(std::vector<T*> items) {
        for (typename std::vector<T*>::iterator iItem = items.begin(); iItem != items.end(); iItem++) {
            add(*iItem);
        }
    }

    virtual void onAdd(T* item) {

    }

    T* remove(std::string name) {
        if (has(name)) {
            T* item = _items[name];
            _items.erase(name);
            this->onRemove(item);
            return item;
        } else {
            return 0;
        }
    }

    T* remove(T* item) {
        remove(item->getName());
    }

    virtual void onRemove(T* item) {

    }

    std::vector<T*> remove(std::vector<T*> items) {
        typename std::vector<T*> removedItems;
        for (typename std::vector<T*>::iterator iItem = items.begin(); iItem != items.end(); iItem++) {
            T* removedItem = remove((*iItem)->getName());
            if (removedItem != 0) {
                removedItems.push_back(removedItem);
            }
        }
    }

    bool has(std::string name) {
        return _items.find(name) != _items.end();
    }

    bool has(T* item) {
        return has(item->getName());
    }

    void clear() {
        _items.clear();
    }
};

} // namespace object
} // namespace drobot

#endif // DROBOT_OBJECT_MANAGER_H
