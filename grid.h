//-------------------------------------------------
// TODO:  Write file header.
// Grid.h
// Author: Ashton Edakkunnathu
// Course: CS 211 - Programming Practicuum
// DATE: 11/19/2023
//-------------------------------------------------

//-------------------------------------------------
// TODO:  Update the member function comments in 
//        your own style.
//-------------------------------------------------

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct ROW {
    T*  Cols;     // array of column elements
    size_t NumCols;  // total # of columns (0..NumCols-1)
  };

  ROW* Rows;     // array of ROWs
  size_t  NumRows;  // total # of rows (0..NumRows-1)

public:
  //
  // default constructor:
  //
  // Called automatically by to construct a 4x4 Grid. 
  // All elements initialized to default value of T.
  //
  Grid() {
    Rows = new ROW[4];  //4 rows
    NumRows = 4;

    //each row has 4 columns:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r].Cols = new T[4];
      Rows[r].NumCols = 4;

      //initialize the elements to default
      for (size_t c = 0; c < Rows[r].NumCols; ++c) {
        Rows[r].Cols[c] = T();  //default value for template
      }
    }
  }

  //
  // parameterized constructor:
  //
  // Called automatically to construct a Grid 
  // with R rows, where each row has C columns. 
  // All elements initialized to default value of T.
  //
  Grid(size_t R, size_t C) {
    //-------------------------------------------------
    // TODO:  Write this parameterized constructor.
    //-------------------------------------------------
    Rows = new ROW[R];  //Initialize the Rows array for R ROWs.
    NumRows = R;

    //go through each row in the grid.
    for (size_t r = 0; r < NumRows; ++r) {
        // For each row, create a array of type T, the columns
        Rows[r].Cols = new T[C];  //Initialize the  array with space for C columns.
        Rows[r].NumCols = C;      //Set the numCols for this row to C.

        for (size_t c = 0; c < Rows[r].NumCols; ++c) {
            Rows[r].Cols[c] = T();  //Default value for type T.
        }
    }

  }

  //
  // destructor:
  //
  // Called automatically to free memory for this Grid.
  //
  virtual ~Grid() {
      //-------------------------------------------------
      // TODO:  Write this destructor.
      //-------------------------------------------------
    //go through each row in the grid.
    for (size_t r = 0; r < NumRows; ++r) {
        delete[] Rows[r].Cols;  //delet the colun arrays for each row.
    }
    delete[] Rows;  //Delete the dynamic row array.

  }


  //
  // copy constructor:
  //
  // Called automatically to construct a Grid that contains a
  // copy of an existing Grid.  Example: this occurs when passing
  // Grid as a parameter by value
  //
  //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
  //   { ... }
  //
  Grid(const Grid<T>& other) {

      //-------------------------------------------------
      // TODO:  Write this copy constructor.
      //-------------------------------------------------
    Rows = new ROW[other.NumRows];  //Initialize the Rows array with the same number of rows as 'other'
    NumRows = other.NumRows;        //Set the total number of rows to match 'other'

    //go through each row in the 'other' grid.
    for (size_t r = 0; r < other.NumRows; ++r) {
        size_t other_numcols = other.Rows[r].NumCols;

        Rows[r].Cols = new T[other_numcols];  // Initialize the dynamic array with the same number of columns as 'other'
        Rows[r].NumCols = other_numcols;      // Set the totla number of columns for this row to match 'other'

        for (size_t c = 0; c < other_numcols; ++c) {
            Rows[r].Cols[c] = other.Rows[r].Cols[c];  // Copy each elment from 'other' to the new
        }
    }

  }

  //
  // copy operator=
  //
  // Called when one Grid is assigned into another, i.e. this = other;
  //
  Grid& operator=(const Grid& other) {
      Grid<T> temp;

      //-------------------------------------------------
      // TODO:  Write this copy operator.
      //-------------------------------------------------

        //Check for self-assignment, if 'this' and 'other' are the same
        if (this == &other) {
            return *this;  //if 'this' and 'other' are the same, no need to copy, return the current object
        }

        // delete memory for the existing grid.
        for (size_t r = 0; r < NumRows; ++r) {
            delete[] Rows[r].Cols;  //Delete the dynamic column arrays for each row
        }
        delete[] Rows;  //Delete the dynamic row array

        this->Rows = new ROW[other.NumRows];  //Initialize the Rows array with the same number of rows as 'other'
        this->NumRows = other.NumRows;        //Set the total number of rows to match 'other'

        //go through each row in 'other'
        for (size_t r = 0; r < other.NumRows; ++r) {
            size_t other_numcols = other.Rows[r].NumCols;

            //For each row, create a array of type T columns in the new grid
            this->Rows[r].Cols = new T[other_numcols];  //create the dynamic array with the same number of columns as 'other'
            this->Rows[r].NumCols = other_numcols;      //set the totla number of columns for this row to match 'other'

            for (size_t c = 0; c < other_numcols; ++c) {
                this->Rows[r].Cols[c] = other.Rows[r].Cols[c];  //copy each element from 'other' to the new grid
            }
        }
        return *this;  //Return a reference to the object
  }

  //
  // numrows
  //
  // Returns the # of rows in the Grid.  
  // The indices for these rows are 0..numrows-1.
  //
  size_t numrows() const {

    //-------------------------------------------------
    // TODO:  Write this function.
    //-------------------------------------------------

    return NumRows;  // TODO:  update this, it is only here so code compiles.
  }


  //
  // numcols
  //
  // Returns the # of columns in row r.  
  // The indices for these columns are 0..numcols-1.  
  // For now, each row has the same number of columns.
  //
  size_t numcols(size_t r) const {

      //-------------------------------------------------
      // TODO:  Write this function.
      //-------------------------------------------------
      if (r >= NumRows) {
            throw out_of_range("Grid::numcols: Invalid row index");
      }
      return Rows[r].NumCols;

  }


  //
  // size
  //
  // Returns the total # of elements in the Grid.
  //
  size_t size() const {

      //-------------------------------------------------
      // TODO:  Write this function.
      //-------------------------------------------------
      size_t totalSize = 0;
      for (size_t r = 0; r < NumRows; ++r) {
          totalSize += Rows[r].NumCols;
      }
      return totalSize;
  }


  //
  // ()
  //
  // Returns a reference to the element at location (r, c);
  // this allows you to access or assign the element:
  //
  //    grid(r, c) = ...
  //    cout << grid(r, c) << endl;
  //
  T& operator()(size_t r, size_t c) {
      //T temp;


      //-------------------------------------------------
      // TODO:  Write the parentheses overloaded operator
      //-------------------------------------------------
      if (r >= NumRows || c >= Rows[r].NumCols) {
          throw out_of_range("Grid::operator(): Invalid row or column index");
      }
      return Rows[r].Cols[c];
  }

  //
  // _output
  //
  // Outputs the contents of the grid; for debugging purposes.  
  // This is not tested.
  //
  void _output() {

      //-------------------------------------------------
      // TODO:  Write this function.
      //-------------------------------------------------
      for (size_t r = 0; r < NumRows; ++r) {
        cout << "| ";
        for (size_t c = 0; c < Rows[r].NumCols; ++c) {
            cout << Rows[NumRows - r - 1].Cols[c] << " | ";
        }
        cout << endl;
    }


  }

};