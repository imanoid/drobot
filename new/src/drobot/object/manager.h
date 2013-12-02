#ifndef DROBOT_OBJECT_MANAGER_H
#define DROBOT_OBJECT_MANAGER_H

#include <vector>
#include <string>
#include <map>
#include "../util/util.h"

namespace drobot {
namespace object {

template<typename T>
/**
 * @brief Item container, can be used to prevent memory leaks.
 * @details Used as a kind of memory database to manage the different Item types.
 *  If _deleteItemsOnDestroy is set it automatically deletes all the items when the destructor is called.
 */
class Manager {
private:
    /**
     * @brief map containing all the items
     */
    std::map<std::string, T*> _items;
protected:
    /**
     * @brief flag indicating wether the items should be deleted in the Destructor.
     */
    bool _deleteItemsOnDestroy;
public:
    Manager() {
        _deleteItemsOnDestroy = true;
    }

    virtual ~Manager() {
        if (_deleteItemsOnDestroy)
            util::deleteMapValues(_items);
    }

    Manager(std::vector<T*> items) {
        for (typename std::vector<T*>::iterator iItem = items.begin(); iItem != items.end(); iItem++) {
            add(*iItem);
        }
    }

    /**
     * @return a vector containing all the elements.
     */
    std::vector<T*> values() const {
        std::vector<T*> items;

        for (typename std::map<std::string, T*>::const_iterator iItem = _items.begin(); iItem != _items.end(); iItem++) {
            items.push_back(iItem->second);
        }

        return items;
    }

    /**
     * @return a vector containing all the keys.
     */
    std::vector<std::string> keys() const {
        std::vector<std::string> items;

        for (typename std::map<std::string, T*>::const_iterator iItem = _items.begin(); iItem != _items.end(); iItem++) {
            items.push_back(iItem->first);
        }

        return items;
    }

    /**
     * @param name of the item
     * @return the item
     */
    T* get(std::string name) {
        typename std::map<std::string, T*>::iterator iItem = _items.find(name);
        if (iItem == _items.end())
            return 0;
        else
            return iItem->second;
    }

    /**
     * @brief adds an item
     * @param item
     * @return true if it is added, false if it's already in the list.
     */
    bool add(T* item) {
        if (!has(item->getName())) {
            _items[item->getName()] = item;
            this->onAdd(item);
            return true;
        } else {
            return false;
        }
    }

    /**
     * @brief adds a list of items
     * @param items
     */
    void add(std::vector<T*> items) {
        for (typename std::vector<T*>::iterator iItem = items.begin(); iItem != items.end(); iItem++) {
            add(*iItem);
        }
    }

    /**
     * @brief called when an item is added
     * @param item
     */
    virtual void onAdd(T* item __maybe_unused) {

    }

    /**
     * @brief removes an item by its name
     * @param name of the item
     * @return the removed item or 0 if it's not in the list.
     */
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

    /**
     * @brief removes an item
     * @param name of the item
     * @return the removed item or 0 if it's not in the list.
     */
    T* remove(T* item) {
        return remove(item->getName());
    }

    /**
     * @brief called when an item is removed
     * @param item
     */
    virtual void onRemove(T* item __maybe_unused) {

    }

    /**
     * @brief removes a list of items
     * @param items
     * @return the removed items
     */
    std::vector<T*> remove(std::vector<T*> items) {
        typename std::vector<T*> removedItems;
        for (typename std::vector<T*>::iterator iItem = items.begin(); iItem != items.end(); iItem++) {
            T* removedItem = remove((*iItem)->getName());
            if (removedItem != 0) {
                removedItems.push_back(removedItem);
            }
        }
    }

    /**
     * @brief checks if item is in the list by its name
     * @param name of the item
     * @return true if item is in the list, false otherwhise
     */
    bool has(std::string name) {
        return _items.find(name) != _items.end();
    }

    /**
     * @brief checks if item is in the list
     * @param item
     * @return true if item is in the list, false otherwhise
     */
    bool has(T* item) {
        return has(item->getName());
    }

    /**
     * @brief removes all the items
     */
    void clear() {
        util::deleteMapValues(_items);
    }
};

} // namespace object
} // namespace drobot

#endif // DROBOT_OBJECT_MANAGER_H
