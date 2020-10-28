#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct range_node{
  int low;
  int hi;
  struct range_node* next;
}rect_range_node;

typedef struct twoDNode
{
  int size_value;
  struct twoDNode* next;
}twoDNode;

typedef struct threeDNode
{
  int twoDSizes;
  struct twoDNode* threeDSizes;
  struct threeDNode* next;
}threeDNode;

typedef union
{
  twoDNode* head_2d;
  threeDNode* head_3d;
}range2;

typedef struct{
char* typeExp_type;
int dimensions;
int range1[2];
char* basicElementType;
range2 r2; //tagged with dimensions r2 is union type
}JaggedArrayTypeExp; //variant record tag: dimensions

typedef struct{
  char* typeExp_type;
  int dimensions;
  rect_range_node* head; //populate on fly all the dimension into a LinkedList
  char* basicElementType;//fixed
}RectArrayTypeExp; //fixed

typedef struct{
  char* basicElementType;
}PrimitiveTypeExp;

typedef union
{
  PrimitiveTypeExp p;
  RectArrayTypeExp r;
  JaggedArrayTypeExp j;
}typeExpression;

// typedef struct typeExpressionTableNode{
//   char* variable_name;
//   enum type{primitive,rectangular,jagged} t;
//   enum isStatic{dyn,static_var,not_applicable} stat;
//   typeExpression* te;
//   // struct typeExpressionTableNode* next;//tagged with type
// }typeExpressionTableNode; //variant record tag: type

typedef struct{
  char* variable_name;
  enum {primitive,rectangular,jagged} t;
  enum {dyn,static_var,not_applicable} stat;
  typeExpression* te; //tagged with type
}typeExpressionTableEntry;

typedef struct typeExpressionTable
{
	typeExpressionTableEntry** entries;
	int size;
} typeExpressionTable;


void TypeExpressionToString(typeExpressionTableEntry* node)
{
  if(node->t==primitive)
  {
    char* type1=(node->te)->p.basicElementType;
    printf("<type=%s>",type1);
  }
  else if(node->t==rectangular)
  {
    //<type=rectangularArray, dimensions=2, range_R1= (2, 5), range_R2 = (3, 6), basicElementType = integer>
    printf("<");
    printf("type=rectangularArray, ");
    printf("dimensions=%d, ",(node->te)->r.dimensions);
    int count=1;
    rect_range_node* root=((node->te)->r).head;
    while(root!=NULL)
    {
      printf("range_R%d=(%d,%d), ",count++,root->low,root->hi);
      root=root->next;
    }
    printf("basicElementType=%s",(node->te)->r.basicElementType);
    printf(">");
  }
  else
  {
    printf("<");
    printf("type=jaggedArray, ");
    printf("dimensions=%d, ",(node->te)->j.dimensions);
    printf("range_R1=(%d,%d), ",(node->te)->j.range1[0],(node->te)->j.range1[1]);
    //
    if((node->te)->j.dimensions==2)
    {
      //<type =jaggedArray, dimensions=2, range_R1=(3, 8), range_R2 = (3, 6, 2, 4, 1, 5), basicElementType = integer>
      printf("range_R2=(");
      twoDNode* root=(node->te)->j.r2.head_2d;
      while(root && root->next)
      {
        printf("%d, ",root->size_value);
        root=root->next;
      }
      printf("%d",root->size_value);
      printf("), ");
    }
    else
    {
      //range_R2 = (3 [ 5, 3, 5] , 2 [ 3, 5], 3 [ 5, 4, 3] ,4 [ 2, 5,4, 4] ), basicElementType = integer>
      printf("range_R2=(");
      threeDNode* root=(node->te)->j.r2.head_3d;
      // int twoDSizes;
      // struct twoDNode* threeDSizes;
      // struct threeDNode* next;
      while(root && root->next)
      {
        printf("%d",root->twoDSizes);
        twoDNode* root2=root->threeDSizes;
        printf("[");
        while(root2 && root2->next)
        {
          printf("%d,",root2->size_value);
          root2=root2->next;
        }
        printf("%d",root2->size_value);
        printf("],");
        root=root->next;
      }
      printf("%d",root->twoDSizes);
      twoDNode* root2=root->threeDSizes;
      printf("[");
      while(root2 && root2->next)
      {
        printf("%d,",root2->size_value);
        root2=root2->next;
      }
      printf("%d",root2->size_value);
      printf("] ");
      printf("), ");
    }
    printf("basicElementType=%s",(node->te)->j.basicElementType);
    printf(">");
}
}

