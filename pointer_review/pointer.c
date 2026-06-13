// this is a review of pointers in C. It will cover the basics of pointers, how to use them.
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t my_strlen(const char* str) {
	assert(str);
	
	const char* end = str;

	while (*end) end++;

	return end - str;
}


void bubble_sort(int* arr, size_t sz) {

	for (size_t i = 0; i < sz; i++) {
		int flag = 0;

		for (size_t j = 0; j < sz - 1 - i; j++) {

			if (arr[j] > arr[j + 1]) {
				flag = 1;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}


int Add(int a, int b) {
	return a + b;
}

int Subtract(int a, int b) {
	return a - b;
}

int Multiply(int a, int b) {
	return a * b;
}

int Divide(int a, int b) {
	if (b == 0) {
		printf("Error: Division by zero\n");
		return 0;
	}
	return a / b;
}


void menu() {
	printf("Select an operation:\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("0. Exit\n");
}

int cmp_int(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

struct Student {
	char name[50];
	int age;
};



void Swap(void* a, void* b, size_t size) {
	char temp;
	char* p1 = (char*)a;
	char* p2 = (char*)b;

	while (size--) {
		temp = *p1;
		*p1++ = *p2;
		*p2++ = temp;
	}
}


void bubble_qsort(void* str, size_t num, size_t size, int(*cmp)(const void*, const void*)) {
	for (int i = 0; i < num; i++) {
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++) {
				if (cmp((char*)str + j * size, (char*)str + (j + 1) * size) > 0) {
				flag = 1;
				Swap((char*)str + j * size, (char*)str + (j + 1) * size, size);
				}
		}
		if (flag == 0) {
			break;
		}
	}
}



//the basic syntax for declaring a pointer is as follows:
int main() {
	//1. declare a variable of a certain type. In this case, we are declaring an integer variable called a and initializing it with the value 10.
	int a = 10;
	// to declare a pointer, we use the * operator. The * operator is used to declare a pointer variable. It is also used to dereference a pointer variable.
	int* pa = &a; // the & operator is used to get the address of a variable. In this case, we are getting the address of the variable a and storing it in the pointer variable pa.
	
	//2.these are the sizes of the pointer types. The size of a pointer type is the same regardless of the type it points to. This is because a pointer is just an address in memory, and the size of an address is the same regardless of the type it points to.
	size_t size1 = sizeof(int*);
	size_t size2 = sizeof(double*);
	size_t size3 = sizeof(char*);
	size_t size4 = sizeof(void*);
	printf("Size of int*: %zu\n", size1);
	printf("Size of double*: %zu\n", size2);
	printf("Size of char*: %zu\n", size3);
	printf("Size of void*: %zu\n", size4);
	

	//3. the difference between const int* and int* const is that const int* is a pointer to a constant integer, while int* const is a constant pointer to an integer. This means that with const int*, you cannot change the value of the integer that the pointer points to, but you can change the pointer itself to point to a different integer. With int* const, you can change the value of the integer that the pointer points to, but you cannot change the pointer itself to point to a different integer.
	int b = 20;
	const int* pb = &b; // pointer to a constant integer
	pb = &a;     // this is allowed, we can change the pointer to point to a different integer
	//*pb = 30;  // this is not allowed, we cannot change the value of the integer that the pointer points to
	int* const pc = &b; // constant pointer to an integer
	//pc = &a;   // this is not allowed, we cannot change the pointer to point to a different integer
	*pc = 30;    // this is allowed, we can change the value of the integer that the pointer points to


	//4. the operation of pointer arithmetic is based on the size of the type that the pointer points to. When we add an integer value to a pointer, we are actually adding that integer value multiplied by the size of the type that the pointer points to. For example, if we have a pointer to an integer and we add 1 to it, we are actually adding 1 * sizeof(int) to the pointer. This means that the pointer will point to the next integer in memory.
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = &arr[0]; // pointer to the first element of the array
	//there are two ways to access the elements of the array using the pointer. The first way is to use pointer arithmetic to access the elements of the array. The second way is to use the dereference operator to access the value of the current element that the pointer points to.
	for (int i = 0; i < 5; i++) {
		printf("%d ", *(ptr + i)); // dereference the pointer to get the value of the current element
	}

	printf("\n");

	for(int i = 0; i < 5; i++) {
		printf("%d ", *ptr); // dereference the pointer to get the value of the current element
		ptr++; // move the pointer to the next element in the array
	}

	//the operation of pointer subtraction is to subtract the addresses that the pointers point to. When we subtract two pointers, we are actually subtracting the addresses that they point to in memory. The result of the subtraction will give us the number of elements between the two pointers, based on the size of the type that the pointers point to.
	int* p1 = &arr[0];
	int* p2 = &arr[5];
	int size = p2 - p1; // this will give us the number of elements between the two pointers
	printf("\nNumber of elements between p1 and p2: %d\n", size);


	//to write the function strlen()
	char arr3[] = "abcdef";
	size_t size_arr3 = my_strlen(arr3);


	//the operation between a pointer and a pointer is to compare the addresses that the pointers point to. When we compare two pointers, we are comparing the addresses that they point to in memory. If the pointers point to the same address, then they are equal. If they point to different addresses, then they are not equal.
	int arr2[] = { 1, 2, 3, 4, 5 };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int* p3 = &arr2[0];
	int* p4 = &arr2[sz2];
	for(int i = 0; i < sz2; i++) {
		if (p3 < p4) {
			printf("%d ", *p3);
			p3++;
		}
	}
	printf("\n");



	//5.bubble sort using pointers
	int arr4[] = { 5, 2, 9, 1, 5 };
	int sz4 = sizeof(arr4) / sizeof(arr4[0]);
	for (int i = 0; i < sz4; i++) {
		printf("%d ", arr4[i]);
	}
	bubble_sort(arr4, sz4);
	printf("\nSorted array: ");
	for (int i = 0; i < sz4; i++) {
		printf("%d ", arr4[i]);
	}
	printf("\n");



	//6. char pointer and string literals. A string literal is a sequence of characters enclosed in double quotes. When we declare a char pointer and initialize it with a string literal, the pointer points to the first character of the string literal in memory. The string literal is stored in a read-only section of memory, so we cannot modify the characters of the string literal through the pointer.
	const char* str = "Hello, World!";
	printf("%c\n", *str);
	printf("%s\n", str);


	//7.function pointer to write a calculator that can perform addition, subtraction, multiplication, and division. A function pointer is a pointer that points to a function. We can use a function pointer to call a function indirectly through the pointer.
	int (*operation[])(int, int) = { 0, Add, Subtract, Multiply, Divide };
	int choice = 0;
	do {		
		menu();
		scanf("%d", &choice);
		if(choice >= 1 && choice <= 4) {
			int num1, num2;
			printf("Enter two numbers: ");
			scanf("%d %d", &num1, &num2);
			int result = operation[choice](num1, num2); // call the function through the function pointer
			printf("Result: %d\n", result);
		} else if (choice == 0) {
			printf("Exit...");
		}
		else {
			printf("Invalid choice. Please try again.\n");
		}
	} while (choice);



	//8.qsort using pointers. Quick sort is a sorting algorithm that uses the divide-and-conquer approach to sort an array. The basic idea of quick sort is to select a pivot element from the array and partition the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.
	struct Student s1 = {"Alice", 20};
	struct Student s2 = { "Bob", 22 };
	struct Student s3 = { "Charlie", 19 };
	
	struct Student students[] = { s1, s2, s3 };
	size_t num_students = sizeof(students) / sizeof(students[0]);
	qsort(students, num_students, sizeof(struct Student), cmp_int);
	printf("\nStudents sorted by age:\n");
	for (size_t i = 0; i < num_students; i++) {
		printf("Name: %s, Age: %d\n", students[i].name, students[i].age);
	}


	//9. bubble_sort rewreting to qsort. We can rewrite the bubble_sort function using qsort by defining a comparison function that compares two integers and then calling qsort with the array, the number of elements, the size of each element, and the comparison function.

	
	
	return 0;
}