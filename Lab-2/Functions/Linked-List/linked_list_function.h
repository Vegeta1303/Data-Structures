struct Node 
{
    int data;
    int id;
    struct Node * link;
};

struct Employee
{
    int id;
    char name[10];
    char expense_type[10];
    int expense;
    struct Employee * link;
};

int count_items_in_linked_list(struct Node *);
void print_linked_list_data(struct Node * head);
void print_linked_list_id(struct Node * head);
void add_element_at_end(struct Node * head , int new_data , int id);
void add_element_at_beg(struct Node * head , int data);
void delete_last_in_element_linked_list(struct Node * head);
struct Node * reverse(struct Node * head);
void detect_loop(struct Node * head);
int get_expense_by_type(struct Employee * head);
int get_expense_by_id(struct Employee * head);
struct Employee * bubble_sort(struct Employee * head);
struct Employee * swap(struct Employee * head , int pos1 , int pos2);