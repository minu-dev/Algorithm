#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define POKEMON_LENGTH 21

typedef struct Pokemon {
  char name[POKEMON_LENGTH];
  int idx;
} Pokemon;

int static compare(const void *first, const void *second) {
  Pokemon *a = (Pokemon *)first;
  Pokemon *b = (Pokemon *)second;
  if (strcmp(a->name, b->name) > 0)
    return 1;
  else if (strcmp(a->name, b->name) < 0)
    return -1;
  else
    return 0;
}

int binarySearch(Pokemon *pokemon, int size, char *target) {
  int low, mid, high;
  low = 0;
  high = size - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (strcmp(pokemon[mid].name, target) == 0)
      return pokemon[mid].idx;
    else if (strcmp(pokemon[mid].name, target) < 0)
      low = mid + 1;
    else if (strcmp(pokemon[mid].name, target) > 0)
      high = mid - 1;
  }
  return -1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Pokemon *pokemon = (Pokemon *)malloc(sizeof(Pokemon) * n);
  Pokemon *pokemonSorted = (Pokemon *)malloc(sizeof(Pokemon) * n);
  for (int i = 0; i < n; i++) {
    scanf("%s", pokemon[i].name);
    sprintf(pokemonSorted[i].name, "%s", pokemon[i].name);
    pokemon[i].idx = pokemonSorted[i].idx = i + 1;
  }
  qsort(pokemonSorted, n, sizeof(Pokemon), compare);
  for (int i = 0; i < m; i++) {
    char question[POKEMON_LENGTH];
    scanf("%s", question);
    if (atoi(question) == 0)
      printf("%d\n", binarySearch(pokemonSorted, n, question));
    else
      printf("%s\n", pokemon[atoi(question) - 1].name);
  }

  free(pokemon);
  free(pokemonSorted);

  return 0;
}