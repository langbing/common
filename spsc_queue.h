#pragma once

/* single-producer/single-consumer from intel */
template<typename T>
void store_release(T *addr, T v) {
    __memory_barrier();
    *const_cast<T volatile*>(addr) = v;
}

template<typename T>
T load_consume(T const* addr) {
    T v = *const_cast<T const volatile*>(addr);
    __memory_barrier();
    return v;
}

template<typename T>
class spsc_queue {
public:
 spsc_queue() {
     node *n = new node();
     n->next = nullptr;
     tail = head = first = tail_copy = node;
 }

 ~spsc_queue() {
     node *n = first;

     do {
        node *next = n->next;
        delete n;
        n = next;
     } while (n);
 }

 void enqueue(T v) {
     node *n = alloc_node();
     n->value = v;
     n->next = nullptr;
     store_release(&head->next, n);
     head = n;
 }

  bool dequeue(T &v) {
    if (!load_consume(&tail->next)) {
        return false;
    }

    v = tail->next->value;
    store_release(&tail, tail->next);
    return true;
 }

private:
 static constexpr size_t cache_line_size = 64;

 struct node {
     T value;
     node *next;
 };

 node* alloc_node() {
     if (first != tail_copy) {
         node *n = first;
         first = first->next;
         return n;
     }
     tail_copy = load_consume(&tail);
     if (first != tail_copy) {
         node *n = first;
         first = first->next;
         return n;
     }

     return new node();
 }

 node *tail;

 /* for false share */
 char cache_line_padding[cache_line_size];

 node *head;
 node *first;
 node *tail_copy;
};