void printTypeExpressionTable(typeExpressionTable T)
{
  for(int i=0;i<T.size;i++)
  {
      typeExpressionTableEntry* tet=T.entries[i];
      printf("Variable Name:%s\t\t",tet->variable_name);
      if(tet->t==primitive)
      {
        printf("Type: primitive");
      }
      else if(tet->t==rectangular)
      {
        printf("Type: Rectangular Array");
      }
      else
      {
        printf("Type: Jagged Array");
      }
      printf("\t\t");
      if(tet->stat==dyn)
      {
        printf("isStatic: Dynamic");
      }
      else if(tet->stat==static_var)
      {
        printf("isStatic: Static");
      }
      else
      {
        printf("%30s","isStatic: Not_Applicable");
      }
      printf("\t\t");
      TypeExpressionToString(tet);
      printf("\n");
  }
}

int main()
{
  typeExpressionTable* T=(typeExpressionTable*)malloc(sizeof(typeExpressionTable));
  T->entries=(typeExpressionTableEntry**)calloc(1,sizeof(typeExpressionTableEntry*));
  T->entries[0]=(typeExpressionTableEntry*)malloc(sizeof(typeExpressionTableEntry));
  // T->entries[1]=(typeExpressionTableEntry*)malloc(sizeof(typeExpressionTableEntry));
  T->entries[0]->variable_name=(char*)malloc(2*sizeof(char));
  strcpy(T->entries[0]->variable_name,"x");
  T->size=1;
  T->entries[0]->t=jagged;
  T->entries[0]->stat=static_var;
  T->entries[0]->te=(typeExpression*)malloc(sizeof(typeExpression));
  T->entries[0]->te->j.typeExp_type=(char*)malloc(8*sizeof(char));
  strcpy(T->entries[0]->te->j.typeExp_type,"JaggedArray");
  T->entries[0]->te->j.dimensions=3;
  T->entries[0]->te->j.range1[0]=0;
  T->entries[0]->te->j.range1[1]=1;
  T->entries[0]->te->j.r2.head_3d=(threeDNode*)malloc(sizeof(threeDNode));
  threeDNode* head=T->entries[0]->te->j.r2.head_3d;
  head->next=(threeDNode*)malloc(sizeof(threeDNode));
  head->twoDSizes=2;
  (head->next)->twoDSizes=2;
  while(head)
  {
    head->threeDSizes=(twoDNode*)malloc(sizeof(twoDNode));
    twoDNode* head2=head->threeDSizes;
    head2->size_value=1;
    head2->next=(twoDNode*)malloc(sizeof(twoDNode));
    (head2->next)->size_value=1;
    while(head2)
    {
      head2=head2->next;
    }
    head=head->next;
  }
  //[1[],2[,]]
  T->entries[0]->te->r.basicElementType=(char*)malloc(8*sizeof(char));
  strcpy(T->entries[0]->te->r.basicElementType,"Integer");
  printTypeExpressionTable(*T);
  // T->entries[1]
  return 0;
}
// T->entries[0]->variable_name=(char*)malloc(2*sizeof(char));
// strcpy(T->entries[0]->variable_name,"x");
// T->entries[0]->t=rectangular;
// T->entries[0]->stat=static_var;
// T->entries[0]->te=(typeExpression*)malloc(sizeof(typeExpression));
// T->entries[0]->te->r.typeExp_type=(char*)malloc(8*sizeof(char));
// strcpy(T->entries[0]->te->r.typeExp_type,"RectArray");
// T->entries[0]->te->r.dimensions=2;
// T->entries[0]->te->r.head=(rect_range_node*)malloc(sizeof(rect_range_node));
// rect_range_node* head=T->entries[0]->te->r.head;
// head->next=(rect_range_node*)malloc(sizeof(rect_range_node));
// int i=0;
// while(head)
// {
//   head->low=i++;
//   head->hi=i++;
//   head=head->next;
// }
// T->entries[0]->te->r.basicElementType=(char*)malloc(8*sizeof(char));
// strcpy(T->entries[0]->te->r.basicElementType,"Integer");
