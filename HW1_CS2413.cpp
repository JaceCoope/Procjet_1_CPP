#include <iostream>
using namespace std;

class CRM {
protected:
    int n; //The number rows of the original matrix
    int m; //The number of columns of the original matrix
    int nonZeros; //The number of non-zero elements in the original matrix
    int* values; //Array that contains all non-zero values of the matrix, assuming they are all integers
    int* rowPos; //Array that for each row of the original matrix contains the position in the values matrix in which the first non-zero element of this row is stored.
    int* colPos; //Array that contains the column number for each one of the non-zero values in the original matrix.
    //There may be others you may need
public:
    CRM ( ); //default or empty constructor
    CRM (int rows, int cols, int numNonZeros);
    int getNumRows ( );
    void addValue (int value); //add a new value in the values array
    void addRow (int row); //add a row number in the rowPos array
    void addColumn (int col);//add a column number in the colPos array
    void display (); //print the contents of the three arrays. Each array must be on a different line (separated by a
    //new line character) and you have exactly a single space between each value printed.
    int mostInfluentialUser(); //find the most influential user
    int mostActiveUser(); //find the most active user
    int* influentialUsers (); //compute vector of users ranked by how much influential they are
    int* activeUsers (); //compute vector of users ranked by how much active they are
    ~CRM(); //destructor
    //You may define and use any other method you need
};

int iterateNum; //global integer to keep track of values index
int rowStart = -1; //global integer to keep track of row input
int rowIterate = 0; //global integer to keep track of rows index


//some of the methods – Katia Papakonstantinopoulou
CRM::CRM ( ) {
    n = 0;
    m = 0;
    values = NULL;
    rowPos = NULL;
    colPos = NULL;
}
CRM::CRM (int rows, int cols, int numNonZeros) {
    n = rows;
    m = cols;
    nonZeros = numNonZeros;
    values = new int [nonZeros];
    rowPos = new int [n];
    colPos = new int [nonZeros];
}
void CRM::addValue(int value)
{
    values[iterateNum] = value;
}
void CRM::addRow(int row)
{
    if(row == rowStart)
    {
        //Do nothing
    }
    else
    {

        addRow(row);
    }
}
void CRM::addColumn(int col)
{

}
int CRM::mostInfluentialUser(){
    return 0;
};
int* CRM::influentialUsers (){
    int* outputVector = new int [n];

    for (int i=0; i < n; i++) outputVector[i] =0;

//fill in the code

    return outputVector;
}
CRM::~CRM ( ) {
    if (values != NULL) delete [ ] values;
    if (rowPos != NULL) delete [ ] rowPos;
    if (colPos != NULL) delete [ ] colPos;
    cout << "CRM Object Destroyed!!" << endl;
    n = 0;
    m = 0;
    nonZeros = 0;
}


#include <iostream>
using namespace std;

//write the entire CRM class here with all the methods

int main ( ) {

    CRM* A;
    int numRows, numColumns, numNonZeros;
    int row, col, value;

    //read in the first matrix
    cin >> numRows >> numColumns;
    cin >> numNonZeros;

    A = new CRM (numRows, numColumns, numNonZeros);
    for (int i=0; i < numRows; i++) {
        iterateNum = i;
        cin >> row >> col >> value;
        (*A).addValue (value);
        (*A).addRow (row);//needs to be done cleverly in the method
        (*A).addColumn (col);
    }
    (*A).display ( );

//Find most influential user
    int mostInf = (*A).mostInfluentialUser ();
    cout << "Most influential user: " << mostInf << endl;
    cout << endl;

//Find most active user
    int mostAct = 0;

    cout << "Most active user: " << mostAct << endl;
    cout << endl;

//Rank users based on how much influential they are
    int* influentialityVector = (*A).influentialUsers ();
    cout << "Users ranked by Influentiality: " << endl;
    for (int i=0; i < (*A).getNumRows ( ); i++)
        cout << influentialityVector [i] << " ";
    cout << endl << endl;

//Rank users based on how much active they are
//fill-in code
    cout << "Users ranked by Activity: " << endl;
    for (int i=0; i < (*A).getNumRows ( ); i++)
        cout << 0 << " ";
    cout << endl;

// Call the destructors
    delete A;
    delete [ ] influentialityVector;
    A->~CRM();

    return 0;
}
