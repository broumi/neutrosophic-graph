#include<stdio.h>
#include<conio.h>
#define max 100
typedef struct {
float Truth_membership,Indterminate_membership,False_membership;
}fuzzy;
fuzzy 
element[max][max],compliment[max][max];//element store the membership value of vertex.Compliment store the value of complimented graph.
int vertex;//store total number of vertex.
float vertex_membership[max][6];//store membership va-lue of vertex.
void input()
{
int i,origin,destiny;//origin & destiny store the no. of ver-tex.And i for iteration.
	printf("Please enter no of vertex:");
	scanf("%d",&vertex);
	for(i=0;i<vertex;i++)
	{
	printf("Please enter (T,I,F)menbership values of vertex:");
	scanf("%f%f%f",&vertex_membership[i][0],&vertex_membership[i][1],&vertex_membership[i][2]);//store the membership value of vertex		if(vertex_membership[i][0]+vertex_membership[i][1]+vertex_membership[i][2]>=3&&(vertex_membership[i][0]<=3&&vertex_membership[i][1]&&vertex_membership[i][2]))
	{
	printf("Error Invalid input\n");
	i--;
	}
	}
	for(i=0;i<vertex*(vertex-1)/2;i++)
	{
	printf("Please enter the edges (x to y):");
	scanf("%d%d",&origin,&destiny);
		if(origin>vertex||destiny>vertex||origin<=0||destiny<=0||destiny==origin)
	{
                  printf("Error! Invalid input\n");	
		    i--;
	}
		else
	{
	printf("Please enter (T,I,F)membership values of edge:");
scanf("%f%f%f",&element[origin-1][destiny-1].Truth_membership,&element[origin-1][destiny-1].Indterminate_membership,&element[origin-1][destiny-1].False_membership);//store th membership value of ed-ge.
                        
element[destiny-1][origin-1].Truth_membership=element[origin-1][destiny-1].Truth_membership;//store the truth-membership value of edge.
element[destiny-1][origin-1].Indterminate_membership=element[origin-1][destiny-1].Indterminate_membership;//store the indterminate-membership value of edge.
element[destiny-1][origin-1].False_membership=element[origin-1][destiny-1].False_membership;//store the False-membership value of edge.
if(element[origin-1][destiny-1].Truth_membership+element[origin-1][destiny-1].Indterminate_membership+element[origin-1][destiny-1].False_membership>3)//store the membership value of edge.
{
printf("Error! Invalid input\n");
i--;
}
}
}
	
}
void output()
{
	int i,j;
	float maximum,minimum,maximuma;
	printf("The complement of Single valued neutro-sophic graphs is:\n");
	for(i=0;i<vertex;i++)
{
	for(j=0;j<vertex;j++)
{
	if(i==j)
	j++;
if(vertex_membership[i][0]>vertex_membership[j][0])
minimum=vertex_membership[j][0];//find minimum value between two vertex.
else
minimum=vertex_membership[i][0];//find minimum value between two vertex.
if(vertex_membership[i][1]>vertex_membership[j][1])
maximum=vertex_membership[i][1];//find maximum va-lue between two vertex.
else
maximum=vertex_membership[j][1];//find maximum va-lue between two vertex.
if(vertex_membership[i][2]>vertex_membership[j][2])
maximuma=vertex_membership[i][2];//find maximum value between two vertex.
else
maximuma=vertex_membership[j][2];//find maximum value between two vertex.
compliment[i][j].Truth_membership=minimum-element[i][j].Truth_membership;//calculating compliment.
compliment[i][j].Indterminate_membership=maximum-element[i][j].Indterminate_membership;//calculating compliment.
compliment[i][j].False_membership=maximuma-element[i][j].False_membership;//calculating compliment.
}
 }
	for(i=0;i<vertex-1;i++)
{
	for(j=0;j<vertex;j++)
{
	if(i==j)
 j++;
printf("%d - %d edge membership value= %f %f %f \n",i+1,j+1,compliment[i][j].Truth_membership,compliment[i][j].Indterminate_membership,compliment[i][j].False_membership);//printing complimented graph.	
}
}
}
int main()
{
	input();
	output();
	getch();
                  }

