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

  for (int i = 0; i<n; i++) {
    r[i] = cos(i*h)-cos(a*x+i*h);
  }

  printf("Массив R из %d элементов\n", n);
  
  for (int i = 0; i<n; i++) {
    printf("%f; ", r[i]);
  }
  printf("\n");

  // Task 2
  
  printf("Задание 2\n");

  int np = -1;
  int k = n;

  for (int i=0; i<n && np == -1; i++) {
    if (r[i] > 0) {
      np = i;
    }
  }

  if (np == -1) {
    printf("Нет положительного элемента\n");
  }

  else {
    k = np+1;
    for (int i=0; i<k; i++) {
      printf("%f; ", r[i]);
    }
    printf("\n");
  }
  
  // Task 3
  //
  

  
  printf("Задание 3\n");
  
  if (k == 1) {
    printf("Нет среднего значения");
    return 0;
  }
  
  float fmax = 0;
  float n1 = -1;

  for (int i=0; i<k; i++) {
    if (r[i] >= fmax) {
      fmax = r[i];
      n1 = i;
    }
  }
  
  if (n1 == -1) {
    printf("Нет среднего");
    return 0;
  }

  float sum = 0;
  int co = 0;

  for (int i=n1+1; i<k; i++) {
    if (r[i] < 0) {
      sum += r[i];
      co++;
    }
  }

  if (co == 0) {
    printf("Нет отрицательных элементов");
    return 0;
  }

  printf("sr = %f", sum/co);

  return 0;
}
