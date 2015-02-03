#include <stdexcept>


template<class T, int N>
class Matrix {

private:
	T** _matrix;

public:
	Matrix(): _matrix(new Matrix[N][N]) {}
	Matrix(Matrix& matrix): _matrix(new Matrix[N][N]) {
		// perform deep copy -> memcpy
	}
	Matrix& operator=(Matrix& matrix) {
		// delete old contents, deep copy matrix
	}
	~Matrix() {
		// delete everything
	}

	void randomInit() {
		// init random values into matrix
	}
	T& operator()(int row, int col) throw(std::out_of_range) {
		if(row >= N || col >= N)
			throw std::out_of_range("Requested coordinates out of the matrix.");
		else
			return _matrix[row][col];
	}

};