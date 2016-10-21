typedef struct song_node;

struct song_node * insert_front(char *a, char *n, struct song_node *S);

struct song_node * insert_song(char *a, char *n, struct song_node *S);

void print_list(struct song_node *S);

struct song_node * find_song_name(char *n, struct song_node *S);

struct song_node * find_song_artist(char *a, struct song_node *S);

int listlength(struct song_node *S);

struct song_node * random(struct song_node *S);

struct song_node * remove_node(int i, struct song_node *S);

struct song_node * free_list(struct node *S);

struct song_node * add_song(char *a, char *n);

struct song_node * find_song(char *n);

struct song_node * find_artist(char *a);

void print_letter(char l);

void print_artist(char *a);

void print_library();

void shuffle();

struct song_node * delete_song(char *n);

void delete_all();