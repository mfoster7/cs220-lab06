#include <stdio.h>

void bad()
{
	char *newname = "Quick brown fox jumped over the lazy dog";
	unsigned char *temp;
	temp = (unsigned char *) (&newname);
	temp += 0x20;
	*((char **)temp) = newname;
	temp += 8;
	*((int *)temp) = 1000;
	temp -= 0x10;
	*((unsigned long *)temp) += 0x1b;
}

int main()
{
	struct{
		char *name;
		int age;
	} student = {.name = "John", .age = 22 };

	bad();

	printf("student.name = %s\nstudent.age = %d\n", student.name, student.age);
	return 0;
}
