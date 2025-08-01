#include <vector>

class Solution {
public:
    // This function generates the entire Pascal's Triangle up to a specified number of rows.
    vector<vector<int>> generate(int numRows) {
        // 'pascal' will be our final result, a vector of vectors (a 2D array)
        // to store all the rows of the triangle.
        vector<vector<int>> pascal;
        
        // Handle the edge case where numRows is 0 or negative.
        // In this case, we return an empty triangle.
        if (numRows <= 0) {
            return pascal;
        }

        // The main loop iterates to generate each row of the triangle.
        // 'i' represents the current row index (0-based).
        for (int i = 0; i < numRows; i++) {
            // Create a new vector for the current row.
            // A row at index 'i' has 'i+1' elements.
            vector<int> currentRow(i + 1);

            // The first and last elements of every row in Pascal's Triangle are always 1.
            currentRow[0] = 1;
            currentRow[i] = 1;

            // This inner loop calculates the values for the elements in between the first and last.
            // The loop runs from the second element (j=1) up to the second-to-last element (j=i-1).
            for (int j = 1; j < i; j++) {
                // The core logic of Pascal's Triangle:
                // An element at (i, j) is the sum of the two elements from the previous row (i-1)
                // that are directly above it: element at (i-1, j-1) and element at (i-1, j).
                currentRow[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
            
            // After the current row is fully constructed, add it to our main result.
            pascal.push_back(currentRow);
        }
        
        // Return the complete Pascal's Triangle.
        return pascal;
    }
};