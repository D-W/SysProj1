#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"

//-------------------------------------------------------
typedef struct song_node{ 
    char artist[256];
    char name[256];
    struct song_node *next;
} song_node;

//SORT BY ARTIST
//linkedlist functions
struct song_node * insert_front(char *a, char *n, struct song_node *S) {
    struct song_node *s = (struct song_node *)malloc(sizeof(struct song_node));
    s->artist = a;
    s->name = n;
    s->next = S;
    return s;
}

struct song_node * insert_song(char *a, char *n, struct song_node *S) {
    struct song_node *s = (struct song_node *)malloc(sizeof(struct song_node));
    s->artist = a;
    s->name = n;
    while (strcmp(S->artist,s->artist) < 0  && S->next) {
        S = S->next;
    }
    while(strcmp(S->name,s->name) < 0 && S->next) {
        S = S->next;
    }
    s->next = S->next;
    S->next = s;
    return s;
}

void print_list(struct song_node *S) {
    while (S) {
        printf("%s - %s, ", S->artist, S->name);
        S = S->next;
    }
    printf("\n");
}

struct song_node * find_song_name(char *n, struct song_node *S) {
    while(S) {
        if(S->name == n) {
            return S;
        }
        S = S->next;
    }
    printf("song not found");
    return 0;
}

struct song_node * find_song_artist(char *a, struct song_node *S) {
    while(S) {
        if(S->artist == a) {
            return S;
        }
        S = S->next;
    }
    printf("artist not found");
    return 0;
}

int listlength(struct song_node *S) {
    int i = 0;
    while(S) {
        i++;
        S = S->next;
    }
    return 0;
}

struct song_node * random(struct song_node *S) {
    int i = rand() % listlength(S);
    while(i) {
        S = S->next;
        i--;
    }
    return S;
}

struct song_node * remove_node(int i, struct song_node *S) {
    struct song_node *s = (struct song_node *)malloc(sizeof(struct song_node));
    if(i == 0) {
        s = S;
        S = S->next;
        return s;
    }
    while (i > 0) {
        S = S->next;
        i--;
    }
    s = S->next;
    S->next = S->next->next;
    return s;
}

struct song_node * free_list(struct node *S) {
    struct song_node *s = S;
    while (S) {
        S = S->next;
        free(s);
        s = S;
    }
    return S;
}
//-------------------------------------------------------
song_node * table[26];

//array of linked list functions
struct song_node * add_song(char *a, char *n) {
    int letter = a[0] - 97;
    if (table[letter] == 0) {
        table[letter] = (struct song_node *)malloc(sizeof(struct song_node));
        table[letter]->artist = a;
        table[letter]->name = n;
        return table[letter];
    }
    else {
        return insert_song(a, n , table[letter]);
    }
}

struct song_node * find_song(char *n) {
    int i = 0;
    while(i<26) {
        if(table[i]) {
            if(find_song_name(n, table[i])) {
                return find_song_name(n, table[i]);
            }
        }
        i++;
    }
    printf("song not found");
    return 0;
}

struct song_node * find_artist(char *a) {
    int letter = a[0]-97;
    if (table[letter]) {
        return find_song_artist(a, table[letter]);
    }
    printf("artist not found");
    return 0;
}

void print_letter(char l) {
    print_list(table[l-97]);
}

void print_artist(char *a) {
    int letter = a[0] - 97;
    struct song_node *s = table[letter];
    while(s) {
        if(s->artist == a) {
            printf("%s - %s, ", s->artist, s->name);
        }
        s = s->next;
    }
    printf("\n");
}

void print_library() {
    int i = 0;
    while (i<26) {
        print_list(i);
        i++;
    }
}

void shuffle() {
    int ctr = 3;
    while (ctr){
        int letter = rand() % 25;
        if(table[letter]) {
            struct song_node *s = random(table[letter]);
            printf("%s - %s, ", s->artist, s->name);
            i--;
        }
    }
}

struct song_node * delete_song(char *n) {
    struct song_node *findartist = find_song(n);
    int letter = ((findartist->artist)[0]) - 97;
    struct song_node *s = table[letter];
    int pos = 0;
    while (s) {
        if(s->name == n) {
            return remove_node(i, table[letter]);
        }
        s = s->next;
        pos++;
    }
    printf("song not found");
    return 0;
}

void delete_all() {
    int i = 0;
    while(i<26) {
        free(table[i]);
        i++;
    }
}


int main() {    
    
    //imagine dragons - radioactive
    //marianas trench - desperate measures, mystery skulls - soul on fire, mystery skulls - the future
    //the cab - stand up, thirty seconds to mars - this is war
    
    return 0;
    
}