// StructTuto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}
struct Books{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};
struct Course{
   struct	Books books;
	char Name[50];
	int course_id;
};

int main()
{
	
	

	struct Books Book1;
	
	strcpy(Book1.title,"C Programming");
	strcpy(Book1.author,"Nuha Ali");
	strcpy(Book1.subject,"C Programming Tutorial");
	Book1.book_id=1;

	printf("Book 1 title: %s\n",Book1.title);
	printf("Book 1 author:%s\n",Book1.author);
	printf("Book 1 subject:%s\n",Book1.subject);
	printf("Book 1 book_id:%d\n",Book1.book_id);

	
	
	
	struct Course course;
	for(int i=1;i<=2;i++)
	{
		course.course_id=i;
		printf(" Course id %d \n",i);
		printf("Course Name:");
		scanf("%s",course.Name);

		printf("Enter  Books Title:");
		scanf("%s",&course.books.title);
	}

	
	return 0;
}
