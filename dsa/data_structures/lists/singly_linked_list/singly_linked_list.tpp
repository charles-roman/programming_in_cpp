#include <iostream>
#include <concepts>
#include "singly_linked_list.hpp"

namespace croman_library {

    template <typename T>
    SList<T>::~SList() {
        while(!this->empty()) {
            this->pop_front();  // this double checks the empty list, but is cleaner to read
        }
    }

    template <typename T>
    size_t SList<T>::size() const {
        size_t size{0};
        Node<T>* node = head;
        while (node != nullptr) {
            ++size;
            node = node->get_next();
        }
        return size;
    }

    template <typename T>
    bool SList<T>::empty() const {
        return (head == nullptr);
    }

    template <typename T>
    void SList<T>::push_front(const T& value) {
        auto node = new(std::nothrow) Node<T>;
        if (node == nullptr) {
            std::cerr << "ERROR using croman_library::SList<T>::push_front();"
            " memory allocation failure" << std::endl;
            exit(EXIT_FAILURE);
        }

        node->set_data(value);
        node->set_next(head);
        head = node;

        if (tail == nullptr)
            tail = head;
    }

    template <typename T>
    void SList<T>::pop_front() {
        if (this->empty()) {
            std::cerr << "ERROR using croman_library::SList<T>::pop_front();"
            " cannot remove element from empty list" << std::endl;
            exit(EXIT_FAILURE);
        }

        Node<T>* temp = head;
        head = head->get_next();
        delete temp;
        temp = nullptr;

        if (head == nullptr)
            tail = nullptr;
    }

    template <typename T>
    const T& SList<T>::front() const {
        if (this->empty()) {
            std::cerr << "ERROR using croman_library::SList<T>::front();"
            " cannot read element from empty list" << std::endl;
            exit(EXIT_FAILURE);
        }
        return head->get_data();
    }

    template <typename T>
    void SList<T>::push_back(const T& value) {
        auto node = new(std::nothrow) Node<T>;
        if (node == nullptr) {
            std::cerr << "ERROR using croman_library::SList<T>::push_back();"
            " memory allocation failure" << std::endl;
            exit(EXIT_FAILURE);
        }

        node->set_data(value);
        // node->set_next(nullptr);

        if (tail == nullptr) {
            tail = node;
            head = node;
        } else {
            tail->set_next(node);
            tail = node;
        }
    }

    template <typename T>
    void SList<T>::pop_back() {
        if (this->empty()) {
            std::cerr << "ERROR using croman_library::SList<T>::pop_back();"
            " cannot remove element from empty list" << std::endl;
            exit(EXIT_FAILURE);
        }

        if (tail == head) {
            tail = nullptr;
            delete head;
            head = nullptr;
        } else {
            Node<T>* node = head;
            while (node->get_next()->get_next() != nullptr) {
                node = node->get_next();
            }

            tail = node;
            delete node->get_next();
            node->set_next(nullptr);
        }
    }

    template <typename T>
    const T& SList<T>::back() const {
        if (this->empty()) {
            std::cerr << "ERROR using croman_library::SList<T>::back();"
            " cannot read element from empty list" << std::endl;
            exit(EXIT_FAILURE);
        }
        return tail->get_data();
    }

    template <typename T>
    const T& SList<T>::value_at(int index) const {
        if ((index < 0) || (index >= this->size())) {   // slightly inefficient as it preemptively loops thru list, but clean to read
            std::cerr << "ERROR using croman_library::SList<T>::insert_after();"
            " index out of bounds" << std::endl;
            exit(EXIT_FAILURE);
        }

        size_t current{0};
        Node<T>* node = head;
        while(current != index) {
            node = node->get_next();
            ++current;
        }
        return node->get_data();
    }

    template <typename T>
    void SList<T>::insert_after(int index, const T& value) {
        if ((index < 0) || (index >= this->size())) {   // slightly inefficient as it preemptively loops thru list, but clean to read
            std::cerr << "ERROR using croman_library::SList<T>::insert_after();"
            " index out of bounds" << std::endl;
            exit(EXIT_FAILURE);
        }

        size_t current{0};
        Node<T>* node = head;
        while(current != index) {
            node = node->get_next();
            ++current;
        }

        auto new_node = new Node<T>;
        if (new_node == nullptr) {
            std::cerr << "ERROR using croman_library::SList<T>::insert_after();"
            " memory allocation failure" << std::endl;
            exit(EXIT_FAILURE);
        }
        new_node->set_data(value);
        new_node->set_next(node->get_next());
        node->set_next(new_node);

        if (tail == node)
            tail = new_node;
    }

    template <typename T>
    void SList<T>::erase_after(int index) {
        if ((index < 0) || (index >= (this->size() - 1))) { // slightly inefficient as it preemptively loops thru list, but clean to read
            std::cerr << "ERROR using croman_library::SList<T>::erase();"
            " index out of bounds" << std::endl;
            exit(EXIT_FAILURE);
        }

        size_t current{0};
        Node<T>* node = head;
        while(current != index) {
            node = node->get_next();
            ++current;
        }
        Node<T>* temp = node->get_next();
        node->set_next(node->get_next()->get_next());
        delete temp;
        temp = nullptr;
    }

    template <typename T>
    void SList<T>::print() const {
        if (this->empty()) {
            std::cerr << "ERROR using croman_library::SList<T>::print();"
            " cannot print contents of empty list" << std::endl;
            exit(EXIT_FAILURE);
        }
        Node<T>* node = head;
        while (node != nullptr) {
            std::cout << node->get_data() << " --> ";
            node = node->get_next();
        }
        std::cout << std::endl;
    }

} // namespace croman_library