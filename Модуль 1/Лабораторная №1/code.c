#include <stdio.h>
#include <math.h>

#define lmax 200




int main() {
  printf("Лабораторная работа №1\n");
  printf("Пырлицану Никита Евгеньевич\nГруппа: БИВ239\nВариант: 473 (5, 6, 4)\n");
  printf("Задание 1\nВведите длину массива R от 1 до %d\n", lmax);

  int n = 0;
  do
    scanf("%d", &n);
  while (n < 1 || n > lmax);
  
  printf("Введите x, h, a:\n");

  float x, h, a;

  scanf("%f %f %f", &x, &h, &a);

  float r[lmax];

  for (int i = 1; i<=n; i++) {
    r[i-1] = cos(i*h)-cos(a*x+i*h);
  }

  printf("Массив R из %d элементов\n", n);
  
  for (int i = 0; i<n; i++) {
    printf("%f; ", r[i]);
  }
  printf("\n");

  // Task 2
  
  printf("Задание 2\n");

  int np = -1;
  for (int i = 0; i<n; i++) {
    if (r[i] < 0) {
      np = i;
    }
  }

  int k = n;

  if (np < 1) {
    if (np == -1) { printf("Нет отрицательного элемента\n"); }
    if (np == 0) { printf("Нет промежутка для удаления\n"); }
  }
  else {
    k = -1;
    
    for (int i=0; i<np+1; i++) {
      if (r[i] <= 0) {
        k++;
        r[k] = r[i];
      }
    }

    for (int i=np+1; i < n; i++) {
      k++;
      r[k] = r[i];
    }
    
    printf("Массив состоит из %d элементов\n", k+1);
    for (int i=0; i < k+1; i++) {
      printf("%f; ", r[i]);
    }
    printf("\n");

    k++;
  }

  // Task 3
  
  printf("Задание 3\n");

  if (k<3) {
    printf("Нет среднего значения\n");
    return 0;
  }

  float fmax = fabsf(r[0]);
  int n1 = 0;

  float fmin = fabsf(r[0]);
  int n2 = 0;

  for (int i = 0; i < k; i++) {
    if (fabsf(r[i]) > fmax) {
      fmax = fabsf(r[i]);
      n1 = i;
    }

    if (fabsf(r[i]) < fmin) {
      fmin = fabsf(r[i]);
      n2 = i;
    }
  }

  int l = n1 < n2 ? n1 : n2;
  int rh = n1 + n2 - l;
  if (rh-l-1 <= 0) {
    printf("Нет среднего значения");
  }
  else {
    float sum = 0;
    for (int i=l+1; i<rh; i++) {
      sum += r[i];
    }
    float sr = sum / (rh-l-1);
    printf("sr = %f", sr);
  }


  return 0;
}
