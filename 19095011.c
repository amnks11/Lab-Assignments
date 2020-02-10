#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct a{
    int n;
    int top1,top2;
    int *array;
};
float Mean(int a[], int n) 
{ 
    int sum = 0; 
    for (int i = 0; i < n; i++)  
        sum += a[i]; 
      
    return (float)sum/(float)n; 
} 
struct a* init(int n){
    struct a* s;
    s=malloc(sizeof(struct a));
    s->n=n;
    s->array = (int*) malloc(n*sizeof(int));
    s->top1=-1;
    s->top2=n;
    return s;
    }
void sort(int *array , int n)
{ 
    // declare some local variables
    int i=0 , j=0 , temp=0;

    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n-1 ; j++)
        {
            if(array[j]>array[j+1])
            {
                temp        = array[j];
                array[j]    = array[j+1];
                array[j+1]  = temp;
            }
        }
    }

    
}
float Median(int array[] , int n)
{
    float median=0;
    
    
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    
    else
        median = array[n/2];
    
    return median;
}

void push(struct a* st,int stack,int element){
    if (stack==1){
        st->top1++;
        st->array[st->top1]=element;
        
    }
    else if(stack==2){
        st->top2--;
        st->array[st->top2]=element;
        
}}
float SD(int data[],int n,float mean) {
    float sum = 0.0, SD = 0.0;
    int i;
    for (i = 0; i < n; ++i) {
        sum += data[i];
    }
    
    for (i = 0; i < n; ++i)
        SD += pow(data[i] - mean, 2);
    return sqrt(SD / n);
}
void pop(struct a* st,int stack){
    if (stack==1){
        
        st->top1--;
    }
    else if(stack==2){
        st->top2++;
}
}
int Mode(int a[], int k) 
{ 
    int x[k]; 
  
    int max=0;
    for (int c = 1; c < k; c++)
  {
    if (a[c] > max)
    {
       max  = a[c];
    }
  }
  
    int y = max + 1; 
    int count[y]; 
    for (int i = 0; i < y; i++) 
        count[i] = 0; 
  
    for (int i = 0; i < k; i++) 
        count[a[i]]++; 
 
    int mode = 0; 
    int w = count[0]; 
    for (int i = 1; i < y; i++) { 
        if (count[i] > w) { 
            w = count[i]; 
            mode = i; 
        } 
    } 
    return mode;
  
   
} 
int main() {
    int n;
    int op;
    int k;
    int b;
    int c;
    int count=0;
    
    scanf("%d%d",&n,&op);
    struct a* st=init(n);
    int z[op];
    
    for(;op>0;op--){
        scanf("%d%d%d",&k,&b,&c);
        if (k==1){
            push(st,b,c);
            z[count]=c;
            count++;
        }
        else if(k==2){
            pop(st,b);
        }
        
    }
    float mean=Mean(z,count);
    printf("%f ",mean);
    sort(z,count);
    float median=Median(z,count);
    printf("%f ",median);
    int mode=Mode(z,count);
    printf("%d ",mode);
    float std=SD(z,count,mean);
    printf("%f\n",std);
    
    for(int i=st->top1;i>=0;i--){
        printf("%d ",st->array[i]);
    }
    printf("\n");
    for(int i=n-1;i>st->top2-1;i--){
        printf("%d ",st->array[i]);
    }
    
	
}
