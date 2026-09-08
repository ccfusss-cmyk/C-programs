#include <stdio.h>
#include <stdlib.h>
struct Node {
 int coeff;
 int exp;
 struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->coeff = coeff;
 newNode->exp = exp;
 newNode->next = NULL;
 return newNode;
}
struct Node* insertEnd(struct Node* head, int coeff, int exp) {
 struct Node* newNode = createNode(coeff, exp);
 if (head == NULL) {
 head = newNode;
 } else {
 struct Node* temp = head;
 while (temp->next != NULL)
 temp = temp->next;
 temp->next = newNode;
 }
 return head;
}
void display(struct Node* head) {
 if (head == NULL) {
 printf("NULL\n");
 return;
 }
 while (head != NULL) {
 printf("%dx^%d", head->coeff, head->exp);
 head = head->next;
 if (head != NULL && head->coeff >= 0)
 printf(" + ");
 }
 printf("\n");
}
struct Node* addTerm(struct Node* result, int coeff, int exp) {
 struct Node* temp = result;
 struct Node* prev = NULL;
 while (temp != NULL) {
 if (temp->exp == exp) {
 temp->coeff += coeff;
 return result;
 }
 prev = temp;
 temp = temp->next;
 }
 
struct Node* newNode = createNode(coeff, exp);
 if (prev == NULL)
 result = newNode;
 else
 prev->next = newNode;
 return result;
}
struct Node* multiply(struct Node* poly1, struct Node* poly2) {
 struct Node* result = NULL;
 struct Node* ptr1 = poly1;
 struct Node* ptr2 = poly2;
 while (ptr1 != NULL) {
 ptr2 = poly2;
 while (ptr2 != NULL) {
 int coeff = ptr1->coeff * ptr2->coeff;
 int exp = ptr1->exp + ptr2->exp;
 result = addTerm(result, coeff, exp);
 ptr2 = ptr2->next;
 }
 ptr1 = ptr1->next;
 }
 return result;
}
int main() {
 struct Node* poly1 = NULL;
 struct Node* poly2 = NULL;
 struct Node* result = NULL;
 int n, coeff, exp, i;
 printf("Enter number of terms in first polynomial: ");
 scanf("%d", &n);
 printf("Enter coeff and exp for each term:\n");
 for (i = 0; i < n; i++) {
 scanf("%d%d", &coeff, &exp);
 poly1 = insertEnd(poly1, coeff, exp);
 }
 printf("Enter number of terms in second polynomial: ");
 scanf("%d", &n);
 printf("Enter coeff and exp for each term:\n");
 for (i = 0; i < n; i++) {
 scanf("%d%d", &coeff, &exp);
 poly2 = insertEnd(poly2, coeff, exp);
 }
 printf("\nFirst Polynomial: ");
 display(poly1);
 printf("Second Polynomial: ");
 display(poly2);
 result = multiply(poly1, poly2);
 printf("\nResultant Polynomial after Multiplication: ");
display(result);
 return 0;
}
