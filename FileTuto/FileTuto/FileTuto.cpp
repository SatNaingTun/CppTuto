// FileTuto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
int area();
int ReadArea();
int main()
{
	//ReadArea();
	area();
	return 0;
}

int area()
{
	FILE *fout=NULL;
	fout=fopen("fout.txt","w");

	if(fout==NULL)
	{
		printf("fout.txt cannot open \n");
		return 1;
	}
	float r=0.0;
	float a=0.0;
	char key;
	printf("please enter r:");
	scanf("%f",&r);
	a=3.14*r*r;
	printf("the area is %f",a );

	fprintf(fout,"%f",a );
	if(fout!=NULL)
	fclose(fout);
	
}

int ReadArea()
{
	FILE *fin=NULL;
	fin=fopen("fout.txt","r");//w a r


	if(fin==NULL)
	{
		printf("fout.txt cannot open \n");
		return 1;
	}
	float r=0.0;
	float a=0.0;
	char key;
	//printf("please enter r:");
  int ret=	fscanf(fin,"%f",&r);
	if(ret>0)
	{
	
	a=3.14*r*r;
	printf("the area is %f",a );

	fprintf(fin,"the area is %f",a );
	}

	if(fin!=NULL)
	fclose(fin);

}
