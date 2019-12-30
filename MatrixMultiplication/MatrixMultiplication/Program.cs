using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MatrixMultiplication
{
    class Program
    {
        static void Main(string[] args)
        {
            // тут вводим параметры матрицы по примеру
            float[,] matrix1 = { {2,-1,7},
                                 {9,1,6} };
            float[,] matrix2 = { {1,2,4,3},
                                 { -1,7,1,2},
                                 {0,5,1,2} };

            float[,] endMatrix = multiplyMatrixes(matrix1, matrix2);
            //Console.WriteLine(endMatrix.GetLength(0) + " " + endMatrix.GetLength(1));
            printMatrix(endMatrix);
        }

        static void printMatrix(float[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                    Console.Write(matrix[i, j] + " ");

                Console.WriteLine();
            }
        }


        static float[,] multiplyMatrixes(float[,] matrix1, float[,] matrix2)
        {
            float[,] endMatrix = new float[matrix1.GetLength(0), matrix2.GetLength(1)];
            // Console.WriteLine(matrix1.Length);
            if (matrix1.GetLength(1) != matrix2.GetLength(0))
                Console.WriteLine("Wrong Matrix!!! \n");
            else
            {
                for (int i = 0; i < endMatrix.GetLength(0); i++)
                    for (int j = 0; j < endMatrix.GetLength(1); j++)
                        endMatrix[i, j] = 0f;

                for (int i = 0; i < matrix1.GetLength(0); i++)
                    for (int j = 0; j < matrix2.GetLength(1); j++)
                        for (int n = 0; n < matrix1.GetLength(1); n++)
                            endMatrix[i, j] += matrix1[i, n] * matrix2[n, j];
            }
            return endMatrix;
        }
    }
}

