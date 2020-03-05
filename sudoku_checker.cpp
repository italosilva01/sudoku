#include <iostream>
#include <algorithm>
#include <sstream>

#define EMPTY short(0)
#define SIZE 9

void print( short b[SIZE][SIZE] )
{
    int contColum,contLine;/*as variáveis contColum e contline 
                            contam a quantidade de elementos que
                            printados.*/
    contColum = 0;
    contLine = 0;

   for(int line = 0; line< SIZE; line++){
       //for para linhas
       ++contLine;
       for(int column = 0;column<SIZE;column++){
           //for para colunas 

           std::cout<< b[line][column]<<" ";
            contColum++; 
                
            if(contColum == 3){
                //só executa quando três elementos foram printados
                std::cout <<" ";
                contColum = 0;
            }
       }
       //quebrar a linha, delimitando a matriz
       std::cout<<std::endl;
    if(contLine==3){
        //quebra uma linha quando tiver printado uma tabela inteira.
        std::cout<<std::endl;
        contLine = 0;
    }
       
   }
}

bool check_row(int row,short v[SIZE][SIZE])
{
    //This function check the row of vector
    
    int aux[10]{0,0,0,0,0,0,0,0,0,0};
    //vector auxiliary

    for(int column = 0;column < SIZE; column++ ){
    //This 'for' moving on in the array line
        if(v[row][column]== 0){
            //checks the value in the vector and marks the auxiliary vector
            aux[0] += 1;
        }else if(v[row][column]==1){
            aux[1] += 1;
        }else if(v[row][column]==2){
            aux[2] += 1;
        }else if(v[row][column]==3){
            aux[3] += 1;
        }else if(v[row][column]==4){
            aux[4] += 1;
        }else if(v[row][column]==5){
            aux[5] += 1;
        }else if(v[row][column]==6){
            aux[6] += 1;
        }else if(v[row][column]==7){
            aux[7] += 1;
        }else if(v[row][column]==8){
            aux[8] += 1;
        }
        else if(v[row][column]==9){
            aux[9] += 1;
        }

        


    };
    
    for(int pos = 0; pos < SIZE; pos++){
        //check if any element is greater than 1
        if(aux[pos]>1){
            return false;
        }
    }
    return true;
}
bool check_column(int column, short v[SIZE][SIZE]){
    int aux[10]{0,0,0,0,0,0,0,0,0,0};

    for( int row = 0; row<SIZE; ++row){
        
        if(v[row][column]== 0){
            aux[0]+=1;
        }else if(v[row][column] == 1){
            aux[1]+=1;
        }else if(v[row][column] == 2){
            aux[2]+=1;
        }else if(v[row][column] == 3){
            aux[3]+=1;
        }else if(v[row][column] == 4){
            aux[4]+=1;
        }else if(v[row][column] == 5){
            aux[5]+=1;
        }else if(v[row][column] == 6){
            aux[6]+=1;
        }else if(v[row][column] == 7){
            aux[7]+=1;
        }else if(v[row][column] == 8){
            aux[8]+=1;
        }else if(v[row][column] == 9){
            aux[9]+=1;
        }


    }

    for(int pos = 0; pos < SIZE; ++pos){
        if(aux[pos] >1){
            return false;
        }
    }
    return true;
}

bool check_quadrant(short v[SIZE][SIZE]){
    int aux[10]{0,0,0,0,0,0,0,0,0,0};

    for(int rowQuadrant = 0; rowQuadrant< SIZE; rowQuadrant+=3){
        for(int columnQuadrant = 0; columnQuadrant < SIZE; columnQuadrant +=3){

            for(int row = rowQuadrant; row<rowQuadrant+3; ++row){
                for(int column = columnQuadrant; column < columnQuadrant+3; ++column){
                    
                    switch (v[row][column])
                    {
                    case 0: aux[0]+=1; break;
                    case 1: aux[1]+=1;break;
                    case 2: aux[2]+=1;break;
                    case 3: aux[3]+=1;break;
                    case 4: aux[4]+=1;break;
                    case 5: aux[5]+=1;break;
                    case 6: aux[6]+=1;break;
                    case 7: aux[7]+=1;break;
                    case 8: aux[8]+=1;break;
                    case 9: aux[9]+=1;break;
                    }

                }
                std::cout<<std::endl;
            }

            for(int pos = 0;pos<10;++pos){
              
                if(aux[pos]>1){
                    return false;
                }
                
            };
            for(int pos = 0; pos < 10;++pos){
                aux[pos]=0;
            }
            
        }
    }
    return true;
}
bool is_valid( short b[SIZE][SIZE] )
{
    // TODO: implement this function.
    //check line
    for(int row = 0; row<SIZE; ++row){
        if(check_row(row,b)==false){
            return false;
        }
    }
    //check column
    for(int column = 0; column<SIZE; ++column){
        if(check_column(column,b)==false){
            return false;
        }
    }
   if(check_quadrant(b)!= true){
       return false;
   } 
    return true; // This is just a stub. Replace it as needed.
}


int main(void)
{
    short board1[SIZE][SIZE]={
        { 1, 3, 4, 6, 7, 8, 5, 9, 2 },
        { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
        { 5, 9, 8, 3, 4, 2, 1, 6, 7 },
        { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
        { 4, 2, 6, 8, 5, 3, 9, 7, 1 },
        { 7, 1, 3, 4, 2, 9, 8, 5, 6 },
        { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
        { 2, 8, 7, 9, 1, 4, 6, 3, 5 },
        { 3, 4, 5, 2, 8, 6, 7, 1, 9 } };

    short board2[SIZE][SIZE]={
        { 1, 6, 2, 8, 5, 7, 4, 9, 3 },
        { 5, 3, 4, 1, 2, 9, 6, 7, 8 },
        { 7, 8, 9, 6, 4, 3, 5, 2, 1 },
        { 4, 7, 5, 3, 1, 2, 9, 8, 6 },
        { 9, 1, 3, 5, 8, 6, 7, 4, 2 },
        { 6, 2, 8, 7, 9, 4, 1, 3, 5 },
        { 3, 5, 6, 4, 7, 8, 2, 1, 9 },
        { 2, 4, 1, 9, 3, 5, 8, 6, 7 },
        { 8, 9, 7, 2, 6, 1, 3, 5, 4 } };

    short board3[SIZE][SIZE]={
        { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
        { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
        { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
        { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
        { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
        { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
        { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
        { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
        { 3, 4, 5, 2, 8, 6, 1, 7, 9 } };

    short board4[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };


    // Problem
    short board5[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 5, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 3, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board6[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 19, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, -3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board7[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 0, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board8[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 3, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 6, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    

    std::cout << "Board: \n";
    print( board1 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board1 ) << std::endl;
    std::cout << "\n";

    std::cout << "Board: \n";
    print( board2 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board2 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board3 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board3 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board4 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board4 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board5 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board5 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board6 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board6 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board7 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board7 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board8 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board8 ) << std::endl;
    std::cout << "\n";

    /* TODO: Make the code below work, instead of the ugly code above.

    int n_boards{8}; // Number of boards...
    for ( int i{0}; i < n_boards ; ++i )
    {
        std::cout << "Board #" << (i+1) << ": \n";
        print( boards[i] );
        std::cout << "Is valid? " << std::boolalpha << is_valid( board[i] ) << std::endl;
        std::cout << "\n";
    }

    */

    return 0;
}