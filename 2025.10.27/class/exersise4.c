//数组转置
#include <stdio.h>
#include <stdlib.h>
int main ( )
{
	int a[2][3]={2,3,4,5,1}, b[3][2]={0};
	int  i , j;

	printf("Output a[2][3]\n");
    for ( i = 0 ;  i < 2 ;  i ++ )
    {
		for ( j = 0 ;  j < 3 ;  j ++ )
            printf("%5d", a [ i ][ j ]) ;

        printf("\n");
    }


	printf("Output b[3][2]\n");
    for ( j = 0 ;  j < 3 ;  j ++ )
    {
		for ( i = 0 ;  i < 2 ;  i ++ )
	    {
	        // to do
	        printf("%5d", b[j][i]) ;
	    }
	   putchar('\n');
    }


/*
    int arr[N][N]; //={ 1,2,3,4,5,6,7,8,9};
    int i, j;
    //for(i=0 ; ; )   arr[i] = ?

	for ( i = 0 ;  i < N ;  i ++ )
    {
		for ( j = 0 ;  j < N ;  j ++ )
		{
				arr[j][i] = arr[i][j];
		}
	}

	printf("Output arr\n");
    for ( i = 0 ;  i < N ;  i ++ )
    {
		for ( j = 0 ;  j < N ;  j ++ )
			printf("%5d", arr[i][j]) ;
		putchar('\n');
	}
*/
	return 0;

}
