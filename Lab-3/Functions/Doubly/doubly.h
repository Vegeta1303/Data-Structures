struct Doubly
{
    int data;
    struct Doubly * next;
    struct Doubly * prev;
};

struct Doubly * add_end_doubly(struct Doubly * head , int data);
void print_doubly(struct Doubly * head);
void backward_print_doubly(struct Doubly * head);
struct Doubly * add_beg_doubly(struct Doubly * head , int data);
void add_random_doubly(struct Doubly * head , int data , int pos);
struct Doubly * delete_element_doubly(struct Doubly * head);
void delete_last_doubly(struct Doubly * head);
struct Doubly * delete_random_doubly(struct Doubly * head , int pos);