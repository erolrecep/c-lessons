// A linked list node.
struct node {
  int data;
  struct node* next;
};

// A linked list.
struct linked_list {
  struct node* head;
  struct node* tail;
};

// Create a new linked list.
struct linked_list* linked_list_create() {
  struct linked_list* list = malloc(sizeof(struct linked_list));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

// Add a node to the end of the linked list.
void linked_list_add_node(struct linked_list* list, int data) {
  struct node* new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

// Remove a node from the end of the linked list.
void linked_list_remove_node(struct linked_list* list) {
  struct node* prev_node = NULL;
  struct node* current_node = list->head;

  while (current_node != NULL) {
    prev_node = current_node;
    current_node = current_node->next;
  }

  if (prev_node == NULL) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    prev_node->next = NULL;
    list->tail = prev_node;
  }
}

// Free the linked list.
void linked_list_free(struct linked_list* list) {
  struct node* current_node = list->head;
  struct node* next_node = NULL;

  while (current_node != NULL) {
    next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }

  free(list);
}
