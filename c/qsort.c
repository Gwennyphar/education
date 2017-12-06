#include <stdlib.h>
#include <stdio.h>

void quicksort(int *a, int left, int right) {

  /* Betrachtung des (Teil-)Arrays,
   * das mindestens zwei Elemente umfasst,
   * left und right sind die Grenzen des (Teil-)Arrays. */
  if (left < right) {

    int pivot = a[right]; // das rechte Grenzelement, Pivotelement!
    int l = left;
    int r = right;

    do {
      /* Den linken Index so weit nach rechts rücken (erhöhen),
       * solange das l-Element kleiner ist als das Pivotelement. */
      while (a[l] < pivot) l++;

      /* Den rechten Index so weit nach links rücken (verkleinern),
       * solange das r-Element größer ist als das Pivotelement. */
      while (a[r] > pivot) r--;

      /* Vertausche die aktuellen r- und l-Elemente und
       * erhöhe l und verringere r jeweils um 1,
       * falls l noch links von r (rechts) ist! */
      if (l <= r) {
          int swap = a[l];
          a[l] = a[r];
          a[r] = swap;
          l++;
          r--;
      }
    } while (l <= r); // bis sich l und r irgendwo in der Mitte treffen.

    quicksort(a, left, r);  // sortiere die linke Teilliste.
    quicksort(a, l, right); // sortiere die rechte Teilliste.
  }
}

// Kleiner Test: Lass quicken!
int main() {

  int values[] = {3, 9, 2, 0, 5, 18, 11, 4, 77, 16};
  int count = sizeof(values) / sizeof(*values);

  // Ausgabe der Werte (vorher)
  //for (int i = 0; i < count; i++) printf("%5d", values[i]);
  printf("\n");

  // Sortiere alle Elemente von 0 bis count-1!
  quicksort(values, 0, count - 1);

  // Ausgabe der Werte (nachher)
  //for (int i = 0; i < count; i++) printf("%5d", values[i]);
  printf("\n");

  getchar();
  return 0;
}
