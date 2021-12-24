#ifndef felipeserna
#define felipeserna

#include <stdio.h>
#include <stdlib.h>

/* Mandatory function */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

/* Auxiliary functions */
int full_match(char const *s, char const **words, int nb_words, int word_len);
int not_in(int *arr, int len, int l);
int str_match(char const *str, char const *word);

#endif
