struct Circular
{
    int data;
    struct Circular * next;
};

void add_end_circular(struct Circular * head , int data);
void print_circular(struct Circular * start);
struct Circular * add_beg_circular(struct Circular * head , int data);
struct Circular * add_random_circular(struct Circular * head , int data , int pos);
struct Circular * delete_last_circular(struct Circular * head);
struct Circular * delete_random_circular(struct Circular * head , int pos);
struct Circular * delete_element_circular(struct Circular * head);