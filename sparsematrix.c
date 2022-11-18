 #include<stdio.h>

 
void read_mat_normal(int mat_normal[100][100],int r,int c)
{
    int i=0,j=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&mat_normal[i][j]);
        }
    }
}
void print_mat_normal(int mat_normal[100][100],int r,int c)
{
    int i=0,j=0;
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        {
            printf("%d  ",mat_normal[i][j]);
        }
    }
}

void conv_trans(int mat_normal[100][100],int r,int c)
{
    //Normal Form to Tuple Form Conversion
    int mat_tup[100][100];
    int i,j,cnz=0,tr=0,tc=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat_normal[i][j]!=0)
            {
                cnz++;
                mat_tup[cnz][0]=i;
                mat_tup[cnz][1]=j;
                mat_tup[cnz][2]=mat_normal[i][j];
            }
            
        }
    }
    mat_tup[0][0]=r;
    mat_tup[0][1]=c;
    mat_tup[0][2]=cnz;
    tr=cnz+1;
    tc=3;
    printf("\nrows columns values");
    for(i=0;i<tr;i++)
    {
        printf("\n");
        for(j=0;j<tc;j++)
        {
            printf("%d  ",mat_tup[i][j]);
        }
    }
    // Transpose
    int temp[100];
    
    for(i=0;i<tr;i++)
    {
        temp[i]=mat_tup[i][0];
    }
    for(i=0;i<tr;i++)
    {
        mat_tup[i][0]= mat_tup[i][1];
         mat_tup[i][1]=temp[i];
    }
    
    printf("\nThe Transpose is\n");
    for(i=0;i<tr;i++)
    {
        printf("\n");
        for(j=0;j<tc;j++)
        {
            mat_normal[i][j]=mat_tup[i][j];
            printf("%d  ",mat_tup[i][j]);
        }
    }
    
}
void sum(int mat1[100][100],int mat2[100][100])
{
    int tr1,tr2,n=0,mat[100][100],i,j,k;
    
    if((mat1[0][0]==mat2[0][0]) && (mat1[0][1]==mat2[0][1]))
    {
        
        tr1=mat1[0][2];
        tr2=mat2[0][2];
        i=1;
        j=1;
        k=1;
        n=tr1+tr2;
        while((i<=tr1) &&(j<=tr2))
        {
            if((mat1[i][0]==mat2[j][0]) &&(mat1[i][1]==mat2[j][1]))
            {
                mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2]+mat2[j][2];
                i++;j++;k++;
            }
            
               else if(mat1[i][0]<mat2[j][0])
                {
                    mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2];
                i++;k++;
                }
                else
                {
                     mat[k][0]=mat2[j][0];
                mat[k][1]=mat2[j][1];
                mat[k][2]=mat2[j][2];
                j++;k++;
                }
                       
                   }
        while(i<=tr1)
        {
           mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2];
                i++;k++; 
        }
        while(j<=tr2)
        {
             mat[k][0]=mat2[j][0];
                mat[k][1]=mat2[j][1];
                mat[k][2]=mat2[j][2];
                j++;k++;
        }
        mat[0][0]=mat1[0][0];
        mat[0][1]=mat1[0][1];
        mat[0][2]=k-1;
        printf("\nThe sum is:\n");
         for(i=0;i<k;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            
            printf("%d  ",mat[i][j]);
        }
    }
    }
    else
    {
        printf("The matrix is incompatible");
    }
}
void main()
{
    int mat1[100][100],r1,c1,mat2[100][100],r2,c2;
    printf("\nFirst matrix:");
    printf("\nEnter the no. of rows:");
    scanf("%d",&r1);
    printf("\nEnter the no. of columns:");
    scanf("%d",&c1);
    printf("Enter the elements\n");
    read_mat_normal(mat1,r1,c1);
    printf("\nSecond matrix:");
    printf("\nEnter the no. of rows:");
    scanf("%d",&r2);
    printf("\nEnter the no. of columns:");
    scanf("%d",&c2);
    printf("Enter the elements\n");
    read_mat_normal(mat2,r2,c2);
    printf("\nThe first matrix in normal form is:");
    print_mat_normal(mat1,r1,c1);
    printf("\nThe second matrix in normal form is:");
    print_mat_normal(mat2,r2,c2);
    printf("\nFirst Matrix in tuple form:\n");
    conv_trans(mat1,r1,c1);
    printf("\nSecond Matrix in tuple form:\n");
    conv_trans(mat2,r2,c2);
    printf("\nSum\n");
    sum(mat1,mat2);
 }

