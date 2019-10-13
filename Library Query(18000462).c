#include<stdio.h>
int main(){

    int i,n, testCases ,t,q, query, q_type, x, y, k, j, l, temp;

     //Getting No. of Test Cases as an Input
    printf("Enter the Number of Test Cases:");
    scanf("%d",&testCases);

    //Loop to run No. of test cases
    for(t=0; t<testCases ; t++) {

        //Getting Total No. of Shelves in the Library as an Input
        printf("Enter the Number of Shelves in the Library(N):");
        scanf("%d", &n);

        int shelves[n];

        //Getting Number of books to a particular shelf as Inputs
        printf("Enter the No. of books in each %d Shelves respectively:", n);
        for(i=0;i<n; i++){
        scanf("%d", &shelves[i]); //Stores values to represent no. of books in a particular shelf
        }

        //Getting Number of Queries as an Input
        printf("Enter the Number of Queries(Q):");

        scanf("%d",&query);

        for(q=0 ; q<query ; q++ ) {
              //q_type(query type),x(Lower Bound shelf),y(Upper bound shelf),k(Rank of the shelf after sorting) - given input values respectively (eg : "1 x y" format or "0 x y k" format)
            printf("Enter the values in the format (0 x y k ) or (1 x k):");
            scanf("%d",&q_type);

            if(q_type == 1) {

			      //first query type(Update Query)

                  scanf("%d %d",&x, &k );

                  if(1<=x && x<=n){
                  shelves[x-1] = k;      //x-th shelf's index is x-1
                  }
                  else{
                  	printf("Invalid Input!!!!! \n");
				  }
            }
		    else if(q_type == 0){

			      //second query type(Search Query)

                  scanf("%d %d %d",&x, &y, &k);

                  //l= length of the new array
                  l= (y-x+1);
                  int array[l];
                       if(1<=x && x<=y && y<=n && 1<=k && k<=l){
                            x--;
                            y--;
                            for(i=0;i<=y; i++){
                                    if(x<=y){
                                     array[i]= shelves[x];
                                     x++;
                                    }
		      	        	}


				        //sorting Process to arrange array elements in ascending order



                              for (i= 0; i < l; i++){

                                 for (j=0; j<l; j++) {
                                     if (array[i] < array[j]){

                                       temp =  array[i];
                                       array[i] = array[j];
                                       array[j] = temp;
                                     }

                                 }

                              }

                              for(i=0; i<50; i++){
			                	printf("-");
		                      }
                              printf("\n");

                          //Displaying the number of books in a shelf of kth rank between given range of shelves

		                 	printf("***Output***Number of books in the shelf rank %d = %d  \n", k, array[k-1]);
		                	for(i=0; i<50; i++){
		            		printf("-");
		                 	}
                            printf("\n");

                        }
            else{
                printf("Invalid User Inputs!!!! \n");
            }

           }
		   else {
            	printf("Invalid User Input!!!!! \n");
	    	}

		}
    }

    return 0;
}




