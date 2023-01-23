#include<bits/stdc++.h>
using namespace  std;
struct node
{   int so;
    char data[100];
	struct node *leftnode;
	struct node *rightnode;
};
struct chu
{  int tanso;
   char	tu[100];
   char alphabet[100];
} al[10000];
struct node *root=NULL;
void insert(char data[],int c)
{
 struct node *temp = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   temp->data[0]='\0';
  for (int i=0;i<strlen(data);i++)
   temp->data[i] = data[i];
    temp->data[strlen(data)]='\0';
	temp->leftnode=NULL;
	temp->rightnode=NULL;
	temp->so=c;
	if (root==NULL)
	root=temp;
	else 
	{
		current=root;
		parent=NULL;
		while (2)
		{
			parent=current;
		    if(strcmp(data,current->data)<0) {
            current = current->leftnode;                

            
            if(current == NULL) {
               parent->leftnode = temp;
               break;
            }
         }
         else {
            current = current->rightnode;

           
            if(current == NULL) {
               parent->rightnode = temp;
               break;
		}	 
	}
}
}}
FILE *fp;
int k=1;
void LNR(struct node *root )
{   
    
	if (root!=NULL)
	{   
		LNR(root->leftnode);
		fprintf(fp,"%d.%s",k++,root->data);
		fseek(fp,-strlen(root->data),SEEK_END);
		fseek(fp,15,1);
		fprintf(fp,"%d\n\n",root->so);
		LNR(root->rightnode);
	}
}
int main()
{  FILE *ptr;
   int count=0,i=0,dem;
    char c;
   	ptr=fopen("myfile.txt","rb");
   	fflush(stdin);
   	if (ptr==NULL)
   	{
   	   perror("tep bi loi trong qua trinh mo");
	   exit(1);	
	}
	  
	while ((c=fgetc(ptr))!=EOF)
	{   
	    if (isalpha(c))
		{dem=i;al[i].tu[count]=c;count++;al[i].tu[count]='\0';}
	   else
		{
		if (strlen(al[i].tu)!=0)
 		 { 
		  i++;
 		  count=0;
		 }
		}
	}
  fflush(ptr);
int h=-1;
for (int j=0;j<=dem;j++)
{
	if (al[j].tu[0]!='\0')
{   h++;al[h].tanso=1;al[h].alphabet[0]='\0';
  for (int l=0;l<strlen(al[j].tu);l++)
  al[h].alphabet[l]=al[j].tu[l];
    al[h].alphabet[strlen(al[j].tu)]='\0';
    for (int k=j+1;k<=dem;k++)
	{ 
	   if (strcmp(al[j].tu,al[k].tu)==0) {al[h].tanso++;al[k].tu[0]='\0';}}}}
	   if (h<100)
	   for (int z=0;z<=h;z++) insert(al[z].alphabet,al[z].tanso);
	   else
	   {
	   	for (int z=0;z<=99;z++) insert(al[z].alphabet,al[z].tanso);
	   }
   fp=fopen("PBL1.txt","wb");
   if (fp==NULL)
   {
   	printf("ko the mo tep\n");
   	perror("ly do");
   	exit(1);
   }
   fprintf(fp,"BANG TAN SO CAC TU TRONG TEXT\nTu");
   fseek(fp,-2,SEEK_END);
	fseek(fp,15,1);
	fputs("Tan suat\n",fp);
   LNR(root);
    return 0;
}
