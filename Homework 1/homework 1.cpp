//
//  homework 1.cpp
//  Hw 1
//  Net ID : Cah835
//  Created by Corey Henry on 6/20/15.
//  Copyright (c) 2015 Corey Henry. All rights reserved.
//

#include <stdio.h>

#include <stdio.h>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

// create function to add
void matrix_add(float matrix[3][3])
{
    float matrix_add[3][3];// create a new matrix for them to add numbers to add too.
    for (int i=0; i<3 ; i++)
    {
        cout << "Enter the Numbers in order you wish to add to first row to add. ";//loop to create first row
        cin >> matrix_add[0][i];
    }
    for(int i=0; i<3; i++)
    {
        cout << "Enter the Numbers in order you wish to add to second row to add. ";// loop to create second row
        cin >> matrix_add[1][i];
    }
    for(int i=0; i<3; i++)
    {
        cout << "Enter the Numbers in order you wish to add to third row to add. ";// loop to create third row
        cin >> matrix_add[2][i];
    }
    for(int i=0; i<3; i++)// adds the first row of the matrix
    {
        matrix[0][i] += matrix_add[0][i];
    }
    for(int i=0; i<3; i++)// adds the second row of the matrix
    {
        matrix[1][i] += matrix_add[1][i];
    }
    for(int i=0; i<3; i++)// adds the third row of the matrix
    {
        matrix[2][i] += matrix_add[2][i];
    }
    
}
// create function to sub
void matrix_sub(float matrix[3][3])
{
    int matrix_sub[3][3];// creates the matrix they will use to subtract
    for (int i=0; i<3 ; i++)
    {
        cout << "Enter the Numbers in order you wish to add to first row to subtract. ";//loop to create first row
        cin >> matrix_sub[0][i];
    }
    for(int i=0; i<3; i++)
    {
        cout << "Enter the Numbers in order you wish to add to second row to subtract. ";// loop to create second row
        cin >> matrix_sub[1][i];
    }
    for(int i=0; i<3; i++)
    {
        cout << "Enter the Numbers in order you wish to add to third row to subtract. ";// loop to create third row
        cin >> matrix_sub[2][i];
    }
    for(int i=0; i<3; i++)// subtracts the first row of the matrix
    {
        matrix[0][i] -= matrix_sub[0][i];
    }
    for(int i=0; i<3; i++)// subtracts the second row of the matrix
    {
        matrix[1][i] -= matrix_sub[1][i];
    }
    for(int i=0; i<3; i++)// subtracts the third row of the matrix
    {
        matrix[2][i] -= matrix_sub[2][i];
    }
    
    
}

// create function to multiply
void matrix_mult(float matrix[3][3])
{
    int matrix_mult[3][3];// creates matrix they will use to multiply
    for (int i=0; i<3 ; i++)
    {
        cout << "Enter the Numbers in order you wish to add to first row to multiply. ";//loop to create first row
        cin >> matrix_mult[0][i];
    }
    for(int i=0; i<3; i++)
    {
        cout << "Enter the Numbers in order you wish to add to second row to multiply. ";// loop to create second row
        cin >> matrix_mult[1][i];
    }
    for(int i=0; i<3; i++)
    {
        cout << "Enter the Numbers in order you wish to add to third row to multiply. ";// loop to create third row
        cin >> matrix_mult[2][i];
    }
    for(int i=0; i<3; i++)// multiplys the first row of the matrix
    {
        matrix[0][i] *= matrix_mult[0][i];
    }
    for(int i=0; i<3; i++)// multiplys the second row of the matrix
    {
        matrix[1][i] *= matrix_mult[1][i];
    }
    for(int i=0; i<3; i++)// multiplys the third row of the matrix
    {
        matrix[2][i] *= matrix_mult[2][i];
    }
}


// create function to scalar
void matrix_sca(float matrix[3][3])
{
    int number;
    cout << "what number would you like to use for scalar?";
    cin >> number;
    for(int i=0; i<3; i++)// adds the first row of the matrix
    {
        matrix[0][i] *= number;
    }
    for(int i=0; i<3; i++)// adds the second row of the matrix
    {
        matrix[1][i] *= number;
    }
    for(int i=0; i<3; i++)// adds the third row of the matrix
    {
        matrix[2][i] *= number;
    }
}


/// main function
int main()
{
    float matrix[3][3];// creates the initial matrix
    for (int i=0; i<3 ; i++)
    {
        cout << "Enter the Numbers in order you wish to add to the first row. ";//loop to create first row
        cin >> matrix[0][i];
    }
    for(int i=0; i<3; i++)
    {
        cout << "Enter the Numbers in order you wish to add to the second row. ";// loop to create second row
        cin >> matrix[1][i];
    }
    for(int i=0; i<3; i++)
    {
        cout << "Enter the Numbers in order you wish to add to the third row. ";// loop to create third row
        cin >> matrix[2][i];
    }
    
    // display options and input choice to corosponding function
    while(true)
    {
        cout << "Option 1: add matrices"<< endl;
        cout << "Option 2: sub matrices"<< endl;
        cout << "Option 3: multiply matrices"<< endl;
        cout << "Option 4: scalar matrices"<< endl;
        cout << "Option 5: exit" << endl;
        cout << "what option would you like to do?" << endl;
        int option; // create variable for function
        cin >> option;
        if(option == 1)
        {
            matrix_add(matrix);
        }
        
        if(option == 2)
        {
            matrix_sub(matrix);
        }
        
        if(option == 3)
        {
            matrix_mult(matrix);
        }
        if(option == 4)
        {
            matrix_sca(matrix);
        }
        if(option == 5)// exits the while loop
        return false;
        
        /////
        cout << "[";// print the matrix first row
        for(int i= 0; i < 3; i++)
        {
            cout << "[" << matrix[0][i]<< "]";
            
        }
        cout << "]" << endl;
        
        
        /////
        cout << "[";// print the matrix second row
        for(int i= 0; i < 3; i++)
        {
            cout << "[" << matrix[1][i]<< "]";
            
        }
        cout << "]" << endl;
        
        ////
        cout << "[";// print the matrix third row
        for(int i= 0; i < 3; i++)
        {
            cout << "[" << matrix[2][i]<< "]";
            
        }
        cout << "]" << endl;
        
        
        
        
        
        
        
    }// ends the while loop
    
    
    return 0;
    
    
}

